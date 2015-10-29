//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLDEPLUS_APPTEST_STORE_MYSQLSTORE01_HPP
#define CLDEPLUS_APPTEST_STORE_MYSQLSTORE01_HPP

#include <gtest/gtest.h>
#include "../../Source/Foundation/Foundation.h"
#include "../../Source/Drivers/MySql/MySqlSourceFactory.h"
#include "Preparation/EnquiryMySqlStore.h"

namespace CLDEPlus {
    namespace Test {
        namespace Store {

            using EnquiryMySqlStore = Preparation::EnquiryMySqlStore;
            using MySqlDriverFactory = Drivers::MySql::MySqlSourceFactory;

            TEST_F(EnquiryMySqlStore, CreateSaveDelete01) {

                Foundation::Data::Comparer::Compare compare{};

                auto sptrId = Foundation::Data::ValueFactory::CreateInt64(0);
                auto sptrCustId = Foundation::Data::ValueFactory::CreateInt64(0);
                auto sptrSubject = Foundation::Data::ValueFactory::CreateVarChar("Enquiry 00");
                auto sptrSubmittedDate = MySqlDriverFactory::CreateDate(2015, 7, 15);
                auto sptrSubmittedHour = MySqlDriverFactory::CreateTime(22, 53, 18, 43256);
                auto sptrUpdatedDate = MySqlDriverFactory::CreateDateTime(2015, 7, 15, 22, 15, 13);

                auto sptrIdCell = (Foundation::SPtrCell)Foundation::Cell::Create(_sptrEnquiryMap->GetColumn("Id"), sptrId);
                auto sptrCells = {sptrIdCell};
                auto sptrIdentity = (Foundation::SPtrIdentity)Foundation::Identity::Create(sptrCells);

                // DELETE - Check if Entity is nullptr
                {
                    auto sptrEnquiry = _sptrEnquiryStore->Get(sptrIdentity);

                    if (sptrEnquiry.get() != 0) {
                        _sptrEnquiryStore->Delete(sptrEnquiry);
                        _sptrEnquiryStore->Clear();
                    }
                }

                // CREATE
                {
                    auto sptrEnquiry = _sptrEnquiryStore->Create(sptrIdentity);
                    EXPECT_TRUE(sptrEnquiry.get() != 0);
                    EXPECT_TRUE(_sptrEnquiryStore->HasIdentityInMap(sptrIdentity));
                }

                // SAVE
                {
                    auto sptrEnquiry = _sptrEnquiryStore->Get(sptrIdentity);
                    auto &sptrSubmittedDateCell = sptrEnquiry->getCell("SubmittedDate");
                    auto &sptrSubmittedHourCell = sptrEnquiry->getCell("SubmittedHour");
                    auto &sptrCustIdCell = sptrEnquiry->getCell("CustId");
                    auto &sptrSubjectCell = sptrEnquiry->getCell("Subject");
                    auto &sptrContentCell = sptrEnquiry->getCell("Content");
                    auto &sptrUpdatedDateCell = sptrEnquiry->getCell("UpdatedDate");

                    sptrCustIdCell->setValue(sptrCustId);
                    sptrSubmittedDateCell->setValue(sptrSubmittedDate);
                    sptrSubmittedHourCell->setValue(sptrSubmittedHour);
                    sptrSubjectCell->setValue(sptrSubject);
                    sptrUpdatedDateCell->setValue(sptrUpdatedDate);

                    _sptrEnquiryStore->Save(sptrEnquiry);
                    _sptrEnquiryStore->Clear();
                }

                // GET - Check for saved field
                {
                    auto sptrEnquiry = _sptrEnquiryStore->Get(sptrIdentity);

                    EXPECT_TRUE(sptrEnquiry.get() != 0);
                    EXPECT_TRUE(_sptrEnquiryStore->Size() > 0);
                    EXPECT_TRUE(_sptrEnquiryStore->HasIdentityInMap(sptrIdentity));

                    if (sptrEnquiry) {

                        auto &sptrCustIdCell = sptrEnquiry->getCell("CustId");
                        auto &sptrSubmittedDateCell = sptrEnquiry->getCell("SubmittedDate");
                        auto &sptrSubmittedHourCell = sptrEnquiry->getCell("SubmittedHour");
                        auto &sptrSubjectCell = sptrEnquiry->getCell("Subject");
                        auto &sptrUpdatedDateCell = sptrEnquiry->getCell("UpdatedDate");

                        EXPECT_TRUE(compare(sptrCustIdCell->getValue(), sptrCustId));
                        EXPECT_TRUE(compare(sptrSubmittedDateCell->getValue(), sptrSubmittedDate));
                        EXPECT_TRUE(compare(sptrSubmittedHourCell->getValue(), sptrSubmittedHour));
                        EXPECT_TRUE(compare(sptrUpdatedDateCell->getValue(), sptrUpdatedDate));
                    }
                }
            }
        }
    }
}

#endif //CLDEPLUS_APPTEST_STORE_MYSQLSTORE01_HPP
