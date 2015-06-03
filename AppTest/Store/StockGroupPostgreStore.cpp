//
// Created by LE, Duc Anh on 6/3/15.
//

#include <Infrastructure/Postgres/PostgreSourceDriver.h>
#include "StockGroupPostgreStore.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {

            void StockGroupPostgreStore::SetUp() {

                _postgresDriver.OptionArgs.Host = "dell-3020";
                _postgresDriver.OptionArgs.User = "cloud-e";
                _postgresDriver.OptionArgs.Pass = "cloud-e";
                _postgresDriver.OptionArgs.Base = "cloud-e";

                _postgresDriver.Connect();
            }

            void StockGroupPostgreStore::TearDown() {

                _postgresDriver.Disconnect();

            }
        }
    }
}