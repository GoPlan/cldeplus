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
#include <Foundation/Query/Helper/SqlHelper.h>

namespace Cloude {
    namespace AppTest {
        namespace Query {

            TEST(Predicate, case01) {

                using namespace Foundation::Query;
                using namespace std;

                const char *email01 = "goplan@cloud-e.biz";
                const char *email02 = "ducanh.ki@cloud-e.biz";

                auto sptrEnquiryId_01 = Foundation::Type::cldeValueFactory::CreateInt64(1);
                auto sptrEnquiryId_02 = Foundation::Type::cldeValueFactory::CreateInt64(2);
                auto sptrEmail_01 = Foundation::Type::cldeValueFactory::CreateVarchar(email01);
                auto sptrEmail_02 = Foundation::Type::cldeValueFactory::CreateVarchar(email02);

                Application::Mapper::EnquiryMap enquiryMap;
                SourceDriver::SQLite::SQLiteSourceDriver sqliteSourceDriver{enquiryMap};

                SPtrPredicate sptrIdEq01(new Comparative::Equal(enquiryMap.EnquiryId, sptrEnquiryId_01));
                SPtrPredicate sptrEmail01(new Comparative::Like(enquiryMap.Email, sptrEmail_01));
                SPtrPredicate sptrIdEq02(new Comparative::Equal(enquiryMap.EnquiryId, sptrEnquiryId_02));
                SPtrPredicate sptrEmail02(new Comparative::NotLike(enquiryMap.Email, sptrEmail_02));

                SPtrPredicate sptrOR01(new Comparative::Or(sptrIdEq01, sptrEmail01));
                SPtrPredicate sptrOR02(new Comparative::Or(sptrIdEq02, sptrEmail02));
                SPtrPredicate sptrAND(new Comparative::And(sptrOR01, sptrOR02));

                auto fpCondition = [](const std::shared_ptr<Foundation::Column> &column, const int &index)
                        -> std::string {
                    return std::string{"?"};
                };

                auto compound = Foundation::Query::Helper::SqlHelper::CreateSelectPreparedQuery(enquiryMap,
                                                                                                sptrAND,
                                                                                                fpCondition);

                cout << compound.first << endl;

                for (auto item : compound.second) {
                    cout << item->ToCString() << endl;
                }

                cout << "Finished!" << endl;
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_APPTEST_QUERY_PREDICATE_H
