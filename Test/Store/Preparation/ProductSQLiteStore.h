//
// Created by LE, Duc Anh on 6/8/15.
//

#ifndef CLDEPLUS_APPTEST_STORE_PREPARATION_ENQUIRYSQLITESTORE_H
#define CLDEPLUS_APPTEST_STORE_PREPARATION_ENQUIRYSQLITESTORE_H

#include <gtest/gtest.h>
#include "../../../Source/Foundation/Foundation.h"
#include "../../../Source/Drivers/SQLite/SQLiteSourceDriver.h"
#include "../../Application/ProductMap.h"

namespace CLDEPlus {
    namespace Test {
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
                    void SetUp() override;
                    void TearDown() override;

                    Application::SPtrProductMap _sptrProductMap;
                    Drivers::SQLite::SPtrSQLiteSourceDriver _sptrSQLiteSourceDriver;
                    Foundation::SPtrEntityStore _sptrProductStore;
                };
            }
        }
    }
}


#endif //CLDEPLUS_APPTEST_STORE_PREPARATION_ENQUIRYSQLITESTORE_H
