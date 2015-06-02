//
// Created by LE, Duc-Anh on 5/21/15.
//

#include <Infrastructure/MySqlSourceDriver.h>
#include "StoreSimple.h"


void Cloude::AppTest::Store::StoreSimple::SetUp() {

    _mySqlDriver.OptionArgs.Host = "dell-3020";
    _mySqlDriver.OptionArgs.Port = 3306;
    _mySqlDriver.OptionArgs.User = "cloud-e";
    _mySqlDriver.OptionArgs.Pass = "cloud-e";
    _mySqlDriver.OptionArgs.Base = "cloud-e";

    _mySqlDriver.Connect();

}

void Cloude::AppTest::Store::StoreSimple::TearDown() {

    _mySqlDriver.Disconnect();

}