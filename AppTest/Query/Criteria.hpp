//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_CPLUS_APPTEST_QUERY_PREDICATE_H
#define CLOUD_E_CPLUS_APPTEST_QUERY_PREDICATE_H

#include <memory>
#include <iostream>
#include <functional>
#include "gtest/gtest.h"
#include <Foundation/Foundation.h>
#include <AppTest/Application/EnquiryMap.h>
#include <AppTest/Application/EnquiryLoader.h>

namespace Cloude {
    namespace AppTest {
        namespace Query {

            TEST(Predicate, case01) {

                using namespace Foundation;
                using namespace Foundation::Query;

                std::string email_01{"goplan@cloud-e.biz"};
                std::string email_02{"ducanh.ki@cloud-e.biz"};

                auto sptrEnquiryId_01 = Data::ValueFactory::CreateInt64(1);
                auto sptrEnquiryId_02 = Data::ValueFactory::CreateInt64(2);
                auto sptrEmail_01 = Data::ValueFactory::CreateVarChar(email_01);
                auto sptrEmail_02 = Data::ValueFactory::CreateVarChar(email_02);

                AppTest::Application::EnquiryMap enquiryMap;
                AppTest::Application::EnquiryLoader enquiryLoader;
                Drivers::SQLite::SQLiteSourceDriver sqliteSourceDriver{enquiryMap};
                auto enquiryStore = std::make_shared<EntityStore>(enquiryMap, enquiryLoader, sqliteSourceDriver);
                auto enquiryQuery = std::make_shared<EntityQuery>(enquiryStore);

                SPtrColumnVector vtorCmpColumns{enquiryMap.Email};
                Foundation::Store::Comparer::Compare<> compare{vtorCmpColumns, vtorCmpColumns};

                auto &options = sqliteSourceDriver.OptionArgs();
                options.ConnectionString = "../ex1.db";
                sqliteSourceDriver.Connect();

                SPtrCriteria sptrIdEq01(new Comparative::Equal(enquiryMap.EnquiryId, sptrEnquiryId_01));
                SPtrCriteria sptrIdEq02(new Comparative::Equal(enquiryMap.EnquiryId, sptrEnquiryId_02));
                SPtrCriteria sptrEmail01(new Comparative::Like(enquiryMap.Email, sptrEmail_01));
                SPtrCriteria sptrEmail02(new Comparative::Like(enquiryMap.Email, sptrEmail_02));

                SPtrCriteria sptrOR01(new Comparative::Or(sptrIdEq01, sptrEmail01));
                SPtrCriteria sptrOR02(new Comparative::Or(sptrIdEq02, sptrEmail02));
                SPtrCriteria sptrOR__(new Comparative::Or(sptrOR01, sptrOR02));

                auto fptrCondition = [](const SPtrColumn &column, const int &index) -> std::string {
                    return std::string{"?"};
                };

                auto compound = Helper::SqlHelper::CreateSelectPreparedQuery
                        (enquiryMap.getTableName(), enquiryMap.getColumnsForSelect(), sptrOR__, fptrCondition);

                std::cout << compound.first << std::endl;

                {
                    auto proxies = enquiryQuery->Select(sptrOR__);

                    for (auto proxy : proxies) {
                        auto sptrEntity = proxy->Summon(enquiryStore);
                        ASSERT_TRUE(sptrEntity.get() != 0);
                        std::cout << proxy->ToString() << endl;
                    }

                    auto proxy00 = proxies[0];
                    auto proxy01 = enquiryQuery->SelectFirst(sptrOR__);

                    EXPECT_TRUE(compare(proxy00, proxy01));
                }

                sqliteSourceDriver.Disconnect();

                std::cout << "Finished!" << std::endl;
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_APPTEST_QUERY_PREDICATE_H
