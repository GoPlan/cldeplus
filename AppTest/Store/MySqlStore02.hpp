//
// Created by LE, Duc Anh on 7/17/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE002_HPP
#define CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE002_HPP

#include <gtest/gtest.h>
#include <Foundation/Foundation.h>
#include <Drivers/MySql/Helper/MySqlSourceHelper.h>

namespace Cloude {
    namespace AppTest {
        namespace Store {
            namespace Test {

                using MySqlDriverHelper = Drivers::MySql::Helper::MySqlSourceHelper;

                TEST(MySqlSourceDriver, Comparable) {

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

            }
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_STORE_MYSQLSTORE002_HPP
