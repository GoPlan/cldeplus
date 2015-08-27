//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY01_HPP
#define CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY01_HPP

#include <gtest/gtest.h>

#include "../Entity/Customer.h"
#include "../Application/CustomerMap.h"

#include "../../Source/Foundation/Foundation.h"
#include "../../Source/Drivers/SQLite/SQLiteSourceDriver.h"

namespace Cloude {
    namespace Test {
        namespace Store {

            TEST(Relation, ConvertEntityToNamedEntity) {

                using namespace Foundation;
                using namespace Foundation::Query;

                auto sptrId04 = Data::ValueFactory::CreateInt64(4);

                auto sptrCustomerMap = Application::Create<Application::CustomerMap>();
                auto sptrCustomerDriver = (Drivers::SQLite::SPtrSQLiteSourceDriver)Drivers::SQLite::SQLiteSourceDriver::Create(sptrCustomerMap);
                sptrCustomerDriver->OptionArgs().ConnectionString = "example01.db";

                auto sptrCustomerStore = (Foundation::SPtrEntityStore)Foundation::EntityStore::Create(sptrCustomerMap,sptrCustomerDriver);
                auto sptrCustomerQuery = (Foundation::SPtrEntityQuery)Foundation::EntityQuery::Create(sptrCustomerMap, sptrCustomerDriver);

                sptrCustomerDriver->Connect();

                auto sptrIdEq01 = ComparativeFactory::CreateEQ(sptrCustomerMap->GetColumn("Id"), sptrId04);
                auto sptrProxy = sptrCustomerQuery->SelectFirst(sptrIdEq01);
                auto sptrEntity = sptrProxy->Summon(sptrCustomerStore);

                EXPECT_TRUE(sptrProxy.get());
                EXPECT_TRUE(sptrEntity.get());

                auto converter = [](const Foundation::Entity &entity) -> Entity::Customer {

                    Entity::Customer customer{};

                    auto &id = entity.getCell("Id")->getValue();
                    auto &firstname = entity.getCell("FirstName")->getValue();
                    auto &lastname = entity.getCell("LastName")->getValue();
                    auto &email = entity.getCell("Email")->getValue();

                    customer.setId(*(int64_t *) (id->PointerToBuffer()));
                    customer.setFirstName(std::string{(const char *) firstname->PointerToBuffer()});
                    customer.setLastName(std::string{(const char *) lastname->PointerToBuffer()});
                    customer.setEmail(std::string{(const char *) email->PointerToBuffer()});

                    return customer;
                };

                auto customer = sptrEntity->NamedEntity<Entity::Customer>(converter);

                EXPECT_TRUE(customer.getId() > 0);
                EXPECT_TRUE(customer.getFirstName().length() > 0);
                EXPECT_TRUE(customer.getLastName().length() > 0);
                EXPECT_TRUE(customer.getEmail().length() > 0);

                sptrCustomerDriver->Disconnect();
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY01_HPP
