//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_CPLUS_APPTEST_STORE_STORESIMPLE_H
#define CLOUD_E_CPLUS_APPTEST_STORE_STORESIMPLE_H

#include "gtest/gtest.h"
#include "../../Cloude.h"
#include "../../Application/Mapper/StockGroupMap.h"
#include "../../Application/Mapper/StockGroupLoader.h"
#include "../../SourceDriver/MySql/MySqlSourceDriver.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {

            class StockGroupMySqlStore : public ::testing::Test {
            public:

            protected:
                using StockGroupLoader = Cloude::Application::Mapper::StockGroupLoader;
                using StockGroupMap = Cloude::Application::Mapper::StockGroupMap;
                using MySqlSourceDriver = Cloude::SourceDriver::MySql::MySqlSourceDriver;
                using EntityStore= Cloude::Foundation::EntityStore;

                StockGroupMySqlStore() : _mySqlDriver(_stockGroupMap),
                                         _entityStore(_stockGroupMap, _stockGroupLoader, _mySqlDriver) { };

                virtual void SetUp();
                virtual void TearDown();

                StockGroupLoader _stockGroupLoader;
                StockGroupMap _stockGroupMap;
                MySqlSourceDriver _mySqlDriver;
                EntityStore _entityStore;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_APPTEST_STORE_STORESIMPLE_H
