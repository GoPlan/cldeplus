//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_CPLUS_STORESIMPLE_H
#define CLOUD_E_CPLUS_STORESIMPLE_H

#include <Infrastructure/MySqlDriver.h>
#include "gtest/gtest.h"
#include "../../Cloude.h"
#include "../../Application/Model/StockGroup.h"
#include "../../Application/Mapper/StockGroupLoader.h"
#include "../../Application/Mapper/StockGroupMap.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {

            class StoreSimple : public ::testing::Test {
            public:

            protected:
                StoreSimple() : _stockGroupLoader(_stockGroupMap.getColumnsMap()),
                                _entityStore(_stockGroupMap, _stockGroupLoader, _mySqlDriver) { };

                virtual void SetUp();
                virtual void TearDown();

                Cloude::Infrastructure::MySqlDriver _mySqlDriver;
                Cloude::Application::Mapper::StockGroupMap _stockGroupMap;
                Cloude::Application::Mapper::StockGroupLoader _stockGroupLoader;
                Cloude::Architecture::EntityStore _entityStore;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_STORESIMPLE_H
