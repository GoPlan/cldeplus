//
// Created by LE, Duc Anh on 6/8/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYSQLITESTORE_H
#define CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYSQLITESTORE_H

#include "gtest/gtest.h"
#include <Foundation/Foundation.h>
#include <Drivers/SQLite/SQLiteSourceDriver.h>
#include <AppTest/Application/ProductMap.h>

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Preparation {

                class ProductSQLiteStore : public ::testing::Test {

                public:
                    ProductSQLiteStore();
                    ProductSQLiteStore(const ProductSQLiteStore &) = default;
                    ProductSQLiteStore(ProductSQLiteStore &&) = default;
                    ProductSQLiteStore &operator=(const ProductSQLiteStore &) = default;
                    ProductSQLiteStore &operator=(ProductSQLiteStore &&) = default;
                    ~ProductSQLiteStore() = default;

                protected:
                    using ProductMap = Application::ProductMap;
                    using SQLiteSourceDriver = Drivers::SQLite::SQLiteSourceDriver;
                    using EntityStore = Foundation::EntityStore;

                    void SetUp() override;
                    void TearDown() override;

                    ProductMap _mapProduct;
                    SQLiteSourceDriver _driverSQLite;
                    EntityStore _storeProduct;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYSQLITESTORE_H
