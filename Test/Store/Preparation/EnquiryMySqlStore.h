//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYMYSQLSTORE_H
#define CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYMYSQLSTORE_H

#include "gtest/gtest.h"
#include "../../Application/EnquiryMap.h"
#include "../../Entity/Enquiry.h"
#include "../../../Source/Foundation/EntityQuery.h"

namespace Cloude {
    namespace Test {
        namespace Store {
            namespace Preparation {

                class EnquiryMySqlStore : public ::testing::Test {

                protected:
                    using Enquiry = Entity::Enquiry;
                    using EnquiryMap = Application::EnquiryMap;
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
