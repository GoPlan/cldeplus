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

                using Field = Cloude::Foundation::Field;
                using Identity = Cloude::Foundation::Identity;

                TEST_F(EnquirySQLiteStore, CreateGetSaveDelete) {

                    std::string email = "goplan@cloud-e.biz";
                    int64_t enquiryId = 15;

                    auto spEnquiryIdField = make_shared<Field>(_enquiryMap.EnquiryId);
                    spEnquiryIdField->setInt64(enquiryId);

                    auto initFieldList{spEnquiryIdField};
                    auto spIdentity = std::make_shared<Identity>(initFieldList);

                    // CREATE
                    {
                        auto spEntity = _entityStore.Create(spIdentity);
                        ASSERT_TRUE(spEntity.get() != 0);
                        ASSERT_TRUE(_entityStore.HasIdentityInMap(spIdentity));
                    }

                    // GET & SAVE
                    {
                        auto spEntity = _entityStore.Get(spIdentity);
                        ASSERT_TRUE(spEntity.get() != 0);
                        ASSERT_TRUE(_entityStore.HasIdentityInMap(spIdentity));

                        auto spEmailField = spEntity->getField("Email");
                        ASSERT_TRUE(spEmailField.get() != 0);

                        spEmailField->setCString(email.c_str());

                        _entityStore.Save(spEntity);
                        _entityStore.Clear();

                        ASSERT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
                        ASSERT_TRUE(_entityStore.Size() == 0);
                    }

                    // DELETE
                    {
                        auto spEntity = _entityStore.Get(spIdentity);
                        ASSERT_TRUE(spEntity.get() != 0);
                        ASSERT_TRUE(_entityStore.HasIdentityInMap(spIdentity));

                        auto spEmailField = spEntity->getField("Email");
                        ASSERT_TRUE(strcmp(spEmailField->getCString(), email.c_str()) == 0);

                        _entityStore.Delete(spEntity);
                        EXPECT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
                        EXPECT_TRUE(_entityStore.Size() == 0);

                        auto spEntityAlt = _entityStore.Get(spIdentity);
                        EXPECT_TRUE(spEntityAlt.get() == 0);
                    }
                }
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_SQLITESTORE_HPP
