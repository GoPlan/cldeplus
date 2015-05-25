//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_CPLUS_STORECREATETEST_H
#define CLOUD_E_CPLUS_STORECREATETEST_H

#include "gtest/gtest.h"
#include "StoreSimple.h"
#include "Application/Mapper/StockGroupMap.h"
#include "../../Cloude.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {

            using Column = Cloude::Architecture::Column;
            using Field = Cloude::Architecture::Field;
            using Identity = Cloude::Architecture::Identity;
            using EnumDbType = Cloude::Architecture::Enumeration::DbType;

            using StockGroupMap = Cloude::Application::Mapper::StockGroupMap;
            using StockGroupLoader = Cloude::Application::Mapper::StockGroupLoader;

            TEST_F(StoreSimple, CreateEntity01_Shared_Pointer) {

                std::string codeName = "Code";
                std::string codeSourceName = "Code";
                std::string codeValue = "VNM";

                auto spColumnId = std::make_shared<Column>(codeName, codeSourceName, EnumDbType::String);
                auto spFieldId = std::make_shared<Field>(spColumnId, codeValue);

                auto spIdentity = std::make_shared<Identity>()->SetField(spFieldId);
                ASSERT_TRUE(spIdentity.get() != 0);

                auto spIdentEntity = spIdentity->getEntity();
                ASSERT_TRUE(spIdentEntity.get() != 0);

                auto spIdentEntityField = spIdentEntity->operator[](codeName);
                ASSERT_TRUE(spIdentEntityField.get() != 0);
                ASSERT_TRUE(codeValue.compare(spIdentEntityField->getString()) == 0);

                auto spEmptyEntity = _entityStore.Create();
                ASSERT_TRUE(spEmptyEntity.get() == 0);

                auto spEntity = _entityStore.Create(spIdentity);
                ASSERT_TRUE(spEntity.get() != 0);

                auto spField = spEntity->operator[](codeName);
                ASSERT_TRUE(codeValue.compare(spField->getString()) == 0);
            }

            TEST_F(StoreSimple, CreateEntity02_Pointer) {

                std::string codeName = "Code";
                std::string codeSourceName = "Code";
                std::string codeValue = "VNM";

                auto spColumnId = std::make_shared<Column>(codeName, codeSourceName, EnumDbType::String);
                auto ptrField = new Field(spColumnId, codeValue);
                auto spIdentity = std::make_shared<Identity>()->SetField(ptrField);
                ASSERT_TRUE(spIdentity.get() != 0);

                auto spIdentEntity = spIdentity->getEntity();
                ASSERT_TRUE(spIdentEntity.get() != 0);

                auto spIdentEntityField = spIdentEntity->operator[](codeName);
                ASSERT_TRUE(spIdentEntityField.get() != 0);
                ASSERT_TRUE(codeValue.compare(spIdentEntityField->getString()) == 0);

                auto spEmptyEntity = _entityStore.Create();
                ASSERT_TRUE(spEmptyEntity.get() == 0);

                auto spEntity = _entityStore.Create(spIdentity);
                ASSERT_TRUE(spEntity.get() != 0);

                auto spField = spEntity->operator[](codeName);
                ASSERT_TRUE(codeValue.compare(spField->getString()) == 0);
            }

            TEST_F(StoreSimple, CreateEntity03_InitializerList) {

                const std::string idName = "Id";
                const long idValue = 1000;

                const std::string codeName = "Code";
                const std::string codeValue = "VNM";

                const std::string nameName = "Name";
                const std::string nameValue = "Vinamilk";

                auto ptrFieldId = new Field(StockGroupMap::Id, idValue);
                auto ptrFieldName = new Field(StockGroupMap::Name, nameValue);
                auto ptrFieldCode = new Field(StockGroupMap::Code, codeValue);

                auto initFieldList{ptrFieldId, ptrFieldName, ptrFieldCode};
                auto spIdentity = std::make_shared<Identity>()->SetField(initFieldList);
                ASSERT_TRUE(spIdentity.get() != 0);

                auto spIdentEntity = spIdentity->getEntity();
                ASSERT_TRUE(spIdentEntity.get() != 0);

                auto spIdentEntityField = spIdentEntity->operator[](codeName);
                ASSERT_TRUE(spIdentEntityField.get() != 0);
                ASSERT_TRUE(codeValue.compare(spIdentEntityField->getString()) == 0);

                auto spEmptyEntity = _entityStore.Create();
                ASSERT_TRUE(spEmptyEntity.get() == 0);

                auto spEntity = _entityStore.Create(spIdentity);
                ASSERT_TRUE(spEntity.get() != 0);
                ASSERT_TRUE(_entityStore.HasIdentityInMap(spIdentity));

                auto spEntityAlt = _entityStore.Get(spIdentity);
                ASSERT_TRUE(spEntity.get() != 0);
                ASSERT_TRUE(spIdentEntity == spEntity);
                ASSERT_TRUE(spEntity == spEntityAlt);

                auto spIdField = spEntity->operator[](idName);
                ASSERT_TRUE(spIdField->getInt64() == 1000);

                auto spNameField = spEntity->operator[](nameName);
                ASSERT_TRUE(nameValue.compare(spNameField->getString()) == 0);

                auto spCodeField = spEntity->operator[](codeName);
                ASSERT_TRUE(codeValue.compare(spCodeField->getString()) == 0);
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_STORECREATETEST_H
