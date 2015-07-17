//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE01_HPP
#define CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE01_HPP

#include <gtest/gtest.h>
#include <Foundation/Foundation.h>
#include <AppTest/Store/Preparation/EnquiryMySqlStore.h>
#include <Drivers/MySql/Helper/MySqlSourceHelper.h>

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Test {

                using EnquiryMySqlStore = Preparation::EnquiryMySqlStore;
                using MySqlDriverHelper = Drivers::MySql::Helper::MySqlSourceHelper;

                TEST_F(EnquiryMySqlStore, Comparable) {

                    Foundation::Data::Comparer::Less LT{};
                    Foundation::Data::Comparer::Greater GT{};
                    Foundation::Data::Comparer::Compare EQ{};

                    // Date
                    {
                        auto sptrDateLo = MySqlDriverHelper::CreateDate(2015, 7, 15);
                        auto sptrDateHi = MySqlDriverHelper::CreateDate(2015, 7, 16);
                        auto sptrDateLoAlt = MySqlDriverHelper::CreateDate(2015, 7, 15);

                        EXPECT_TRUE(LT(sptrDateLo, sptrDateHi));
                        EXPECT_TRUE(GT(sptrDateHi, sptrDateLo));
                        EXPECT_TRUE(EQ(sptrDateLo, sptrDateLoAlt));
                        EXPECT_TRUE(!EQ(sptrDateLo, sptrDateHi));
                    }

                    // Time
                    {
                        auto sptrTimeLo = MySqlDriverHelper::CreateTime(22, 12, 35);
                        auto sptrTimeHi = MySqlDriverHelper::CreateTime(23, 7, 16);
                        auto sptrTimeLoAlt = MySqlDriverHelper::CreateTime(22, 12, 35);

                        EXPECT_TRUE(LT(sptrTimeLo, sptrTimeHi));
                        EXPECT_TRUE(GT(sptrTimeHi, sptrTimeLo));
                        EXPECT_TRUE(EQ(sptrTimeLo, sptrTimeLoAlt));
                        EXPECT_TRUE(!EQ(sptrTimeLo, sptrTimeHi));
                    }

                    // Date & Time
                    {
                        auto sptrDateTimeLo = MySqlDriverHelper::CreateDateTime(2015, 7, 15, 22, 12, 35);
                        auto sptrDateTimeHi = MySqlDriverHelper::CreateDateTime(2015, 7, 18, 23, 7, 16);
                        auto sptrDateTimeAlt = MySqlDriverHelper::CreateDateTime(2015, 7, 15, 22, 12, 35);

                        EXPECT_TRUE(LT(sptrDateTimeLo, sptrDateTimeHi));
                        EXPECT_TRUE(GT(sptrDateTimeHi, sptrDateTimeLo));
                        EXPECT_TRUE(EQ(sptrDateTimeLo, sptrDateTimeAlt));
                        EXPECT_TRUE(!EQ(sptrDateTimeLo, sptrDateTimeHi));
                    }
                }

                TEST_F(EnquiryMySqlStore, CreateSaveDelete01) {


                    Foundation::Data::Comparer::Compare compare{};

                    auto sptrId = Foundation::Data::ValueFactory::CreateInt64(0);
                    auto sptrCustId = Foundation::Data::ValueFactory::CreateInt64(0);
                    auto sptrSubject = Foundation::Data::ValueFactory::CreateVarChar("Enquiry 00");
                    auto sptrSubmittedDate = MySqlDriverHelper::CreateDate(2015, 7, 15);
                    auto sptrSubmittedHour = MySqlDriverHelper::CreateTime(22, 53, 18, 43256);
                    auto sptrUpdatedDate = MySqlDriverHelper::CreateDateTime(2015, 7, 15, 22, 15, 13);

                    auto sptrIdCell = Foundation::CreateCell(_mapEnquiry.Id, sptrId);
                    auto sptrCells = {sptrIdCell};
                    auto sptrIdentity = Foundation::CreateIdentity(sptrCells);

                    // DELETE - Check if Entity is nullptr
                    {
                        auto sptrEnquiry = _storeEnquiry.Get(sptrIdentity);

                        if (sptrEnquiry.get() != 0) {
                            _storeEnquiry.Delete(sptrEnquiry);
                            _storeEnquiry.Clear();
                        }
                    }

                    // CREATE
                    {
                        auto sptrEnquiry = _storeEnquiry.Create(sptrIdentity);
                        EXPECT_TRUE(sptrEnquiry.get() != 0);
                        EXPECT_TRUE(_storeEnquiry.HasIdentityInMap(sptrIdentity));
                    }

                    // SAVE
                    {
                        auto sptrEnquiry = _storeEnquiry.Get(sptrIdentity);
                        auto &sptrSubmittedDateCell = sptrEnquiry->getCell("SubmittedDate");
                        auto &sptrSubmittedHourCell = sptrEnquiry->getCell("SubmittedHour");
                        auto &sptrCustIdCell = sptrEnquiry->getCell("CustId");
                        auto &sptrSubjectCell = sptrEnquiry->getCell("Subject");
                        auto &sptrUpdatedDateCell = sptrEnquiry->getCell("UpdatedDate");

                        sptrCustIdCell->setValue(sptrCustId);
                        sptrSubmittedDateCell->setValue(sptrSubmittedDate);
                        sptrSubmittedHourCell->setValue(sptrSubmittedHour);
                        sptrSubjectCell->setValue(sptrSubject);
                        sptrUpdatedDateCell->setValue(sptrUpdatedDate);

                        _storeEnquiry.Save(sptrEnquiry);
                        _storeEnquiry.Clear();
                    }

                    // GET - Check for saved field
                    {
                        auto sptrEnquiry = _storeEnquiry.Get(sptrIdentity);

                        EXPECT_TRUE(sptrEnquiry.get() != 0);
                        EXPECT_TRUE(_storeEnquiry.Size() > 0);
                        EXPECT_TRUE(_storeEnquiry.HasIdentityInMap(sptrIdentity));

                        if (sptrEnquiry) {

                            auto &sptrCustIdCell = sptrEnquiry->getCell("CustId");
                            auto &sptrSubmittedDateCell = sptrEnquiry->getCell("SubmittedDate");
                            auto &sptrSubmittedHourCell = sptrEnquiry->getCell("SubmittedHour");
                            auto &sptrSubjectCell = sptrEnquiry->getCell("Subject");
                            auto &sptrUpdatedDateCell = sptrEnquiry->getCell("UpdatedDate");

                            EXPECT_TRUE(compare(sptrCustIdCell->getValue(), sptrCustId));
                            EXPECT_TRUE(compare(sptrSubmittedDateCell->getValue(), sptrSubmittedDate));
                            EXPECT_TRUE(compare(sptrSubmittedHourCell->getValue(), sptrSubmittedHour));
                            EXPECT_TRUE(compare(sptrSubjectCell->getValue(), sptrSubject));
                            EXPECT_TRUE(compare(sptrUpdatedDateCell->getValue(), sptrUpdatedDate));
                        }
                    }
                }
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE01_HPP
