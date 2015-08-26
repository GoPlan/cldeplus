//
// Created by LE, Duc Anh on 6/8/15.
//

#include "../../../Source/Drivers/SQLite/SQLiteSourceDriver.h"
#include "ProductSQLiteStore.h"

namespace Cloude {
    namespace Test {
        namespace Store {
            namespace Preparation {

                ProductSQLiteStore::ProductSQLiteStore() {
                    _sptrProductMap = std::make_shared<Application::ProductMap>();
                    _sptrSQLiteSourceDriver = std::make_shared<Drivers::SQLite::SQLiteSourceDriver>(_sptrProductMap);
                    _sptrProductStore = std::make_shared<Foundation::EntityStore>(_sptrProductMap,
                                                                                  _sptrSQLiteSourceDriver);

                }

                void ProductSQLiteStore::SetUp() {
                    _sptrSQLiteSourceDriver->OptionArgs().ConnectionString = "example01.db";
                    _sptrSQLiteSourceDriver->Connect();
                }

                void ProductSQLiteStore::TearDown() {
                    _sptrSQLiteSourceDriver->Disconnect();
                }
            }
        }
    }
}

