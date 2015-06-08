//
// Created by LE, Duc Anh on 6/8/15.
//

#ifndef CLOUD_E_CPLUS_SQLITESTORE_HPP
#define CLOUD_E_CPLUS_SQLITESTORE_HPP

#include "gtest/gtest.h"
#include "../EnquirySQLiteStore.h"

using namespace std;

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Test {

                using Field = Cloude::Framework::Field;
                using Identity = Cloude::Framework::Identity;

                TEST_F(EnquirySQLiteStore, CreateGetSaveDelete) {

                    int64_t enquiryId = 15;

                    auto spEnquiryIdField = make_shared<Field>(_enquiryMap.EnquiryId);
                    spEnquiryIdField->setInt64(enquiryId);

                    auto initFieldList{spEnquiryIdField};
                    auto spIdentity = std::make_shared<Identity>(initFieldList);

                    // CREATE
                    {
                        auto entity = _entityStore.Create(spIdentity);
                        ASSERT_TRUE(entity.get() != 0);
                    }

                    // CLEAR
                    {
                        _entityStore.Clear();
                        ASSERT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
                        ASSERT_TRUE(_entityStore.Size() == 0);
                    }

                }
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_SQLITESTORE_HPP
