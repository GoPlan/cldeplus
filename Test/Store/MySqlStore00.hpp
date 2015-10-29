//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLDEPLUS_APPTEST_STORE_MYSQLSTORE00_HPP
#define CLDEPLUS_APPTEST_STORE_MYSQLSTORE00_HPP

#include <gtest/gtest.h>
#include "../../Source/Foundation/Foundation.h"
#include "../Store/Preparation/PreOrderMySqlStore.h"

namespace CLDEPlus {
    namespace Test {
        namespace Store {
            namespace Test {

                using Cell = CLDEPlus::Foundation::Cell;
                using Identity = CLDEPlus::Foundation::Identity;

                TEST_F(PreOrderMySqlStore, CreateGetSaveDelete00) {

                    Foundation::Data::Comparer::Compare compare{};

                    auto sptrIdValue = Foundation::Data::ValueFactory::CreateInt64(0);
                    auto sptrIdCell = (Foundation::SPtrCell)Foundation::Cell::Create(_sptrPreOrderMap->GetColumn("Id"), sptrIdValue);
                    auto sptrNameValue = Foundation::Data::ValueFactory::CreateVarChar("ORDER-0");
                    auto sptrCustIdValue = Foundation::Data::ValueFactory::CreateInt64(15);
                    auto sptrTotalValue = Foundation::Data::ValueFactory::CreateDouble(35);
                    auto sptrIdentity = (Foundation::SPtrIdentity)Foundation::Identity::Create({sptrIdCell});

                    // DELETE - Check if Entity is nullptr
                    {
                        auto sptrPreOrder = _sptrPreOrderStore->Get(sptrIdentity);

                        EXPECT_TRUE(sptrPreOrder.get() != 0);
                        EXPECT_TRUE(_sptrPreOrderStore->HasIdentityInMap(sptrIdentity));

                        _sptrPreOrderStore->Delete(sptrPreOrder);
                        _sptrPreOrderStore->Clear();

                        EXPECT_TRUE(!_sptrPreOrderStore->HasIdentityInMap(sptrIdentity));
                        EXPECT_TRUE(_sptrPreOrderStore->Size() == 0);
                    }

                    // CREATE
                    {
                        auto sptrPreOrder = _sptrPreOrderStore->Create(sptrIdentity);
                        EXPECT_TRUE(sptrPreOrder.get() != 0);
                        EXPECT_TRUE(_sptrPreOrderStore->HasIdentityInMap(sptrIdentity));
                    }

                    // SAVE
                    {
                        auto sptrEntity = _sptrPreOrderStore->Get(sptrIdentity);
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

                        _sptrPreOrderStore->Save(sptrEntity);
                        _sptrPreOrderStore->Clear();
                    }

                    // GET - Check for saved field
                    {
                        auto sptrEntity = _sptrPreOrderStore->Get(sptrIdentity);

                        EXPECT_TRUE(sptrEntity.get() != 0);
                        EXPECT_TRUE(_sptrPreOrderStore->Size() > 0);
                        EXPECT_TRUE(_sptrPreOrderStore->HasIdentityInMap(sptrIdentity));

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
                    auto gteLoId = CmpFactory::CreateGTE(_sptrPreOrderMap->GetColumn("Id"), sptrIdLo);
                    auto lteHiId = CmpFactory::CreateLTE(_sptrPreOrderMap->GetColumn("Id"), sptrIdHi);
                    auto criteria = CmpFactory::CreateAND(gteLoId, lteHiId);

                    // Execute
                    auto rsPreOrder = _sptrPreOrderQuery->Select(criteria);
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

#endif //CLDEPLUS_APPTEST_STORE_MYSQLSTORE00_HPP
