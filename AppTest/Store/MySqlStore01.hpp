//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE01_HPP
#define CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE01_HPP

#include <gtest/gtest.h>
#include <Foundation/Foundation.h>
#include <AppTest/Store/Preparation/EnquiryMySqlStore.h>

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Test {

                using EnquiryMySqlStore = Preparation::EnquiryMySqlStore;

                TEST_F(EnquiryMySqlStore, CreateSaveDelete){

                    auto sptrIdValue = Foundation::Data::ValueFactory::CreateDouble(0);
                    auto sptrSubjectValue = Foundation::Data::ValueFactory::CreateVarChar("Enquiry 00");

                }
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE01_HPP
