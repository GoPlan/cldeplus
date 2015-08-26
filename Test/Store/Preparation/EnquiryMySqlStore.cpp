//
// Created by LE, Duc Anh on 7/16/15.
//

#include "../../../Source/Drivers/MySql/MySqlSourceDriver.h"
#include "EnquiryMySqlStore.h"

namespace Cloude {
    namespace Test {
        namespace Store {
            namespace Preparation {

                EnquiryMySqlStore::EnquiryMySqlStore() {
                    _sptrEnquiryMap = std::make_shared<Application::EnquiryMap>();
                    _sptrMySqlSourceDriver = std::make_shared<Drivers::MySql::MySqlSourceDriver>(_sptrEnquiryMap);
                    _sptrEnquiryStore = std::make_shared<Foundation::EntityStore>(_sptrEnquiryMap, _sptrMySqlSourceDriver);
                    _sptrEnquiryQuery = std::make_shared<Foundation::EntityQuery>(_sptrEnquiryMap, _sptrMySqlSourceDriver);
                }

                void EnquiryMySqlStore::SetUp() {

                    _sptrMySqlSourceDriver->OptionArgs().Host = "dell-3020";
                    _sptrMySqlSourceDriver->OptionArgs().User = "cloud-e";
                    _sptrMySqlSourceDriver->OptionArgs().Pass = "cloud-e";
                    _sptrMySqlSourceDriver->OptionArgs().Base = "cloud-e";
                    _sptrMySqlSourceDriver->OptionArgs().Port = 3306;

                    _sptrMySqlSourceDriver->Connect();
                }

                void EnquiryMySqlStore::TearDown() {
                    _sptrMySqlSourceDriver->Disconnect();
                }
            }
        }
    }
}


