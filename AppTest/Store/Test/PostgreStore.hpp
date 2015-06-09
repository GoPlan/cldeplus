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

                    std::string codeValue("VNM");
                    std::string nameValue("Vinamilk");

                    auto spCodeField = make_shared<Field>(StockGroupMap::Code);
                    spCodeField->setCString(codeValue.c_str());

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

                        spNameField->setCString(nameValue.c_str());

                        _entityStore.Save(spEntity);
                    }

                    // CLEAR
                    {
                        _entityStore.Clear();
                        ASSERT_TRUE(_entityStore.HasIdentityInMap(spIdentity) == false);
                        ASSERT_TRUE(_entityStore.Size() == 0);
                    }

                    // GET - Check for saved field
                    {
                        auto spEntity = _entityStore.Get(spIdentity);
                        ASSERT_TRUE(spEntity.get() != 0);

                        auto spCodeFieldAlt = spEntity->operator[](StockGroupMap::Code->getName());
                        auto spNameFieldAlt = spEntity->operator[](StockGroupMap::UniqueName->getName());

                        EXPECT_TRUE(_entityStore.Size() > 0);
                        EXPECT_TRUE(_entityStore.HasIdentityInMap(spIdentity) == true);

                        EXPECT_TRUE(strcmp(codeValue.c_str(), spCodeFieldAlt->getCString()) == 0);

                        // TODO: Investigate ERROR: invalid byte sequence for encoding "UTF8": 0xf0 0xfa 0x9f 0x7f
                        EXPECT_TRUE(strcmp(nameValue.c_str(), spNameFieldAlt->getCString()) == 0);

                        _entityStore.Delete(spEntity);
                    }
                }
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_POSTGRESTORE_HPP
