//
// Created by LE, Duc Anh on 7/9/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY02_HPP
#define CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY02_HPP

#include <gtest/gtest.h>

#include "../Application/CustomerMap.h"
#include "../Application/PreOrderMap.h"
#include "../Entity/Customer.h"
#include "../Entity/PreOrder.h"

#include "../../Source/Drivers/MySql/MySqlSourceDriver.h"
#include "../../Source/Drivers/SQLite/SQLiteSourceDriver.h"

namespace Cloude {
    namespace Test {
        namespace Store {

            TEST(Relation, NamedEntityReferencingSQLiteAndMySql) {

                Application::CustomerMap mapCustomer{};
                Application::PreOrderMap mapPreOrder{};

                Drivers::SQLite::SQLiteSourceDriver driverCustomer{mapCustomer};
                Drivers::MySql::MySqlSourceDriver driverPreOrder{mapPreOrder};

                driverCustomer.OptionArgs().ConnectionString = "example01.db";
                driverPreOrder.OptionArgs().Host = "dell-3020";
                driverPreOrder.OptionArgs().User = "cloud-e";
                driverPreOrder.OptionArgs().Pass = "cloud-e";
                driverPreOrder.OptionArgs().Base = "cloud-e";
                driverPreOrder.OptionArgs().Port = 3306;

                Relation::RelationMap relCustomerToPreOrder{};
                Relation::RelationMap relCustomerAddress{};
                Relation::RelationMap relPreOrderToCustomer{};

                relCustomerToPreOrder.AddLink(mapCustomer.Id, mapPreOrder.CustId);
                relCustomerAddress.AddLink(mapCustomer.Id, mapCustomer.Id);
                relPreOrderToCustomer.AddLink(mapPreOrder.CustId, mapCustomer.Id);

                auto sptrCustomerQuery = Foundation::CreateEntityQuery(mapCustomer, driverCustomer);
                auto sptrPreOrderQuery = Foundation::CreateEntityQuery(mapPreOrder, driverPreOrder);
                auto sptrCustomerStore = Relation::CreateNamedStore<Entity::Customer>(mapCustomer, driverCustomer);
                auto sptrPreOrderStore = Relation::CreateNamedStore<Entity::PreOrder>(mapPreOrder, driverPreOrder);

                sptrCustomerStore->EntityLoader().fptrNamedEntityCreator =
                        [&mapCustomer, &mapPreOrder,
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

                            auto columnsList = {mapCustomer.AddrStreet,
                                                mapCustomer.AddrZipCode,
                                                mapCustomer.AddrCity,
                                                mapCustomer.AddrCountry};

                            customer.setObjAddress(Relation::CreateMultiCellsObj(sptrCustomerQuery,
                                                                                 criteriaAddress,
                                                                                 columnsList));

                            return customer;
                        };

                sptrPreOrderStore->EntityLoader().fptrNamedEntityCreator =
                        [&mapCustomer, &sptrCustomerQuery, &relPreOrderToCustomer]
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

                driverCustomer.Connect();
                driverPreOrder.Connect();

                // PreOrder referencing Customer (LinkToOne)
                {
                    using namespace Foundation::Query;
                    using namespace Foundation::Data;
                    using CmprFactory = ComparativeFactory;

                    auto sptrPreOrderIdGt00 = CmprFactory::CreateGTE(mapPreOrder.Id, ValueFactory::CreateInt64(0));
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

                    auto sptrCustomerIdGt00 = CmprFactory::CreateGTE(mapPreOrder.Id, ValueFactory::CreateInt64(0));
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

                driverCustomer.Disconnect();
                driverPreOrder.Disconnect();
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY02_HPP
