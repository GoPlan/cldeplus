//
// Created by LE, Duc Anh on 6/8/15.
//

#ifndef CLOUD_E_CPLUS_APPTEST_STORE_SQLITESTORE_HPP
#define CLOUD_E_CPLUS_APPTEST_STORE_SQLITESTORE_HPP

#include "gtest/gtest.h"
#include "Preparation/EnquirySQLiteStore.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {

            using Field = Cloude::Foundation::Cell;
            using Identity = Cloude::Foundation::Identity;
            using EnquirySQLiteStorePreparation = Preparation::EnquirySQLiteStore;

            TEST_F(EnquirySQLiteStorePreparation, CreateGetSaveDelete) {

                std::string email{"goplan@cloud-e.biz"};

                auto spEnquiryId = Foundation::Data::ValueFactory::CreateInt64(15);
                auto spEnquiryEmail = Foundation::Data::ValueFactory::CreateVarChar(email);

                auto spEnquiryIdField = std::make_shared<Field>(_enquiryMap.EnquiryId);
                spEnquiryIdField->setValue(spEnquiryId);

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

                    auto &spEmailField = spEntity->getCell("Email");
                    ASSERT_TRUE(spEmailField.get() != 0);

                    spEmailField->setValue(spEnquiryEmail);

                    _entityStore.Save(spEntity);
                    _entityStore.Clear();

                    ASSERT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
                    ASSERT_TRUE(_entityStore.Size() == 0);
                }

                // DELETE
                {
                    auto sptrEntity = _entityStore.Get(spIdentity);
                    ASSERT_TRUE(sptrEntity.get() != 0);
                    ASSERT_TRUE(_entityStore.HasIdentityInMap(spIdentity));

                    auto &sptrEmailField = sptrEntity->getCell("Email");
                    auto &sptrEmailValue = sptrEmailField->getValue();
                    EXPECT_TRUE(strcmp(email.c_str(), sptrEmailValue->ToString().c_str()) == 0);

                    _entityStore.Delete(sptrEntity);
                    EXPECT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
                    EXPECT_TRUE(_entityStore.Size() == 0);

                    auto spEntityAlt = _entityStore.Get(spIdentity);
                    EXPECT_TRUE(spEntityAlt.get() == 0);
                }
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_APPTEST_STORE_SQLITESTORE_HPP
