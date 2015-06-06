//
// Created by LE, Duc-Anh on 5/21/15.
//


#include "StockGroupMySqlStore.h"


void Cloude::AppTest::Store::StockGroupMySqlStore::SetUp() {

    auto &optionArgs = _mySqlDriver.getOptionArgs();

    optionArgs.Host = "dell-3020";
    optionArgs.User = "cloud-e";
    optionArgs.Pass = "cloud-e";
    optionArgs.Base = "cloud-e";

    _mySqlDriver.Connect();

}

void Cloude::AppTest::Store::StockGroupMySqlStore::TearDown() {
    _mySqlDriver.Disconnect();
}