//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYMYSQLSTORE_H
#define CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYMYSQLSTORE_H

#include "gtest/gtest.h"
#include <Foundation/Foundation.h>
#include <Drivers/MySql/MySqlSourceDriver.h>
#include <AppTest/Application/EnquiryMap.h>
#include <AppTest/Entity/Enquiry.h>

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Preparation {

                class EnquiryMySqlStore : public ::testing::Test {

                protected:
                    using Enquiry = AppTest::Entity::Enquiry;
                    using EnquiryMap = AppTest::Application::EnquiryMap;
                    using MySqlSourceDriver = Drivers::MySql::MySqlSourceDriver;
                    using EntityStore = Foundation::EntityStore;
                    using EntityQuery = Foundation::EntityQuery;

                    EnquiryMySqlStore() : _driverEnquiry{_mapEnquiry},
                                          _storeEnquiry{_mapEnquiry, _driverEnquiry},
                                          _queryEnquiry{_mapEnquiry, _driverEnquiry} {
                        //
                    }

                    virtual void SetUp();
                    virtual void TearDown();

                    EnquiryMap _mapEnquiry;
                    MySqlSourceDriver _driverEnquiry;
                    EntityStore _storeEnquiry;
                    EntityQuery _queryEnquiry;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYMYSQLSTORE_H
