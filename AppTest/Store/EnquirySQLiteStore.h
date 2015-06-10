//
// Created by LE, Duc Anh on 6/8/15.
//

#ifndef CLOUD_E_CPLUS_ENQUIRYSQLITESTORE_H
#define CLOUD_E_CPLUS_ENQUIRYSQLITESTORE_H

#include "gtest/gtest.h"
#include <Cloude.h>
#include <SourceDriver/SQLite/SQLiteSourceDriver.h>
#include <Application/Mapper/EnquiryLoader.h>
#include <Application/Mapper/EnquiryMap.h>


namespace Cloude {
    namespace AppTest {
        class EnquirySQLiteStore : public ::testing::Test {
        public:
            EnquirySQLiteStore();
             ~EnquirySQLiteStore() = default;
            EnquirySQLiteStore(const EnquirySQLiteStore &srcEnquirySQLiteStore) = default;
            EnquirySQLiteStore &operator=(const EnquirySQLiteStore &srcEnquirySQLiteStore) = default;

        protected:
            using EnquiryMap = Application::Mapper::EnquiryMap;
            using EnquiryLoader = Application::Mapper::EnquiryLoader;
            using SQLiteSourceDriver = SourceDriver::SQLite::SQLiteSourceDriver;
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


#endif //CLOUD_E_CPLUS_ENQUIRYSQLITESTORE_H
