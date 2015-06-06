//
// Created by LE, Duc Anh on 6/6/15.
//

#ifndef CLOUD_E_CPLUS_MONGODBSTORE_HPP
#define CLOUD_E_CPLUS_MONGODBSTORE_HPP

#include "gtest/gtest.h"
#include "../EnquiryMongoDbStore.h"

using namespace std;

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Test {

                using EnquiryStore = AppTest::Store::EnquiryMongoDbStore;

                TEST_F(EnquiryStore, CreateGetSaveDelete) {

                }
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_MONGODBSTORE_HPP
