//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_CPLUS_STORESIMPLE_H
#define CLOUD_E_CPLUS_STORESIMPLE_H

#include "gtest/gtest.h"
#include "../../Cloude.h"
#include "../../Application/Mapper/StockGroupMap.h"
#include "../../Application/Mapper/StockGroupLoader.h"
#include "../../Infrastructure/MySql/MySqlSourceDriver.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {

            class StockGroupMySqlStore : public ::testing::Test {
            public:

            protected:
                StockGroupMySqlStore() : _mySqlDriver(_stockGroupMap),
                                         _entityStore(_stockGroupMap, _stockGroupLoader, _mySqlDriver) { };

                virtual void SetUp();
                virtual void TearDown();

                Cloude::Application::Mapper::StockGroupLoader _stockGroupLoader;
                Cloude::Application::Mapper::StockGroupMap _stockGroupMap;
                Cloude::Infrastructure::MySql::MySqlSourceDriver _mySqlDriver;
                Cloude::Architecture::EntityStore _entityStore;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_STORESIMPLE_H
