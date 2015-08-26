//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYMYSQLSTORE_H
#define CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYMYSQLSTORE_H

#include <gtest/gtest.h>
#include "../../Application/EnquiryMap.h"
#include "../../Entity/Enquiry.h"
#include "../../../Source/Foundation/EntityQuery.h"

namespace Cloude {
    namespace Test {
        namespace Store {
            namespace Preparation {

                class EnquiryMySqlStore : public ::testing::Test {

                protected:
                    EnquiryMySqlStore();

                    virtual void SetUp();
                    virtual void TearDown();

                    Application::SPtrEnquiryMap _sptrEnquiryMap;
                    Drivers::MySql::SPtrMySqlSourceDriver _sptrMySqlSourceDriver;
                    Foundation::SPtrEntityStore _sptrEnquiryStore;
                    Foundation::SPtrEntityQuery _sptrEnquiryQuery;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_STORE_PREPARATION_ENQUIRYMYSQLSTORE_H
