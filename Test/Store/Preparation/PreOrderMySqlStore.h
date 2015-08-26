//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_PREORDERMYSQLSTORE_H
#define CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_PREORDERMYSQLSTORE_H

#include <gtest/gtest.h>
#include "../../Application/PreOrderMap.h"
#include "../../Application/PreOrderItemsMap.h"
#include "../../../Source/Foundation/EntityQuery.h"

namespace Cloude {
    namespace Test {
        namespace Store {

            class PreOrderMySqlStore : public ::testing::Test {

            protected:
                PreOrderMySqlStore();

                virtual void SetUp();
                virtual void TearDown();

                Application::SPtrPreOrderMap _sptrPreOrderMap;
                Application::SPtrPreOrderItemMap _sptrPreOrderItemsMap;
                Drivers::MySql::SPtrMySqlSourceDriver _sptrPreOrderDriver;
                Drivers::MySql::SPtrMySqlSourceDriver _sptrPreOrderItemsDriver;
                Foundation::SPtrEntityStore _sptrPreOrderStore;
                Foundation::SPtrEntityStore _sptrPreOrderItemsStore;
                Foundation::SPtrEntityQuery _sptrPreOrderQuery;
                Foundation::SPtrEntityQuery _sptrPreOrderItemsQuery;
            };
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_PREORDERMYSQLSTORE_H
