//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_CPLUS_STORESIMPLE_H
#define CLOUD_E_CPLUS_STORESIMPLE_H

#include "gtest/gtest.h"
#include "../../Architecture/cloude.h"
#include "../../Application/Model/StockGroup.h"
#include "../../Application/Mapper/StockGroupLoader.h"
#include "../../Application/Mapper/StockGroupMap.h"

using namespace Cloude::Application::Model;
using namespace Cloude::Application::Mapper;
using namespace Cloude::Architecture::Foundation;

namespace Cloude {
    namespace AppTest {
        namespace Store {

            class StoreSimple : public ::testing::Test {
            public:

            protected:
                StoreSimple() : _entityStore(_stockGroupMap, _stockGroupLoader) { };

                virtual void SetUp();
                virtual void TearDown();

                StockGroupMap _stockGroupMap;
                StockGroupLoader _stockGroupLoader;
                EntityStore<StockGroup> _entityStore;
            };

        }
    }
}

#endif //CLOUD_E_CPLUS_STORESIMPLE_H
