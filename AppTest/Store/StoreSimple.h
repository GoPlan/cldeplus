//
// Created by LE, Duc-Anh on 5/21/15.
//

#ifndef CLOUD_E_CPLUS_STORESIMPLE_H
#define CLOUD_E_CPLUS_STORESIMPLE_H

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
                StoreSimple() : _boundEntityStore(_stockGroupMap, _stockGroupLoader),
                                _entityStore(_stockGroupMap, _stockGroupLoader) { };

                virtual void SetUp();
                virtual void TearDown();

                Cloude::Application::Mapper::StockGroupMap _stockGroupMap;
                Cloude::Application::Mapper::StockGroupLoader _stockGroupLoader;
                Cloude::Architecture::EntityStore _entityStore;
                Cloude::Architecture::BoundEntityStore<Cloude::Application::Model::StockGroup> _boundEntityStore;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_STORESIMPLE_H
