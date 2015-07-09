//
// Created by LE, Duc Anh on 7/9/15.
//

#ifndef CLOUD_E_PLUS_NAMEDENTITY02_HPP
#define CLOUD_E_PLUS_NAMEDENTITY02_HPP

#include "gtest/gtest.h"
#include <Foundation/Foundation.h>
#include <Drivers/SQLite/SQLiteSourceDriver.h>
#include <AppTest/Application/CustomerMap.h>
#include <AppTest/Application/CustomerLoader.h>
#include <AppTest/Application/PreOrderMap.h>
#include <AppTest/Application/PreOrderLoader.h>
#include <AppTest/Entity/Customer.h>
#include <AppTest/Entity/PreOrder.h>


namespace Cloude {
    namespace AppTest {
        namespace Store {

            TEST(Relation, NamedEntity02) {

                Application::CustomerMap mapCustomer{};
                Application::PreOrderMap mapPreOrder{};
                Application::CustomerLoader loaderCustomer{};
                Application::PreOrderLoader loaderPreOrder{};

                Drivers::SQLite::SQLiteSourceDriver driverCustomer{mapCustomer};
                Drivers::SQLite::SQLiteSourceDriver driverPreOrder{mapPreOrder};
                driverCustomer.OptionArgs().ConnectionString = "../ex1.db";
                driverPreOrder.OptionArgs().ConnectionString = "../ex1.db";

                auto sptrCustomerStore = Foundation::CreateStoreSharedPtr(mapCustomer, loaderCustomer, driverCustomer);
                auto sptrPreOrderStore = Foundation::CreateStoreSharedPtr(mapPreOrder, loaderPreOrder, driverPreOrder);
                auto sptrCustomerQuery = Foundation::CreateQuerySharedPtr(sptrCustomerStore);
                auto sptrPreOrderQuery = Foundation::CreateQuerySharedPtr(sptrPreOrderStore);

                auto fptrCustomerCreator = [](const Foundation::SPtrEntity &entity) -> Entity::Customer {

                    using namespace Foundation::Data;

                    Entity::Customer customer{};

                    return customer;
                };

                auto fptrPreOrderCreator = [](const Foundation::Entity &entity) -> Entity::PreOrder {

                    using namespace Foundation::Data;
                    using namespace Relation;

                    Entity::PreOrder preOrder{};
                    preOrder.setId(ToNumeric<int64_t>(entity.getCell("Id")->getValue()));
                    preOrder.setCustomerId(ToNumeric<int64_t>(entity.getCell("CustId")->getValue()));
                    preOrder.setName(entity.getCell("Name")->ToString());

//                    SPtrLinkToOne linkToCustomer = Relation::CreateLinkToOne(sptrCustomerQuery, )

                    return preOrder;
                };

                driverCustomer.Connect();
                driverPreOrder.Connect();

                Foundation::Query::SPtrCriteria sptrPreOrderIdGt00;
                {
                    using namespace Foundation::Query;
                    using namespace Foundation::Data;
                    sptrPreOrderIdGt00.reset(new Comparative::GreaterOrEqual(mapPreOrder.Id, ValueFactory::CreateInt64(0)));
                }

                auto sptrProxy = sptrPreOrderQuery->SelectFirst(sptrPreOrderIdGt00);
                auto sptrEntity = sptrProxy->Summon(sptrPreOrderStore);
                auto preOrder = sptrEntity->NamedEntity<Entity::PreOrder>(fptrPreOrderCreator);

                std::cout << preOrder.getId() << std::endl;
                std::cout << preOrder.getCustomerId() << std::endl;
                std::cout << preOrder.getName() << std::endl;

                driverCustomer.Disconnect();
                driverPreOrder.Disconnect();
            }
        }
    }
}

#endif //CLOUD_E_PLUS_NAMEDENTITY02_HPP
