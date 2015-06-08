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

                using Field = Cloude::Framework::Field;
                using Identity = Cloude::Framework::Identity;

                TEST_F(EnquiryMongoDbStore, CreateGetSaveDelete) {

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

                    // GET & SAVE
                    {
                        auto entity = _entityStore.Get(spIdentity);
                        auto spNameField = entity->getField("Email");
                        ASSERT_TRUE(entity.get() != 0);
                        ASSERT_TRUE(spNameField.get() != 0);

                        spNameField->setCString("ducanh.ki@cloud-e.biz");
                        _entityStore.Save(entity);
                    }

                    // CLEAR
                    {
                        _entityStore.Clear();
                        ASSERT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
                        ASSERT_TRUE(_entityStore.Size() == 0);
                    }

                    // DELETE
                    {
                        auto entity = _entityStore.Get(spIdentity);
                        _entityStore.Delete(entity);
                        ASSERT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));

                        auto entityAlt = _entityStore.Get(spIdentity);
                        ASSERT_TRUE(entityAlt.get() == 0);
                    }
                }
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_MONGODBSTORE_HPP
