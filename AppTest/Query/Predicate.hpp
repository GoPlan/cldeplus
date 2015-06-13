//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_CPLUS_APPTEST_QUERY_PREDICATE_H
#define CLOUD_E_CPLUS_APPTEST_QUERY_PREDICATE_H

#include "gtest/gtest.h"
#include <memory>
#include <iostream>
#include <Cloude.h>
#include <Application/Mapper/EnquiryMap.h>
#include <Application/Mapper/EnquiryLoader.h>
#include <Foundation/Query/Query.h>
#include <SourceDriver/SQLite/SQLiteSourceDriver.h>

namespace Cloude {
    namespace AppTest {
        namespace Query {

            TEST(Predicate, case01) {

                using namespace Foundation::Query;
                using namespace std;


                const char *email = "goplan@cloud-e.biz";

                auto sptrEnquiryId_01 = Foundation::Type::cldeValueFactory::CreateInt64(1);
                auto sptrEnquiryId_02 = Foundation::Type::cldeValueFactory::CreateInt64(2);
                auto sptrEmail_01 = Foundation::Type::cldeValueFactory::CreateVarchar(email);
                auto sptrEmail_02 = Foundation::Type::cldeValueFactory::CreateVarchar(email);

                Application::Mapper::EnquiryMap enquiryMap;

                SPtrPredicate sptrIdEq01(new Comparative::Equal(*enquiryMap.EnquiryId, sptrEnquiryId_01));
                SPtrPredicate sptrEmail(new Comparative::Like(*enquiryMap.Email, sptrEmail_01));
                SPtrPredicate sptrAnd(new Comparative::And(sptrIdEq01, sptrEmail));
                SPtrPredicateIterator next(new PredicateIterator(sptrAnd));

                while (next) {

                    if (next->hasValue()) {
                        cout << next->getPredicate()->getValue()->ToCString() << endl;
                    }

                    next = next->operator++();
                }

                cout << "Finishing .." << endl;
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_APPTEST_QUERY_PREDICATE_H
