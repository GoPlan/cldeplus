//
// Created by LE, Duc Anh on 7/14/15.
//

#include "../../../Source/Drivers/MySql/MySqlSourceDriver.h"
#include "PreOrderMySqlStore.h"

namespace CLDEPlus {
    namespace Test {
        namespace Store {

            PreOrderMySqlStore::PreOrderMySqlStore() {
                _sptrPreOrderMap = std::make_shared<Application::PreOrderMap>();
                _sptrPreOrderItemsMap = std::make_shared<Application::PreOrderItemsMap>();
                _sptrPreOrderDriver = std::make_shared<Drivers::MySql::MySqlSourceDriver>(_sptrPreOrderMap);
                _sptrPreOrderItemsDriver = std::make_shared<Drivers::MySql::MySqlSourceDriver>(_sptrPreOrderItemsMap);
                _sptrPreOrderStore = std::make_shared<Foundation::EntityStore>(_sptrPreOrderMap, _sptrPreOrderDriver);
                _sptrPreOrderItemsStore = std::make_shared<Foundation::EntityStore>(_sptrPreOrderItemsMap, _sptrPreOrderItemsDriver);
                _sptrPreOrderQuery = std::make_shared<Foundation::EntityQuery>(_sptrPreOrderMap, _sptrPreOrderDriver);
                _sptrPreOrderItemsQuery = std::make_shared<Foundation::EntityQuery>(_sptrPreOrderItemsMap, _sptrPreOrderItemsDriver);
            }

            void PreOrderMySqlStore::SetUp() {

                _sptrPreOrderDriver->OptionArgs().Host = "dell-3020";
                _sptrPreOrderDriver->OptionArgs().User = "cloud-e";
                _sptrPreOrderDriver->OptionArgs().Pass = "cloud-e";
                _sptrPreOrderDriver->OptionArgs().Base = "cloud-e";
                _sptrPreOrderDriver->OptionArgs().Port = 3306;

                _sptrPreOrderItemsDriver->OptionArgs().Host = "dell-3020";
                _sptrPreOrderItemsDriver->OptionArgs().User = "cloud-e";
                _sptrPreOrderItemsDriver->OptionArgs().Pass = "cloud-e";
                _sptrPreOrderItemsDriver->OptionArgs().Base = "cloud-e";
                _sptrPreOrderItemsDriver->OptionArgs().Port = 3306;

                _sptrPreOrderDriver->Connect();
                _sptrPreOrderItemsDriver->Connect();
            }

            void PreOrderMySqlStore::TearDown() {
                _sptrPreOrderDriver->Disconnect();
                _sptrPreOrderItemsDriver->Disconnect();
            }
        }
    }
}