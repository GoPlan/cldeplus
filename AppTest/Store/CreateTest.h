//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_CPLUS_CREATETEST_H
#define CLOUD_E_CPLUS_CREATETEST_H

#include "gtest/gtest.h"
#include "StoreSimple.h"
#include "../../Architecture/Cloude.h"

using namespace std;
using namespace Cloude::AppTest::Store;
using namespace Cloude::Architecture::Foundation;

namespace Cloude {
    namespace AppTest {
        namespace EntityStore {

            TEST_F(StoreSimple, CreateEntity) {

                std::string codeName = "Code";
                std::string codeSourceName = "Code";
                std::string codeValue = "VNM";

                auto spColumnId = make_shared<Column>(codeName, codeSourceName, DbType::String);
                auto spFieldId = make_shared<Field>(spColumnId, codeValue);

                auto spIdentity = make_shared<Identity>()->SetField(spFieldId)
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
