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

                using Field = Cloude::Architecture::Field;
                using Identity = Cloude::Architecture::Identity;

                TEST_F(EnquiryMongoDbStore, CreateGetSaveDelete) {

                    int64_t enquiryId = 15;

                    auto spEnquiryIdField = make_shared<Field>(_enquiryMap.EnquiryId);
                    spEnquiryIdField->setInt64(enquiryId);

                    // setMultiFields(initializer_list<shared_ptr<Field>>()
                    auto initFieldList{spEnquiryIdField};
                    auto spIdentity = std::make_shared<Identity>(initFieldList);

                }
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_MONGODBSTORE_HPP
