//
// Created by LE, Duc Anh on 7/9/15.
//

#ifndef CLDEPLUS_APPTEST_RELATION_NAMEDENTITY02_HPP
#define CLDEPLUS_APPTEST_RELATION_NAMEDENTITY02_HPP

#include <gtest/gtest.h>

#include "../Application/CustomerMap.h"
#include "../Application/PreOrderMap.h"
#include "../Entity/Customer.h"
#include "../Entity/PreOrder.h"

#include "../../Source/Drivers/MySql/MySqlSourceDriver.h"
#include "../../Source/Drivers/SQLite/SQLiteSourceDriver.h"
#include "../../Source/Foundation/Data/ValueFactory.h"
#include "NumericToPrimative.hpp"

namespace CLDEPlus {
    namespace Test {
        namespace Store {

            TEST(Relation, NamedEntityReferencingSQLiteAndMySql) {

                auto sptrCustomerMap = CLDEPlus::cldeplus_make_shared<Application::CustomerMap>();
                auto sptrPreOrderMap = CLDEPlus::cldeplus_make_shared<Application::PreOrderMap>();
                auto sptrCustomerDriver = (Drivers::SQLite::SPtrSQLiteSourceDriver) Drivers::SQLite::SQLiteSourceDriver::CreateUnique(sptrCustomerMap);
                auto sptrPreOrderDriver = (Drivers::MySql::SPtrMySqlSourceDriver) Drivers::MySql::MySqlSourceDriver::CreateUnique(sptrPreOrderMap);

                sptrCustomerDriver->OptionArgs().ConnectionString = "example01.db";
                sptrPreOrderDriver->OptionArgs().Host = "dell-3020";
                sptrPreOrderDriver->OptionArgs().User = "cloud-e";
                sptrPreOrderDriver->OptionArgs().Pass = "cloud-e";
                sptrPreOrderDriver->OptionArgs().Base = "cloud-e";
                sptrPreOrderDriver->OptionArgs().Port = 3306;

                Relation::RelationMap relCustomerToPreOrder{};
                Relation::RelationMap relCustomerAddress{};
                Relation::RelationMap relPreOrderToCustomer{};

                relCustomerToPreOrder.AddLink(sptrCustomerMap->GetColumn("Id"), sptrPreOrderMap->GetColumn("CustId"));
                relCustomerAddress.AddLink(sptrCustomerMap->GetColumn("Id"), sptrCustomerMap->GetColumn("Id"));
                relPreOrderToCustomer.AddLink(sptrPreOrderMap->GetColumn("CustId"), sptrCustomerMap->GetColumn("Id"));

                auto sptrCustomerQuery = (Foundation::SPtrEntityQuery) Foundation::EntityQuery::CreateShared(sptrCustomerMap, sptrCustomerDriver);
                auto sptrPreOrderQuery = (Foundation::SPtrEntityQuery) Foundation::EntityQuery::CreateShared(sptrPreOrderMap, sptrPreOrderDriver);
                auto sptrCustomerStore = Relation::CreateNamedStore<Entity::Customer>(sptrCustomerMap, sptrCustomerDriver);
                auto sptrPreOrderStore = Relation::CreateNamedStore<Entity::PreOrder>(sptrPreOrderMap, sptrPreOrderDriver);

                sptrCustomerStore->EntityLoader().fptrNamedEntityCreator =
                        [&sptrCustomerMap, &sptrPreOrderMap,
                                &sptrPreOrderQuery, &sptrCustomerQuery,
                                &relCustomerToPreOrder, &relCustomerAddress]
                                (const Foundation::Entity &entity) -> Entity::Customer {

                            using namespace Foundation::Data;
                            using namespace Foundation::Query;

                            Entity::Customer customer{};
                            customer.setId(NumericToPrimative<int64_t>(entity.getCell("Id")->getValue()));
                            customer.setFirstName(entity.getCell("FirstName")->ToString());
                            customer.setLastName(entity.getCell("LastName")->ToString());
                            customer.setEmail(entity.getCell("Email")->ToString());

                            // LinkToMany to PreOrder
                            SPtrCriteria criteriaPreOrder = relCustomerToPreOrder.Generate(entity);
                            customer.setLinkToPreOrders(Relation::CreateLinkToMany(sptrPreOrderQuery,
                                                                                   criteriaPreOrder));

                            auto criteriaAddress = relCustomerAddress.Generate(entity);

                            auto columnsList = {
                                    sptrCustomerMap->GetColumn("AddrStreet"),
                                    sptrCustomerMap->GetColumn("AddrZipCode"),
                                    sptrCustomerMap->GetColumn("AddrCity"),
                                    sptrCustomerMap->GetColumn("AddrCountry")
                            };

                            customer.setObjAddress(Relation::CreateMultiCellsObj(sptrCustomerQuery,
                                                                                 criteriaAddress,
                                                                                 columnsList));

                            return customer;
                        };

                sptrPreOrderStore->EntityLoader().fptrNamedEntityCreator =
                        [&sptrCustomerMap, &sptrCustomerQuery, &relPreOrderToCustomer]
                                (const Foundation::Entity &entity) -> Entity::PreOrder {

                            using namespace Foundation::Data;
                            using namespace Foundation::Query;

                            Entity::PreOrder preOrder{};
                            preOrder.setId(NumericToPrimative<int64_t>(entity.getCell("Id")->getValue()));
                            preOrder.setCustomerId(NumericToPrimative<int64_t>(entity.getCell("CustId")->getValue()));
                            preOrder.setName(entity.getCell("Name")->ToString());

                            // LinkToOne to Customer
                            SPtrCriteria criteria = relPreOrderToCustomer.Generate(entity);
                            preOrder.setLinkToCustomer(Relation::CreateLinkToOne(sptrCustomerQuery, criteria));

                            return preOrder;
                        };

                sptrCustomerDriver->Connect();
                sptrPreOrderDriver->Connect();

                // PreOrder referencing Customer (LinkToOne)
                {
                    using namespace Foundation::Query;
                    using namespace Foundation::Data;
                    using CmprFactory = ComparativeFactory;

                    auto sptrPreOrderIdGt00 = CmprFactory::CreateGTE(sptrPreOrderMap->GetColumn("Id"), ValueFactory::CreateInt64(0));
                    auto sptrPreOrderProxy = sptrPreOrderQuery->SelectFirst(sptrPreOrderIdGt00);
                    auto sptrPreOrderEntity = sptrPreOrderStore->Summon(sptrPreOrderProxy);
                    auto preOrder = sptrPreOrderStore->NamedEntity(sptrPreOrderEntity);

                    auto sptrCustomerProxy = preOrder.LinkToCustomer()->Refer();
                    auto sptrCustomerEntity = sptrCustomerStore->Summon(sptrCustomerProxy);
                    EXPECT_TRUE(sptrCustomerProxy.get());
                    EXPECT_TRUE(sptrCustomerEntity.get());
                    EXPECT_TRUE(sptrCustomerEntity->ToString().length() > 0);
                }

                // Customer referencing PreOrder (LinkToMany)
                {
                    using namespace Foundation::Query;
                    using namespace Foundation::Data;
                    using CmprFactory = ComparativeFactory;

                    auto sptrCustomerIdGt00 = CmprFactory::CreateGTE(sptrPreOrderMap->GetColumn("Id"), ValueFactory::CreateInt64(0));
                    auto sptrCustomerProxy = sptrCustomerQuery->SelectFirst(sptrCustomerIdGt00);
                    auto sptrCustomerEntity = sptrCustomerStore->Summon(sptrCustomerProxy);
                    auto customer = (Entity::Customer) sptrCustomerStore->NamedEntity(sptrCustomerEntity);

                    auto sptrPreOrdersVector = customer.LinkToPreOrders()->Refer();
                    for (auto &order : sptrPreOrdersVector) {
                        EXPECT_TRUE(order->ToString().length() > 0);
                    }

                    auto sptrAddress = customer.objAddress()->Refer();
                    auto &sptrStreetCell = sptrAddress->getCell("AddrStreet");
                    auto &sptrZipCodeCell = sptrAddress->getCell("AddrZipCode");
                    auto &sptrCityCell = sptrAddress->getCell("AddrCity");
                    auto &sptrCountryCell = sptrAddress->getCell("AddrCountry");

                    EXPECT_TRUE(sptrStreetCell->getValue()->ToString().length() > 0);
                    EXPECT_TRUE(sptrZipCodeCell->getValue()->ToString().length() > 0);
                    EXPECT_TRUE(sptrCityCell->getValue()->ToString().length() > 0);
                    EXPECT_TRUE(sptrCountryCell->getValue()->ToString().length() > 0);
                }

                sptrCustomerDriver->Disconnect();
                sptrPreOrderDriver->Disconnect();
            }
        }
    }
}

#endif //CLDEPLUS_APPTEST_RELATION_NAMEDENTITY02_HPP
