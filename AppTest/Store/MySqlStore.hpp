//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_CPLUS_STORECREATETEST_H
#define CLOUD_E_CPLUS_STORECREATETEST_H

#include <Cloude.h>
#include <gtest/gtest.h>
#include <Application/Mapper/StockGroupMap.h>
#include <Application/Mapper/StockGroupLoader.h>
#include "../StockGroupMySqlStore.h"

using namespace std;

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Test {

                using Field = Cloude::Foundation::Field;
                using Identity = Cloude::Foundation::Identity;

                TEST_F(StockGroupMySqlStore, CreateGetSaveDelete) {

                    const char *code = "VNM";
                    const char *name = "Vinamilk";

                    auto spFieldCode = make_shared<Field>(StockGroupMap::Code);

                    auto spCodeValue = Foundation::Type::cldeValueFactory::CreateVarchar(code);
                    auto spNameValue = Foundation::Type::cldeValueFactory::CreateVarchar(name);

                    spFieldCode->setValue(spCodeValue);

                    auto initFieldList{spFieldCode};
                    auto spIdentity = std::make_shared<Identity>(initFieldList);

                    // CREATE
                    {
                        auto spEntity = _entityStore.Create(spIdentity);

                        ASSERT_TRUE(spEntity.get() != 0);
                        ASSERT_TRUE(_entityStore.HasIdentityInMap(spIdentity));
                    }

                    // SAVE
                    {
                        auto spEntity = _entityStore.Get(spIdentity);
                        auto &spCodeFieldAlt = spEntity->getField("Code");
                        auto &spNameFieldAlt = spEntity->operator[](StockGroupMap::UniqueName->getName());
                        auto &spCodeValueAlt = spCodeFieldAlt->getValue();

                        ASSERT_TRUE(strcmp(spCodeValueAlt->ToCString(), code) == 0);

                        spNameFieldAlt->setValue(spNameValue);
                        _entityStore.Save(spEntity);
                    }

                    // CLEAR
                    {
                        _entityStore.Clear();
                        ASSERT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
                        ASSERT_TRUE(_entityStore.Size() == 0);
                    }

                    // GET - Check for saved field
                    {
                        auto spEntity = _entityStore.Get(spIdentity);

                        EXPECT_TRUE(spEntity.get() != 0);
                        EXPECT_TRUE(_entityStore.Size() > 0);
                        EXPECT_TRUE(_entityStore.HasIdentityInMap(spIdentity));

                        auto &spCodeFieldAlt = spEntity->operator[](StockGroupMap::Code->getName());
                        auto &spNameFieldAlt = spEntity->operator[](StockGroupMap::UniqueName->getName());
                        auto &spCodeValueAlt = spCodeFieldAlt->getValue();
                        auto &spNameValueAlt = spNameFieldAlt->getValue();

                        EXPECT_TRUE(strncmp(code, spCodeValueAlt->ToCString(), spCodeValueAlt->getLength()) == 0);
                        EXPECT_TRUE(strncmp(name, spNameValueAlt->ToCString(), spNameValueAlt->getLength()) == 0);

                        _entityStore.Delete(spEntity);
                    }

                    // CLEAR
                    {
                        _entityStore.Clear();
                        EXPECT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
                        EXPECT_TRUE(_entityStore.Size() == 0);
                    }

                    // DELETE - Check if Entity is nullptr
                    {
                        auto spEntity = _entityStore.Get(spIdentity);
                        EXPECT_TRUE(spEntity.get() == 0);
                        EXPECT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
                    }
                }
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_STORECREATETEST_H
