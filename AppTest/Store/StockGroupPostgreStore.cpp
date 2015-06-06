//
// Created by LE, Duc Anh on 6/3/15.
//

#include <Infrastructure/Postgres/PostgreSourceDriver.h>
#include "StockGroupPostgreStore.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {

            void StockGroupPostgreStore::SetUp() {

                auto &optionArgs = _postgresDriver.getOptionArgs();

                optionArgs.Host = "dell-3020";
                optionArgs.User = "cloud-e";
                optionArgs.Pass = "cloud-e";
                optionArgs.Base = "cloud-e";

                _postgresDriver.Connect();
            }

            void StockGroupPostgreStore::TearDown() {
                _postgresDriver.Disconnect();
            }
        }
    }
}