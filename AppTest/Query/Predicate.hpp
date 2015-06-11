//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_CPLUS_PREDICATE_H
#define CLOUD_E_CPLUS_PREDICATE_H

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

                auto spEnquiryId_01 = Foundation::Type::cldeValueFactory::CreateInt64(1);
                auto spEnquiryId_02 = Foundation::Type::cldeValueFactory::CreateInt64(2);
                auto spEmail = Foundation::Type::cldeValueFactory::CreateVarchar(email);

                Application::Mapper::EnquiryMap enquiryMap;
                SourceDriver::SQLite::SQLiteSourceDriver sqliteSourceDriver(enquiryMap);

                Foundation::Query::Comparative::Equal eqId_01(*enquiryMap.EnquiryId, *spEnquiryId_01);
                Foundation::Query::Comparative::Greater gtId_02(*enquiryMap.EnquiryId, *spEnquiryId_02);
                Foundation::Query::Comparative::Equal eqEmail(*enquiryMap.Email, *spEmail);
                Foundation::Query::Comparative::And andIdEmail(eqId_01, eqEmail);
                Foundation::Query::Comparative::Or predOr(andIdEmail, gtId_02);

                std::string predicate = sqliteSourceDriver.CopyFormat(predOr);

                cout << predicate << endl;
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_PREDICATE_H
