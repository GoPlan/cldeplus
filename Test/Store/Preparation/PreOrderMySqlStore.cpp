//
// Created by LE, Duc Anh on 7/14/15.
//

#include "../../../Source/Drivers/MySql/MySqlSourceDriver.h"
#include "PreOrderMySqlStore.h"

namespace Cloude {
    namespace Test {
        namespace Store {

            void PreOrderMySqlStore::SetUp() {
                _driverPreOrder.OptionArgs().Host = "dell-3020";
                _driverPreOrder.OptionArgs().User = "cloud-e";
                _driverPreOrder.OptionArgs().Pass = "cloud-e";
                _driverPreOrder.OptionArgs().Base = "cloud-e";
                _driverPreOrder.OptionArgs().Port = 3306;

                _driverPreOrderItems.OptionArgs().Host = "dell-3020";
                _driverPreOrderItems.OptionArgs().User = "cloud-e";
                _driverPreOrderItems.OptionArgs().Pass = "cloud-e";
                _driverPreOrderItems.OptionArgs().Base = "cloud-e";
                _driverPreOrderItems.OptionArgs().Port = 3306;

                _driverPreOrder.Connect();
                _driverPreOrderItems.Connect();
            }

            void PreOrderMySqlStore::TearDown() {
                _driverPreOrder.Disconnect();
                _driverPreOrderItems.Disconnect();
            }
        }
    }
}