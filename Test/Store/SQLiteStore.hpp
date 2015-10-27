//
// Created by LE, Duc Anh on 6/8/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_SQLITESTORE_HPP
#define CLOUD_E_PLUS_APPTEST_STORE_SQLITESTORE_HPP

#include <gtest/gtest.h>
#include "Preparation/ProductSQLiteStore.h"

namespace Cloude {
    namespace Test {
        namespace Store {

            using Cell = Cloude::Foundation::Cell;
            using Identity = Cloude::Foundation::Identity;
            using ProductSQLiteStore = Preparation::ProductSQLiteStore;

            TEST_F(ProductSQLiteStore, CreateGetSaveDelete) {

                std::string name{"Example Product 00"};
                std::string code{"PROD00"};

                auto sptrIdValue = Foundation::Data::ValueFactory::CreateInt64(0);
                auto sptrNameValue = Foundation::Data::ValueFactory::CreateVarChar(name);
                auto sptrCodeValue = Foundation::Data::ValueFactory::CreateVarChar(code);
                auto sptrPriceValue = Foundation::Data::ValueFactory::CreateDouble(18);

                auto sptrIdCell = (Foundation::SPtrCell) Foundation::Cell::Create(_sptrProductMap->GetColumn("Id"));
                sptrIdCell->setValue(sptrIdValue);

                auto initFieldList = {sptrIdCell};
                auto sptrIdentity = (Foundation::SPtrIdentity) Foundation::Identity::Create(initFieldList);

                // TRUNCATE EXAMPLE DATA
                {
                    auto sptrProduct = _sptrProductStore->Get(sptrIdentity);

                    if (sptrProduct.get() != 0) {

                        _sptrProductStore->Delete(sptrProduct);
                        EXPECT_TRUE(!_sptrProductStore->HasIdentityInMap(sptrIdentity));

                        auto sptrProductAlt = _sptrProductStore->Get(sptrIdentity);
                        EXPECT_TRUE(sptrProductAlt.get() == 0);
                    }
                }

                // CREATE
                {
                    auto sptrProduct = _sptrProductStore->Create(sptrIdentity);
                    EXPECT_TRUE(sptrProduct.get() != 0);
                    EXPECT_TRUE(_sptrProductStore->HasIdentityInMap(sptrIdentity));

                    _sptrProductStore->Clear();
                }

                // GET & SAVE
                {
                    auto sptrProduct = _sptrProductStore->Get(sptrIdentity);
                    EXPECT_TRUE(sptrProduct.get() != 0);
                    EXPECT_TRUE(_sptrProductStore->HasIdentityInMap(sptrIdentity));

                    auto &sptrNameCell = sptrProduct->getCell("Name");
                    auto &sptrCodeCell = sptrProduct->getCell("Code");
                    auto &sptrPriceCell = sptrProduct->getCell("Price");
                    EXPECT_TRUE(sptrNameCell.get() != 0);
                    EXPECT_TRUE(sptrCodeCell.get() != 0);
                    EXPECT_TRUE(sptrPriceCell.get() != 0);

                    sptrNameCell->setValue(sptrNameValue);
                    sptrCodeCell->setValue(sptrCodeValue);
                    sptrPriceCell->setValue(sptrPriceValue);

                    _sptrProductStore->Save(sptrProduct);
                    _sptrProductStore->Clear();

                    EXPECT_TRUE(!_sptrProductStore->HasIdentityInMap(sptrIdentity));
                    EXPECT_TRUE(_sptrProductStore->Size() == 0);
                }

//                // DELETE
//                {
//                    auto sptrEntity = _entityStore.Get(spIdentity);
//                    EXPECT_TRUE(sptrEntity.get() != 0);
//                    EXPECT_TRUE(_entityStore.HasIdentityInMap(spIdentity));
//
//                    auto &sptrEmailField = sptrEntity->getCell("Email");
//                    auto &sptrEmailValue = sptrEmailField->getValue();
//                    EXPECT_TRUE(strcmp(name.c_str(), sptrEmailValue->ToString().c_str()) == 0);
//
//                    _entityStore.Delete(sptrEntity);
//                    EXPECT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
//                    EXPECT_TRUE(_entityStore.Size() == 0);
//
//                    auto spEntityAlt = _entityStore.Get(spIdentity);
//                    EXPECT_TRUE(spEntityAlt.get() == 0);
//                }
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_STORE_SQLITESTORE_HPP
