//
// Created by LE, Duc Anh on 6/8/15.
//

#include <Drivers/SQLite/SQLiteSourceDriver.h>
#include "ProductSQLiteStore.h"

namespace Cloude {
    namespace Test {
        namespace Store {
            namespace Preparation {

                ProductSQLiteStore::ProductSQLiteStore() : _driverSQLite(_mapProduct),
                                                           _storeProduct(_mapProduct, _driverSQLite) {
                    //
                }

                void ProductSQLiteStore::SetUp() {
                    _driverSQLite.OptionArgs().ConnectionString = "example01.db";
                    _driverSQLite.Connect();
                }

                void ProductSQLiteStore::TearDown() {
                    _driverSQLite.Disconnect();
                }
            }
        }
    }
}

