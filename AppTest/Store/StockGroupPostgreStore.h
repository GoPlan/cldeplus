//
// Created by LE, Duc Anh on 6/3/15.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPPOSTGRESTORE_H
#define CLOUD_E_CPLUS_STOCKGROUPPOSTGRESTORE_H

#include "gtest/gtest.h"
#include "../../Cloude.h"
#include "../../Application/Mapper/StockGroupMap.h"
#include "../../Application/Mapper/StockGroupLoader.h"
#include "../../SourceDriver/Postgres/PostgreSourceDriver.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {

            class StockGroupPostgreStore : public ::testing::Test {
            public:
                virtual ~StockGroupPostgreStore() = default;
                StockGroupPostgreStore(const StockGroupPostgreStore &srcStockGroupPostgreStore) = default;
                StockGroupPostgreStore &operator=(const StockGroupPostgreStore &srcStockGroupPostgreStore) = default;

            protected:
                using StockGroupLoader = Cloude::Application::Mapper::StockGroupLoader;
                using StockGroupMap = Cloude::Application::Mapper::StockGroupMap;
                using PostgreSourceDriver = Cloude::SourceDriver::PostgreSql::PostgreSourceDriver;
                using EntityStore= Cloude::Framework::EntityStore;

                StockGroupPostgreStore() : _postgresDriver(_stockGroupMap),
                                           _entityStore(_stockGroupMap,
                                                        _stockGroupLoader,
                                                        _postgresDriver) { };

                void SetUp() override;
                void TearDown() override;

                StockGroupLoader _stockGroupLoader;
                StockGroupMap _stockGroupMap;
                PostgreSourceDriver _postgresDriver;
                EntityStore _entityStore;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPPOSTGRESTORE_H
