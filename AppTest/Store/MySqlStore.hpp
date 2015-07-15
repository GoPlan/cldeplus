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

                    Foundation::Data::Comparer::Compare compare{};

                    auto sptrIdValue = Foundation::Data::ValueFactory::CreateInt64(0);
                    auto sptrIdCell = Foundation::CreateCell(_mapPreOrder.Id, sptrIdValue);
                    auto sptrNameValue = Foundation::Data::ValueFactory::CreateVarChar("ORDER-0");
                    auto sptrCustIdValue = Foundation::Data::ValueFactory::CreateInt64(15);
                    auto sptrTotalValue = Foundation::Data::ValueFactory::CreateDouble(35);
                    auto cells{sptrIdCell};
                    auto sptrIdentity = Foundation::CreateIdentity(cells);

                    // DELETE - Check if Entity is nullptr
                    {
                        auto sptrPreOrder = _storePreOrder.Get(sptrIdentity);

                        EXPECT_TRUE(sptrPreOrder.get() != 0);
                        EXPECT_TRUE(_storePreOrder.HasIdentityInMap(sptrIdentity));

                        _storePreOrder.Delete(sptrPreOrder);
                        _storePreOrder.Clear();

                        EXPECT_TRUE(!_storePreOrder.HasIdentityInMap(sptrIdentity));
                        EXPECT_TRUE(_storePreOrder.Size() == 0);
                    }

                    // CREATE
                    {
                        auto sptrPreOrder = _storePreOrder.Create(sptrIdentity);

                        EXPECT_TRUE(sptrPreOrder.get() != 0);
                        EXPECT_TRUE(_storePreOrder.HasIdentityInMap(sptrIdentity));
                    }

                    // SAVE
                    {
                        auto sptrEntity = _storePreOrder.Get(sptrIdentity);
                        auto &sptrIdCell = sptrEntity->getCell("Id");
                        auto &sptrNameCell = sptrEntity->getCell("Name");
                        auto &sptrCustIdCell = sptrEntity->getCell("CustId");
                        auto &sptrTotalCell = sptrEntity->getCell("Total");

                        auto &sptrIdCellValue = sptrIdCell->getValue();

                        EXPECT_TRUE(sptrIdCellValue.get() != 0);

                        if (sptrIdCellValue) {
                            EXPECT_TRUE(compare(sptrIdCellValue, sptrIdValue));
                        }

                        sptrNameCell->setValue(sptrNameValue);
                        sptrCustIdCell->setValue(sptrCustIdValue);
                        sptrTotalCell->setValue(sptrTotalValue);

                        _storePreOrder.Save(sptrEntity);
                        _storePreOrder.Clear();
                    }

                    // GET - Check for saved field
                    {
                        auto sptrEntity = _storePreOrder.Get(sptrIdentity);

                        EXPECT_TRUE(sptrEntity.get() != 0);
                        EXPECT_TRUE(_storePreOrder.Size() > 0);
                        EXPECT_TRUE(_storePreOrder.HasIdentityInMap(sptrIdentity));

                        if (sptrEntity) {

                            auto &sptrNameCell = sptrEntity->getCell("Name");
                            auto &sptrCustIdCell = sptrEntity->getCell("CustId");
                            auto &sptrTotalCell = sptrEntity->getCell("Total");

                            EXPECT_TRUE(compare(sptrNameCell->getValue(), sptrNameValue));
                            EXPECT_TRUE(compare(sptrCustIdCell->getValue(), sptrCustIdValue));
                            EXPECT_TRUE(compare(sptrTotalCell->getValue(), sptrTotalValue));
                        }
                    }
                }

                TEST_F(PreOrderMySqlStore, Select) {

                    Foundation::Data::Comparer::Compare compare{};

                    using ValueFactory = Foundation::Data::ValueFactory;
                    using CmpFactory = Foundation::Query::ComparativeFactory;

                    // Values
                    auto sptrIdLo = ValueFactory::CreateInt64(2);
                    auto sptrIdHi = ValueFactory::CreateInt64(15);

                    // Criterias
                    auto gteLowId = CmpFactory::CreateGTE(_mapPreOrder.Id, sptrIdLo);
                    auto lteHiiId = CmpFactory::CreateLTE(_mapPreOrder.Id, sptrIdHi);
                    auto criteria = CmpFactory::CreateAND(gteLowId, lteHiiId);

                    // Execute
                    auto rsPreOrder = _queryPreOrder.Select(criteria);
                    auto &sptrFistPreOrder = *rsPreOrder.cbegin();
                    auto &sptrLastPreOrder = *(rsPreOrder.cbegin() + rsPreOrder.size() - 1);

                    EXPECT_TRUE(rsPreOrder.size() > 0);
                    EXPECT_TRUE(compare(sptrFistPreOrder->getCell("Id")->getValue(), sptrIdLo));
                    EXPECT_TRUE(compare(sptrLastPreOrder->getCell("Id")->getValue(), sptrIdHi));
                }
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE_H
