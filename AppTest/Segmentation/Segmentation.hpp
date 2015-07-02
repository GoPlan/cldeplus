//
// Created by LE, Duc Anh on 6/19/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_SEGMENTATION_HPP
#define CLOUD_E_PLUS_APPTEST_SEGMENTATION_HPP

#include "gtest/gtest.h"
#include <memory>
#include <iostream>
#include <functional>
#include <Cloude.h>
#include <AppTest/Application/EnquiryMap.h>
#include <AppTest/Application/EnquiryLoader.h>
#include <Drivers/SQLite/SQLiteSourceDriver.h>
#include <Foundation/Query/Helper/SqlHelper.h>

namespace Cloude {
    namespace AppTest {
        namespace Segmentation {

            TEST(Segmentation, case01) {

                using namespace Foundation;
                using namespace Foundation::Query;

                std::string email_01{"goplan@cloud-e.biz"};
                std::string email_02{"ducanh.ki@cloud-e.biz"};

                auto sptrEnquiryId_01 = Data::ValueFactory::CreateInt64(1);
                auto sptrEnquiryId_02 = Data::ValueFactory::CreateInt64(2);
                auto sptrEmail_01 = Data::ValueFactory::CreateVarChar(email_01);
                auto sptrEmail_02 = Data::ValueFactory::CreateVarChar(email_02);

                Application::EnquiryMap enquiryMap{};
                Application::EnquiryLoader enquiryLoader{};
                Drivers::SQLite::SQLiteSourceDriver sqliteSourceDriver{enquiryMap};
                auto enquiryStore = std::make_shared<EntityStore>(enquiryMap, enquiryLoader, sqliteSourceDriver);
                auto enquiryQuery = std::make_shared<EntityQuery>(enquiryStore);

            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_SEGMENTATION_HPP
