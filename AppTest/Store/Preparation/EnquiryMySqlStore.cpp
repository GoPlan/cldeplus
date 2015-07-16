//
// Created by LE, Duc Anh on 7/16/15.
//

#include <Drivers/MySql/MySqlSourceDriver.h>
#include "EnquiryMySqlStore.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Preparation {

                void EnquiryMySqlStore::SetUp() {

                    _driverEnquiry.OptionArgs().Host = "dell-3020";
                    _driverEnquiry.OptionArgs().User = "cloud-e";
                    _driverEnquiry.OptionArgs().Pass = "cloud-e";
                    _driverEnquiry.OptionArgs().Base = "cloud-e";
                    _driverEnquiry.OptionArgs().Port = 3306;

                    _driverEnquiry.Connect();
                }

                void EnquiryMySqlStore::TearDown() {
                    _driverEnquiry.Disconnect();
                }
            }
        }
    }
}


