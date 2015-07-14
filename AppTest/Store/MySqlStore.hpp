//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE_H
#define CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE_H

#include <gtest/gtest.h>
#include <Foundation/Foundation.h>
#include <AppTest/Store/Preparation/PreOrderMySqlStore.h>

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Test {

                using Cell = Cloude::Foundation::Cell;
                using Identity = Cloude::Foundation::Identity;

                TEST_F(PreOrderMySqlStore, CreateGetSaveDelete) {

                    auto sptrIdValue = Foundation::Data::ValueFactory::CreateInt64(0);
                    auto sptrIdCell = Foundation::CreateCell(_mapPreOrder.Id, sptrIdValue);

                    auto cells{sptrIdCell};
                    auto spIdentity = Foundation::CreateIdentity(cells);

//                    // CREATE
//                    {
//                        auto spEntity = _entityStore.Create(spIdentity);
//
//                        EXPECT_TRUE(spEntity.get() != 0);
//                        EXPECT_TRUE(_entityStore.HasIdentityInMap(spIdentity));
//                    }

//                    // SAVE
//                    {
//                        auto spEntity = _entityStore.Get(spIdentity);
//                        auto &spCodeFieldAlt = spEntity->getField("Code");
//                        auto &spNameFieldAlt = spEntity->operator[](StockGroupMap::UniqueName->getName());
//                        auto &spCodeValueAlt = spCodeFieldAlt->getValue();
//
//                        EXPECT_TRUE(strcmp(spCodeValueAlt->ToCString(), code) == 0);
//
//                        spNameFieldAlt->setValue(spNameValue);
//                        _entityStore.Save(spEntity);
//                    }

//                    // CLEAR
//                    {
//                        _entityStore.Clear();
//                        ASSERT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
//                        ASSERT_TRUE(_entityStore.Size() == 0);
//                    }

//                    // GET - Check for saved field
//                    {
//                        auto spEntity = _entityStore.Get(spIdentity);
//
//                        EXPECT_TRUE(spEntity.get() != 0);
//                        EXPECT_TRUE(_entityStore.Size() > 0);
//                        EXPECT_TRUE(_entityStore.HasIdentityInMap(spIdentity));
//
//                        auto &spCodeFieldAlt = spEntity->operator[](StockGroupMap::Code->getName());
//                        auto &spNameFieldAlt = spEntity->operator[](StockGroupMap::UniqueName->getName());
//                        auto &spCodeValueAlt = spCodeFieldAlt->getValue();
//                        auto &spNameValueAlt = spNameFieldAlt->getValue();
//
//                        EXPECT_TRUE(strncmp(code, spCodeValueAlt->ToCString(), spCodeValueAlt->getLength()) == 0);
//                        EXPECT_TRUE(strncmp(name, spNameValueAlt->ToCString(), spNameValueAlt->getLength()) == 0);
//
//                        _entityStore.Delete(spEntity);
//                    }

//                    // CLEAR
//                    {
//                        _entityStore.Clear();
//                        EXPECT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
//                        EXPECT_TRUE(_entityStore.Size() == 0);
//                    }

//                    // DELETE - Check if Entity is nullptr
//                    {
//                        auto spEntity = _entityStore.Get(spIdentity);
//                        EXPECT_TRUE(spEntity.get() == 0);
//                        EXPECT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
//                    }
                }
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE_H
