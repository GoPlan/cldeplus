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

            TEST_F(StoreSimple, CreateEntity01_Shared_Pointer) {

                std::string codeName = "Code";
                std::string codeSourceName = "Code";
                std::string codeValue = "VNM";

                auto spColumnId = std::make_shared<Cloude::Architecture::Column>(codeName,
                                                                                 codeSourceName,
                                                                                 Cloude::Architecture::Enumeration::DbType::String);

                auto spFieldId = std::make_shared<Cloude::Architecture::Field>(spColumnId,
                                                                               codeValue);

                auto spIdentity = std::make_shared<Cloude::Architecture::Identity>()->SetField(spFieldId);
                ASSERT_TRUE(spIdentity.get() != 0);

                auto spIdentEntity = spIdentity->getSpEntity();
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

                auto spColumnId = std::make_shared<Cloude::Architecture::Column>(codeName,
                                                                                 codeSourceName,
                                                                                 Cloude::Architecture::Enumeration::DbType::String);

                auto ptrField = new Cloude::Architecture::Field(spColumnId, codeValue);
                auto spIdentity = std::make_shared<Cloude::Architecture::Identity>()->SetField(ptrField);
                ASSERT_TRUE(spIdentity.get() != 0);

                auto spIdentEntity = spIdentity->getSpEntity();
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

                const std::string codeName = "Code";
                const std::string codeValue = "VNM";

                const std::string nameName = "Name";
                const std::string nameValue = "Vinamilk";


                auto ptrFieldName = new Cloude::Architecture::Field(Cloude::Application::Mapper::StockGroupMap::Name,
                                                                    nameValue);

                auto ptrFieldCode = new Cloude::Architecture::Field(Cloude::Application::Mapper::StockGroupMap::Code,
                                                                    codeValue);

                auto ptrFieldsList = std::initializer_list<Cloude::Architecture::Field *>{ptrFieldName, ptrFieldCode};
                auto spIdentity = std::make_shared<Cloude::Architecture::Identity>()->SetField(ptrFieldsList);
                ASSERT_TRUE(spIdentity.get() != 0);

                auto spIdentEntity = spIdentity->getSpEntity();
                ASSERT_TRUE(spIdentEntity.get() != 0);

                auto spIdentEntityField = spIdentEntity->operator[](codeName);
                ASSERT_TRUE(spIdentEntityField.get() != 0);
                ASSERT_TRUE(codeValue.compare(spIdentEntityField->getString()) == 0);

                auto spEmptyEntity = _entityStore.Create();
                ASSERT_TRUE(spEmptyEntity.get() == 0);

                auto spEntity = _entityStore.Create(spIdentity);
                ASSERT_TRUE(spEntity.get() != 0);

                auto spNameField = spEntity->operator[](nameName);
                ASSERT_TRUE(nameValue.compare(spNameField->getString()) == 0);

                auto spCodeField = spEntity->operator[](codeName);
                ASSERT_TRUE(codeValue.compare(spCodeField->getString()) == 0);
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_STORECREATETEST_H
