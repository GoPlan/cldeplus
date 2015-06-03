//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_CPLUS_STORECREATETEST_H
#define CLOUD_E_CPLUS_STORECREATETEST_H

#include <Cloude.h>
#include <gtest/gtest.h>
#include <Application/Mapper/StockGroupMap.h>
#include "StockGroupMySqlStore.h"
#include "StockGroupPostgreStore.h"

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

            TEST_F(StockGroupMySqlStore, CreateGetSaveDelete) {

                std::string codeValue("VNM");
                std::string nameValue("Vinamilk");

                auto spFieldCode = make_shared<Field>(StockGroupMap::Code);
                auto spFieldName = make_shared<Field>(StockGroupMap::UniqueName);

                spFieldCode->setCString(codeValue.c_str());
                spFieldName->setCString(nameValue.c_str());

                // SetMultiFields(initializer_list<shared_ptr<Field>>()
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
                    auto spNameField = spEntity->operator[](StockGroupMap::UniqueName->getName());

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
                    auto spCodeField = spEntity->operator[](StockGroupMap::Code->getName());
                    auto spNameField = spEntity->operator[](StockGroupMap::UniqueName->getName());
                    ASSERT_TRUE(_entityStore.Size() > 0);
                    ASSERT_TRUE(_entityStore.HasIdentityInMap(spIdentity) == true);
                    ASSERT_TRUE(strcmp(codeValue.c_str(), spCodeField->getCString()) == 0);
                    ASSERT_TRUE(strcmp(nameValue.c_str(), spNameField->getCString()) == 0);

                    _entityStore.Delete(spEntity);
                }

                // DELETE - Check if Entity is nullptr
                {
                    auto spEntity = _entityStore.Get(spIdentity);
                    ASSERT_TRUE(spEntity.get() == 0);
                }
            }

            TEST_F(StockGroupPostgreStore, CreateGetSaveDelete){

                std::string codeValue("VNM");
                std::string nameValue("Vinamilk");

                auto spFieldCode = make_shared<Field>(StockGroupMap::Code);
                auto spFieldName = make_shared<Field>(StockGroupMap::UniqueName);

                spFieldCode->setCString(codeValue.c_str());
                spFieldName->setCString(nameValue.c_str());

                // SetMultiFields(initializer_list<shared_ptr<Field>>()
                auto initFieldList{spFieldCode};
                auto spIdentity = std::make_shared<Identity>(initFieldList);

                // CREATE
                {
                    auto spEntity = _entityStore.Create(spIdentity);
                    ASSERT_TRUE(spEntity.get() != 0);
                    ASSERT_TRUE(_entityStore.HasIdentityInMap(spIdentity));
                }


            }
        }
    }
}

#endif //CLOUD_E_CPLUS_STORECREATETEST_H
