//
// Created by LE, Duc Anh on 6/6/15.
//

#include <Infrastructure/MongoDb/MongoDbSourceDriver.h>
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

                _mongoDbSourceDriver.OptionArgs.Host = "dell-3020";
                _mongoDbSourceDriver.OptionArgs.User = "cloude";
                _mongoDbSourceDriver.OptionArgs.Pass = "cloude";
                _mongoDbSourceDriver.OptionArgs.Base = "cloude";
                _mongoDbSourceDriver.OptionArgs.Port = 27017;

            }

            void EnquiryMongoDbStore::TearDown() {

                //

            }
        }
    }
}


