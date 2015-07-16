//
// Created by LE, Duc Anh on 7/9/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY02_HPP
#define CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY02_HPP

#include "gtest/gtest.h"
#include <Foundation/Foundation.h>
#include <Relation/Relation.h>
#include <Drivers/SQLite/SQLiteSourceDriver.h>
#include <AppTest/Application/CustomerMap.h>
#include <AppTest/Application/PreOrderMap.h>
#include <AppTest/Entity/Customer.h>
#include <AppTest/Entity/PreOrder.h>
#include <Drivers/MySql/MySqlSourceDriver.h>

namespace Cloude {
    namespace AppTest {
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

                Relation::RelationMap linkCustomerToPreOrder{};
                Relation::RelationMap linkPreOrderToCustomer{};

                linkCustomerToPreOrder.AddLink(mapCustomer.Id, mapPreOrder.CustId);
                linkPreOrderToCustomer.AddLink(mapPreOrder.CustId, mapCustomer.Id);

                auto sptrCustomerQuery = Foundation::CreateEntityQuery(mapCustomer, driverCustomer);
                auto sptrPreOrderQuery = Foundation::CreateEntityQuery(mapPreOrder, driverPreOrder);
                auto sptrCustomerStore = Relation::CreateNamedStore<Entity::Customer>(mapCustomer, driverCustomer);
                auto sptrPreOrderStore = Relation::CreateNamedStore<Entity::PreOrder>(mapPreOrder, driverPreOrder);

                sptrCustomerStore->EntityLoader().fptrNamedEntityCreator =
                        [&mapPreOrder, &sptrPreOrderQuery, &linkCustomerToPreOrder]
                                (const Foundation::Entity &entity) -> Entity::Customer {

                            using namespace Foundation::Data;
                            using namespace Foundation::Query;

                            Entity::Customer customer{};
                            customer.setId(NumericToPrimative<int64_t>(entity.getCell("Id")->getValue()));
                            customer.setFirstName(entity.getCell("FirstName")->ToString());
                            customer.setLastName(entity.getCell("LastName")->ToString());
                            customer.setEmail(entity.getCell("Email")->ToString());

                            // LinkToMany to PreOrder
                            SPtrCriteria criteria = linkCustomerToPreOrder.Generate(entity);
                            customer.setSptrPreOrders(Relation::CreateLinkToMany(sptrPreOrderQuery, criteria));

                            return customer;
                        };

                sptrPreOrderStore->EntityLoader().fptrNamedEntityCreator =
                        [&mapCustomer, &sptrCustomerQuery, &linkPreOrderToCustomer]
                                (const Foundation::Entity &entity) -> Entity::PreOrder {

                            using namespace Foundation::Data;
                            using namespace Foundation::Query;

                            Entity::PreOrder preOrder{};
                            preOrder.setId(NumericToPrimative<int64_t>(entity.getCell("Id")->getValue()));
                            preOrder.setCustomerId(NumericToPrimative<int64_t>(entity.getCell("CustId")->getValue()));
                            preOrder.setName(entity.getCell("Name")->ToString());

                            // LinkToOne to Customer
                            SPtrCriteria criteria = linkPreOrderToCustomer.Generate(entity);
                            preOrder.setSptrCustomer(Relation::CreateLinkToOne(sptrCustomerQuery, criteria));

                            return preOrder;
                        };

                driverCustomer.Connect();
                driverPreOrder.Connect();

                // PreOrder referencing Customer (LinkToOne)
                Foundation::Query::SPtrCriteria sptrPreOrderIdGt00;
                {
                    using namespace Foundation::Query;
                    using namespace Foundation::Data;
                    sptrPreOrderIdGt00 = ComparativeFactory::CreateGTE(mapPreOrder.Id, ValueFactory::CreateInt64(0));
                }

                auto sptrPreOrderProxy = sptrPreOrderQuery->SelectFirst(sptrPreOrderIdGt00);
                auto sptrPreOrderEntity = sptrPreOrderStore->Summon(sptrPreOrderProxy);
                auto preOrder = sptrPreOrderStore->NamedEntity(sptrPreOrderEntity);

                {
                    auto sptrCustomerProxy = preOrder.sptrCustomer()->Call();
                    auto sptrCustomerEntity = sptrCustomerStore->Summon(sptrCustomerProxy);

                    EXPECT_TRUE(sptrCustomerProxy.get());
                    EXPECT_TRUE(sptrCustomerEntity.get());
                    EXPECT_TRUE(sptrCustomerEntity->ToString().length() > 0);
                }

                // Customer referencing PreOrder (LinkToMany)
                Foundation::Query::SPtrCriteria sptrCustomerIdGt00;
                {
                    using namespace Foundation::Query;
                    using namespace Foundation::Data;
                    sptrCustomerIdGt00 = ComparativeFactory::CreateGTE(mapPreOrder.Id, ValueFactory::CreateInt64(0));
                }

                auto sptrCustomerProxy = sptrCustomerQuery->SelectFirst(sptrCustomerIdGt00);
                auto sptrCustomerEntity = sptrCustomerStore->Summon(sptrCustomerProxy);
                auto customer = sptrCustomerStore->NamedEntity(sptrCustomerEntity);

                {
                    auto sptrPreOrdersVector = customer.sptrPreOrders()->Call();
                    for (auto &order : sptrPreOrdersVector) {
                        EXPECT_TRUE(order->ToString().length() > 0);
                    }
                }

                driverCustomer.Disconnect();
                driverPreOrder.Disconnect();
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY02_HPP
