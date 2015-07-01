//
// Created by LE, Duc Anh on 6/8/15.
//

#ifndef CLOUD_E_CPLUS_APPTEST_STORE_PREPARATION_ENQUIRYSQLITESTORE_H
#define CLOUD_E_CPLUS_APPTEST_STORE_PREPARATION_ENQUIRYSQLITESTORE_H

#include "gtest/gtest.h"
#include <Cloude.h>
#include <Drivers/SQLite/SQLiteSourceDriver.h>
#include <AppTest/Application/EnquiryLoader.h>
#include <AppTest/Application/EnquiryMap.h>

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Preparation {

                class EnquirySQLiteStore : public ::testing::Test {

                public:
                    EnquirySQLiteStore();
                    ~EnquirySQLiteStore() = default;
                    EnquirySQLiteStore(const EnquirySQLiteStore &srcEnquirySQLiteStore) = default;
                    EnquirySQLiteStore &operator=(const EnquirySQLiteStore &srcEnquirySQLiteStore) = default;

                protected:
                    using EnquiryMap = Application::EnquiryMap;
                    using EnquiryLoader = Application::EnquiryLoader;
                    using SQLiteSourceDriver = Drivers::SQLite::SQLiteSourceDriver;
                    using EntityStore = Foundation::EntityStore;

                    void SetUp() override;
                    void TearDown() override;

                    EnquiryMap _enquiryMap;
                    EnquiryLoader _enquiryLoader;
                    SQLiteSourceDriver _sqliteSourceDriver;
                    EntityStore _entityStore;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_APPTEST_STORE_PREPARATION_ENQUIRYSQLITESTORE_H
