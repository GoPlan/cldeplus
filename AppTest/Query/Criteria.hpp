//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_QUERY_PREDICATE_H
#define CLOUD_E_PLUS_APPTEST_QUERY_PREDICATE_H

#include <memory>
#include <iostream>
#include <functional>
#include "gtest/gtest.h"
#include <Foundation/Foundation.h>
#include <AppTest/Application/EnquiryMap.h>
#include <Drivers/SQLite/SQLiteSourceDriver.h>

namespace Cloude {
    namespace AppTest {
        namespace Query {

            TEST(Query, case01) {

                using namespace Foundation;
                using namespace Foundation::Query;

                std::string email_01{"goplan@cloud-e.biz"};
                std::string email_02{"ducanh.ki@cloud-e.biz"};

                auto sptrEnquiryId_01 = Data::ValueFactory::CreateInt64(1);
                auto sptrEnquiryId_02 = Data::ValueFactory::CreateInt64(2);
                auto sptrEmail_01 = Data::ValueFactory::CreateVarChar(email_01);
                auto sptrEmail_02 = Data::ValueFactory::CreateVarChar(email_02);

                AppTest::Application::EnquiryMap enquiryMap{};
                Drivers::SQLite::SQLiteSourceDriver sqliteSourceDriver{enquiryMap};
                sqliteSourceDriver.OptionArgs().ConnectionString = "example01.db";
                sqliteSourceDriver.Connect();

                auto enquiryStore = Foundation::CreateEntityStore(enquiryMap, sqliteSourceDriver);
                auto enquiryQuery = Foundation::CreateEntityQuery(enquiryMap, sqliteSourceDriver);

                SPtrColumnVector vtorCmpColumns{enquiryMap.Email};
                Foundation::Store::Comparer::Compare<> compare{vtorCmpColumns, vtorCmpColumns};

                using CmpFactory = Foundation::Query::ComparativeFactory;

                auto sptrIdEq_01 = CmpFactory::CreateEQ(enquiryMap.EnquiryId, sptrEnquiryId_01);
                auto sptrIdEq_02 = CmpFactory::CreateEQ(enquiryMap.EnquiryId, sptrEnquiryId_02);
                auto sptrEmail01 = CmpFactory::CreateLike(enquiryMap.Email, sptrEmail_01);
                auto sptrEmail02 = CmpFactory::CreateLike(enquiryMap.Email, sptrEmail_02);
                auto sptrOR01 = CmpFactory::CreateOR(sptrIdEq_01, sptrEmail01);
                auto sptrOR02 = CmpFactory::CreateOR(sptrIdEq_02, sptrEmail02);
                auto sptrOR__ = CmpFactory::CreateOR(sptrOR01, sptrOR02);

                auto fptrCondition = [](const SPtrColumn &column, const int &index) -> std::string {
                    return std::string{"?"};
                };

                auto compound = Helper::SqlHelper::CreateSelectPreparedQuery
                        (enquiryMap.getTableName(), enquiryMap.getColumnsForSelect(), sptrOR__, fptrCondition);

                {
                    auto proxies = enquiryQuery->Select(sptrOR__);
                    auto proxy00 = proxies[0];
                    auto proxy01 = enquiryQuery->SelectFirst(sptrOR__);

                    EXPECT_TRUE(compare(proxy00, proxy01));

                    for (auto proxy : proxies) {

                        auto sptrEntity = proxy->Summon(enquiryStore);

                        EXPECT_TRUE(sptrEntity.get() != 0);
                        EXPECT_TRUE(sptrEntity->ToString().length() > 0);
                    }
                }

                sqliteSourceDriver.Disconnect();
            }
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_QUERY_PREDICATE_H
