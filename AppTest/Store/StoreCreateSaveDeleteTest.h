//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_CPLUS_STORECREATETEST_H
#define CLOUD_E_CPLUS_STORECREATETEST_H

#include "gtest/gtest.h"
#include "StoreSimple.h"
#include "Application/Mapper/StockGroupMap.h"
#include "../../Cloude.h"

using namespace std;

namespace Cloude {
    namespace AppTest {
        namespace Store {

            using Column = Cloude::Architecture::Column;
            using Field = Cloude::Architecture::Field;
            using Identity = Cloude::Architecture::Identity;
            using EnumDbType = Cloude::Architecture::Enumeration::DbType;

            using StockGroupMap = Cloude::Application::Mapper::StockGroupMap;
            using StockGroupLoader = Cloude::Application::Mapper::StockGroupLoader;

            TEST_F(StoreSimple, CreateEntity01) {

                std::string codeValue("VNM");
                std::string nameValue("Vinamilk");

                auto spField = std::make_shared<Field>(_stockGroupMap.Code);
                auto spIdentity = std::make_shared<Identity>()->SetField(spField);
                ASSERT_TRUE(spIdentity.get() != 0);

                spField->setCString(codeValue.c_str());

                auto spIdentEntity = spIdentity->getEntity();
                ASSERT_TRUE(spIdentEntity.get() != 0);

                auto spIdentEntityField = spIdentEntity->operator[](_stockGroupMap.Code->getName());
                ASSERT_TRUE(spIdentEntityField.get() != 0);
                ASSERT_TRUE(codeValue.compare(spIdentEntityField->getCString()) == 0);

                // CREATE
                auto spEntity = _entityStore.Create(spIdentity);
                auto spNameField = spEntity->operator[](_stockGroupMap.UniqueName->getName());
                spNameField->setCString(nameValue.c_str());

                // SAVE
                _entityStore.Save(spEntity);

                // GET
                auto spEntityAlt = _entityStore.Get(spIdentity);
                auto spFieldCodeAlt = spEntityAlt->operator[](_stockGroupMap.Code->getName());
                auto spFieldNameAlt = spEntityAlt->operator[](_stockGroupMap.UniqueName->getName());
                ASSERT_TRUE(strcmp(spFieldCodeAlt->getCString(), codeValue.c_str()) == 0);
                ASSERT_TRUE(strcmp(spFieldNameAlt->getCString(), nameValue.c_str()) == 0);

                _entityStore.Delete(spEntity);
            }

            TEST_F(StoreSimple, CreateEntity02_InitializerList) {

                std::string codeValue("VNM");
                std::string nameValue("Vinamilk");

                auto spFieldCode = make_shared<Field>(StockGroupMap::Code);
                auto spFieldName = make_shared<Field>(StockGroupMap::UniqueName);

                spFieldCode->setCString(codeValue.c_str());
                spFieldName->setCString(nameValue.c_str());

                // SetField(initializer_list<shared_ptr<Field>>()
                std::initializer_list<std::shared_ptr<Field>> initFieldList{spFieldCode};
                auto spIdentity = std::make_shared<Identity>()->SetField(initFieldList);
                ASSERT_TRUE(spIdentity.get() != 0);

                auto spIdentEntity = spIdentity->getEntity();
                ASSERT_TRUE(spIdentEntity.get() != 0);

                auto spIdentEntityField = spIdentEntity->operator[](StockGroupMap::Code->getName());
                ASSERT_TRUE(spIdentEntityField.get() != 0);
                ASSERT_TRUE(strcmp(codeValue.c_str(), spIdentEntityField->getCString()) == 0);

                // CREATE
                auto spEntity = _entityStore.Create(spIdentity);
                ASSERT_TRUE(spEntity.get() != 0);
                ASSERT_TRUE(_entityStore.HasIdentityInMap(spIdentity));

                // GET - SAVE
                {
                    auto spEntityAlt = _entityStore.Get(spIdentity);
                    ASSERT_TRUE(spEntityAlt.get() != 0);
                    ASSERT_TRUE(spIdentEntity == spEntity);
                    ASSERT_TRUE(spEntity == spEntityAlt);

                    auto spNameFieldAlt = spEntityAlt->operator[](StockGroupMap::UniqueName->getName());
                    spNameFieldAlt->setCString(nameValue.c_str());

                    // SAVE
                    _entityStore.Save(spEntityAlt);
                }

                // CLEAR
                {
                    _entityStore.Clear();
                    ASSERT_TRUE(_entityStore.HasIdentityInMap(spIdentity) == false);
                    ASSERT_TRUE(_entityStore.Size() == 0);
                }

                // GET - Check for saved field
                {
                    auto spEntityAlt = _entityStore.Get(spIdentity);
                    auto spCodeField = spEntityAlt->operator[](StockGroupMap::Code->getName());
                    auto spNameField = spEntityAlt->operator[](StockGroupMap::UniqueName->getName());
                    ASSERT_TRUE(_entityStore.Size() > 0);
                    ASSERT_TRUE(_entityStore.HasIdentityInMap(spIdentity) == true);
                    ASSERT_TRUE(strncmp(codeValue.c_str(), spCodeField->getCString(), 3) == 0);
                    ASSERT_TRUE(strncmp(nameValue.c_str(), spNameField->getCString(), 3) == 0);

                    _entityStore.Delete(spEntityAlt);
                }

                // DELETE - Check if Entity is nullptr
                {


                }
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_STORECREATETEST_H
