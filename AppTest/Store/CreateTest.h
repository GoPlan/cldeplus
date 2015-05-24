//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_CPLUS_CREATETEST_H
#define CLOUD_E_CPLUS_CREATETEST_H

#include "gtest/gtest.h"
#include "StoreSimple.h"
#include "../../Cloude.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {

            TEST_F(StoreSimple, CreateEntity) {

                std::string codeName = "Code";
                std::string codeSourceName = "Code";
                std::string codeValue = "VNM";

                auto spColumnId = std::make_shared<Cloude::Architecture::Column>(codeName,
                                                                                 codeSourceName,
                                                                                 Cloude::Architecture::Enumeration::DbType::String);

                auto spFieldId = std::make_shared<Cloude::Architecture::Field>(spColumnId, codeValue);

                auto spIdentity = std::make_shared<Cloude::Architecture::Identity>()->SetField(spFieldId)
                                                                                    ->SetField(spFieldId);

                ASSERT_TRUE(spIdentity.get() != 0);

                auto spIdentEntity = spIdentity->getSpEntity();
                ASSERT_TRUE(spIdentEntity.get() != 0);

                auto spEmptyEntity = _entityStore.Create();
                ASSERT_TRUE(spEmptyEntity.get() == 0);

                auto spEntity = _entityStore.Create(spIdentity);
                ASSERT_TRUE(spEntity.get() != 0);
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_CREATETEST_H
