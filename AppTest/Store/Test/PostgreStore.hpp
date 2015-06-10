//
// Created by LE, Duc Anh on 6/6/15.
//

#ifndef CLOUD_E_CPLUS_POSTGRESTORE_HPP
#define CLOUD_E_CPLUS_POSTGRESTORE_HPP

#include <Cloude.h>
#include <gtest/gtest.h>
#include <Application/Mapper/StockGroupMap.h>
#include <Application/Mapper/StockGroupLoader.h>
#include "../StockGroupPostgreStore.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Test {

                using Field = Cloude::Foundation::Field;
                using Identity = Cloude::Foundation::Identity;

                TEST_F(StockGroupPostgreStore, CreateGetSaveDelete) {

                    const char *code = "VNM";
                    const char *name = "Vinamilk";

                    auto spCodeField = make_shared<Field>(StockGroupMap::Code);

                    auto spCodeValue = Foundation::Data::cldeValueFactory::CreateString(code);
                    auto spNameValue = Foundation::Data::cldeValueFactory::CreateString(name);

                    spCodeField->setValue(spCodeValue);

                    // setMultiFields(initializer_list<shared_ptr<Field>>()
                    auto initFieldList{spCodeField};
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
                        ASSERT_TRUE(spEntity.get() != 0);

                        auto spNameField = spEntity->operator[]("UniqueName");
                        ASSERT_TRUE(spNameField.get() != 0);

                        spNameField->setValue(spNameValue);

                        _entityStore.Save(spEntity);
                    }

                    // CLEAR
                    {
                        _entityStore.Clear();
                        ASSERT_TRUE(!_entityStore.HasIdentityInMap(spIdentity));
                        ASSERT_TRUE(_entityStore.Size() == 0);
                    }

                    // GET & DELETE - Check for saved field
                    {
                        auto spEntity = _entityStore.Get(spIdentity);
                        ASSERT_TRUE(spEntity.get() != 0);

                        auto &spCodeFieldAlt = spEntity->operator[](StockGroupMap::Code->getName());
                        auto &spNameFieldAlt = spEntity->operator[](StockGroupMap::UniqueName->getName());

                        auto &spCodeValue = spCodeFieldAlt->getValue();
                        auto &spNameValue = spNameFieldAlt->getValue();

                        EXPECT_TRUE(_entityStore.Size() > 0);
                        EXPECT_TRUE(_entityStore.HasIdentityInMap(spIdentity));

                        EXPECT_TRUE(strcmp(code, spCodeValue->ToString().c_str()) == 0);
                        EXPECT_TRUE(strcmp(name, spNameValue->ToString().c_str()) == 0);

                        _entityStore.Delete(spEntity);
                    }

                    // Check deleted
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

#endif //CLOUD_E_CPLUS_POSTGRESTORE_HPP
