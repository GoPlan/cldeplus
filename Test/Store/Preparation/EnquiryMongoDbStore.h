//
// Created by LE, Duc Anh on 6/6/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYMONGODBSTORE_H
#define CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYMONGODBSTORE_H

#include "gtest/gtest.h"
#include <Cloude.h>
#include <SourceDriver/MongoDb/MongoDbSourceDriver.h>
#include <Application/Mapper/EnquiryLoader.h>
#include <Application/Mapper/EnquiryMap.h>

namespace Cloude {
    namespace AppTest {
        namespace Store {

            class EnquiryMongoDbStore : public ::testing::Test {
            public:
                EnquiryMongoDbStore();
                EnquiryMongoDbStore(const EnquiryMongoDbStore &) = default;
                EnquiryMongoDbStore(EnquiryMongoDbStore &&) = default;
                EnquiryMongoDbStore &operator=(const EnquiryMongoDbStore &) = default;
                EnquiryMongoDbStore &operator=(EnquiryMongoDbStore &&) = default;
                ~EnquiryMongoDbStore() = default;

            protected:
                using EnquiryMap = Application::Mapper::EnquiryMap;
                using EnquiryLoader = Application::Mapper::EnquiryLoader;
                using MongoDbSourceDriver = SourceDriver::MongoDb::MongoDbSourceDriver;
                using EntityStore = Foundation::EntityStore;

                void SetUp() override;
                void TearDown() override;

                EnquiryMap _enquiryMap;
                EnquiryLoader _enquiryLoader;
                MongoDbSourceDriver _mongoDbSourceDriver;
                EntityStore _entityStore;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYMONGODBSTORE_H
