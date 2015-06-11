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
                auto spEmail_02 = Foundation::Type::cldeValueFactory::CreateVarchar(email);

                Application::Mapper::EnquiryMap enquiryMap;
                SourceDriver::SQLite::SQLiteSourceDriver sqliteSourceDriver(enquiryMap);

                Foundation::Query::Comparative::Equal eqId_01(*enquiryMap.EnquiryId, *spEnquiryId_01);
                Foundation::Query::Comparative::GreaterOrEqual gtId_02(*enquiryMap.EnquiryId, *spEnquiryId_02);
                Foundation::Query::Comparative::NotEqual neqEmail(*enquiryMap.Email, *spEmail);
                Foundation::Query::Comparative::And andIdEmail(eqId_01, neqEmail);
                Foundation::Query::Comparative::Or predOr(andIdEmail, gtId_02);

                Foundation::Query::Comparative::Like likeEmail(*enquiryMap.Email, *spEmail_02);
                Foundation::Query::Comparative::Or predOr2(predOr, likeEmail);

                Foundation::Query::Comparative::LesserOrEqual ltId_01(*enquiryMap.EnquiryId, *spEnquiryId_01);
                Foundation::Query::Comparative::IsNotNull isNullEmail(*enquiryMap.Email);
                Foundation::Query::Comparative::Or predOr3(ltId_01, isNullEmail);
                Foundation::Query::Comparative::And and03(predOr2, predOr3);

                std::string predicate = sqliteSourceDriver.CopyFormat(and03);

                cout << predicate << endl;
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_PREDICATE_H
