//
// Created by LE, Duc Anh on 6/8/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYSQLITESTORE_H
#define CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYSQLITESTORE_H

#include "gtest/gtest.h"
#include <Foundation/Foundation.h>
#include <Drivers/SQLite/SQLiteSourceDriver.h>
#include <AppTest/Application/EnquiryMap.h>

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Preparation {

                class EnquirySQLiteStore : public ::testing::Test {

                public:
                    EnquirySQLiteStore();
                    EnquirySQLiteStore(const EnquirySQLiteStore &) = default;
                    EnquirySQLiteStore(EnquirySQLiteStore &&) = default;
                    EnquirySQLiteStore &operator=(const EnquirySQLiteStore &) = default;
                    EnquirySQLiteStore &operator=(EnquirySQLiteStore &&) = default;
                    ~EnquirySQLiteStore() = default;

                protected:
                    using EnquiryMap = Application::EnquiryMap;
                    using SQLiteSourceDriver = Drivers::SQLite::SQLiteSourceDriver;
                    using EntityStore = Foundation::EntityStore;

                    void SetUp() override;
                    void TearDown() override;

                    EnquiryMap _enquiryMap;
                    EntityStore _entityStore;
                    SQLiteSourceDriver _sqliteSourceDriver;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYSQLITESTORE_H
