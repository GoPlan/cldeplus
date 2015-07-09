//
// Created by LE, Duc Anh on 6/8/15.
//

#include <Drivers/SQLite/SQLiteSourceDriver.h>
#include "EnquirySQLiteStore.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Preparation {

                EnquirySQLiteStore::EnquirySQLiteStore() : _sqliteSourceDriver(_enquiryMap),
                                                           _entityStore(_enquiryMap,
                                                                        _enquiryLoader,
                                                                        _sqliteSourceDriver) {
                    //
                }

                void EnquirySQLiteStore::SetUp() {

                    auto &options = _sqliteSourceDriver.OptionArgs();
                    options.ConnectionString = "../ex1.db";

                    _sqliteSourceDriver.Connect();
                }

                void EnquirySQLiteStore::TearDown() {
                    _sqliteSourceDriver.Connect();
                }
            }
        }
    }
}

