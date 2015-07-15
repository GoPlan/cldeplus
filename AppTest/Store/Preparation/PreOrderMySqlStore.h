//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_PREORDERMYSQLSTORE_H
#define CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_PREORDERMYSQLSTORE_H

#include "gtest/gtest.h"
#include <Foundation/Foundation.h>
#include <Drivers/MySql/MySqlSourceDriver.h>
#include <AppTest/Application/EnquiryMap.h>
#include <AppTest/Application/PreOrderMap.h>
#include <AppTest/Application/PreOrderItemsMap.h>

namespace Cloude {
    namespace AppTest {
        namespace Store {

            class PreOrderMySqlStore : public ::testing::Test {

            public:

            protected:
                using PreOrderMap = AppTest::Application::PreOrderMap;
                using PreOrderItemsMap = AppTest::Application::PreOrderItemsMap;
                using MySqlSourceDriver = Drivers::MySql::MySqlSourceDriver;
                using EntityStore = Foundation::EntityStore;
                using EntityQuery = Foundation::EntityQuery;

                PreOrderMySqlStore() : _driverPreOrder{_mapPreOrder},
                                       _driverPreOrderItems{_mapPreOrderItems},
                                       _storePreOrder{_mapPreOrder, _driverPreOrder},
                                       _storePreOrderItems{_mapPreOrderItems, _driverPreOrderItems},
                                       _queryPreOrder{_mapPreOrder, _driverPreOrder},
                                       _queryPreOrderItems{_mapPreOrderItems, _driverPreOrderItems} {
                    //
                };

                virtual void SetUp();
                virtual void TearDown();

                PreOrderMap _mapPreOrder;
                PreOrderItemsMap _mapPreOrderItems;
                MySqlSourceDriver _driverPreOrder;
                MySqlSourceDriver _driverPreOrderItems;
                EntityStore _storePreOrder;
                EntityStore _storePreOrderItems;
                EntityQuery _queryPreOrder;
                EntityQuery _queryPreOrderItems;
            };
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_PREORDERMYSQLSTORE_H
