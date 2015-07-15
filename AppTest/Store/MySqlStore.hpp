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

                    auto sptrNameValue = Foundation::Data::ValueFactory::CreateVarChar("ORDER-0");
                    auto sptrCustIdValue = Foundation::Data::ValueFactory::CreateInt64(0);

                    auto cells{sptrIdCell};
                    auto spIdentity = Foundation::CreateIdentity(cells);

                    // DELETE - Check if Entity is nullptr
                    {
                        auto sptrPreOrder = _storePreOrder.Get(spIdentity);
                        _storePreOrder.Delete(sptrPreOrder);
                        EXPECT_TRUE(sptrPreOrder.get() == 0);
                        EXPECT_TRUE(!_storePreOrder.HasIdentityInMap(spIdentity));
                    }

                    // CREATE
                    {
                        auto sptrPreOrder = _storePreOrder.Create(spIdentity);
                        EXPECT_TRUE(sptrPreOrder.get() != 0);
                        EXPECT_TRUE(_storePreOrder.HasIdentityInMap(spIdentity));
                    }

                    // SAVE
                    {
                        auto sptrEntity = _storePreOrder.Get(spIdentity);
                        auto &sptrNameCell = sptrEntity->getCell("Code");
                        auto &sptrNameValue = sptrNameCell->getValue();

                        EXPECT_TRUE(sptrNameValue->ToString().length() > 0);

                        sptrNameCell->setValue(sptrNameValue);
                        _storePreOrder.Save(sptrEntity);
                    }

                    // CLEAR
                    {
                        _storePreOrder.Clear();
                        EXPECT_TRUE(!_storePreOrder.HasIdentityInMap(spIdentity));
                        EXPECT_TRUE(_storePreOrder.Size() == 0);
                    }

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
                }
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE_H
