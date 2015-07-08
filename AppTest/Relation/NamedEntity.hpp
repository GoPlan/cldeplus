//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY_HPP
#define CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY_HPP

#include <Drivers/SQLite/SQLiteSourceDriver.h>
#include "gtest/gtest.h"
#include "../Entity/Enquiry.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {

            TEST(Relation, NamedEntity01) {

                using namespace Foundation;
                using namespace Foundation::Query;

                auto sptrEnquiryId_04 = Data::ValueFactory::CreateInt64(4);

                AppTest::Application::EnquiryMap enquiryMap;
                AppTest::Application::EnquiryLoader enquiryLoader;

                Drivers::SQLite::SQLiteSourceDriver sqliteSourceDriver{enquiryMap};
                sqliteSourceDriver.OptionArgs().ConnectionString = "../ex1.db";

                auto sptrEnquiryStore = std::make_shared<EntityStore>(enquiryMap, enquiryLoader, sqliteSourceDriver);
                auto sptrEnquiryQuery = std::make_shared<EntityQuery>(sptrEnquiryStore);

                sqliteSourceDriver.Connect();

                SPtrCriteria sptrIdEq01(new Comparative::Equal(enquiryMap.EnquiryId, sptrEnquiryId_04));
                SPtrEntityProxy sptrProxy = sptrEnquiryQuery->SelectFirst(sptrIdEq01);
                SPtrEntity sptrEntity = sptrProxy->Summon(sptrEnquiryStore);

                EXPECT_TRUE(sptrProxy.get());
                EXPECT_TRUE(sptrEntity.get());

                std::cout << sptrEntity->ToString() << std::endl;


                auto converter = [](const Foundation::Entity &entity) -> Entity::Enquiry {

                    Entity::Enquiry enquiry{};

                    auto &id = entity.getCell("EnquiryId")->getValue();
                    auto &email = entity.getCell("Email")->getValue();
                    auto &subject = entity.getCell("Subject")->getValue();

                    enquiry.setId(*(int64_t *) (id->RawPointerToValueBuffer()));
                    enquiry.setEmail(std::string{(const char *) email->RawPointerToValueBuffer()});
                    enquiry.setSubject(std::string{(const char *) subject->RawPointerToValueBuffer()});

                    return enquiry;
                };

                auto enquiry = sptrEntity->NamedEntity<Entity::Enquiry>(converter);
                
                std::cout << enquiry.getId() << std::endl;
                std::cout << enquiry.getEmail() << std::endl;
                std::cout << enquiry.getSubject() << std::endl;

                sqliteSourceDriver.Disconnect();

            }
        }
    }
}
#endif //CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY_HPP
