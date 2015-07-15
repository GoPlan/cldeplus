//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY_HPP
#define CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY_HPP

#include "gtest/gtest.h"
#include <Foundation/Foundation.h>
#include <Drivers/SQLite/SQLiteSourceDriver.h>
#include <AppTest/Entity/Enquiry.h>

namespace Cloude {
    namespace AppTest {
        namespace Store {

            TEST(Relation, ConvertEntityToNamedEntity) {

                using namespace Foundation;
                using namespace Foundation::Query;

                auto sptrEnquiryId_04 = Data::ValueFactory::CreateInt64(4);

                AppTest::Application::EnquiryMap enquiryMap{};
                Drivers::SQLite::SQLiteSourceDriver sqliteSourceDriver{enquiryMap};
                sqliteSourceDriver.OptionArgs().ConnectionString = "example01.db";

                auto sptrEnquiryStore = Foundation::CreateEntityStore(enquiryMap, sqliteSourceDriver);
                auto sptrEnquiryQuery = Foundation::CreateEntityQuery(enquiryMap, sqliteSourceDriver);

                sqliteSourceDriver.Connect();

                auto sptrIdEq01 = ComparativeFactory::CreateEQ(enquiryMap.EnquiryId, sptrEnquiryId_04);
                auto sptrProxy = sptrEnquiryQuery->SelectFirst(sptrIdEq01);
                auto sptrEntity = sptrProxy->Summon(sptrEnquiryStore);

                EXPECT_TRUE(sptrProxy.get());
                EXPECT_TRUE(sptrEntity.get());

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

                EXPECT_TRUE(enquiry.getId() > 0);
                EXPECT_TRUE(enquiry.getEmail().length() > 0);
                EXPECT_TRUE(enquiry.getSubject().length() > 0);

                sqliteSourceDriver.Disconnect();
            }
        }
    }
}
#endif //CLOUD_E_PLUS_APPTEST_RELATION_NAMEDENTITY_HPP
