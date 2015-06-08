//
// Created by LE, Duc Anh on 6/6/15.
//

#include <SourceDriver/MongoDb/MongoDbSourceDriver.h>
#include "EnquiryMongoDbStore.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {

            EnquiryMongoDbStore::EnquiryMongoDbStore() : _mongoDbSourceDriver(_enquiryMap),
                                                         _entityStore(_enquiryMap,
                                                                      _enquiryLoader,
                                                                      _mongoDbSourceDriver) {
                //
            }

            void EnquiryMongoDbStore::SetUp() {

                auto &optionArgs = _mongoDbSourceDriver.getOptionArgs();

                optionArgs.Host = "dell-3020";
                optionArgs.Base = "test";
                optionArgs.Port = 27017;

                _mongoDbSourceDriver.Connect();

            }

            void EnquiryMongoDbStore::TearDown() {
                _mongoDbSourceDriver.Disconnect();
            }
        }
    }
}


