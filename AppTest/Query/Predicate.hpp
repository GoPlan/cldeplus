//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_CPLUS_APPTEST_QUERY_PREDICATE_H
#define CLOUD_E_CPLUS_APPTEST_QUERY_PREDICATE_H

#include "gtest/gtest.h"
#include <Cloude.h>
#include <Application/Mapper/EnquiryMap.h>
#include <Application/Mapper/EnquiryLoader.h>
#include <SourceDriver/SQLite/SQLiteSourceDriver.h>

namespace Cloude {
    namespace AppTest {
        namespace Query {

            TEST(Predicate, case01){

                const char * email = "goplan@cloud-e.biz";

                auto SPtrEnquiryId_01 = Foundation::Type::cldeValueFactory::CreateInt64(1);
                auto SPtrEnquiryId_02 = Foundation::Type::cldeValueFactory::CreateInt64(2);
                auto SPtrEmail_01 = Foundation::Type::cldeValueFactory::CreateVarchar(email);
                auto SPtrEmail_02 = Foundation::Type::cldeValueFactory::CreateVarchar(email);

                Application::Mapper::EnquiryMap enquiryMap;
                SourceDriver::SQLite::SQLiteSourceDriver sqliteSourceDriver(enquiryMap);
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_APPTEST_QUERY_PREDICATE_H
