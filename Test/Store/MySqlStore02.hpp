//
// Created by LE, Duc Anh on 7/17/15.
//

#ifndef CLDEPLUS_APPTEST_STORE_MYSQLSTORE002_HPP
#define CLDEPLUS_APPTEST_STORE_MYSQLSTORE002_HPP

#include <gtest/gtest.h>
#include "../../Source/Foundation/Foundation.h"
#include "../../Source/Drivers/MySql/MySqlSourceFactory.h"

namespace CLDEPlus {
    namespace Test {
        namespace Store {

            using MySqlDriverFactory = Drivers::MySql::MySqlSourceFactory;

            TEST(MySqlSourceDriver, Comparable) {

                Foundation::Data::Comparer::Less LT{};
                Foundation::Data::Comparer::Greater GT{};
                Foundation::Data::Comparer::Compare EQ{};

                // Date
                {
                    auto sptrDateLo = MySqlDriverFactory::CreateDate(2015, 7, 15);
                    auto sptrDateHi = MySqlDriverFactory::CreateDate(2015, 7, 16);
                    auto sptrDateLoAlt = MySqlDriverFactory::CreateDate(2015, 7, 15);

                    EXPECT_TRUE(LT(sptrDateLo, sptrDateHi));
                    EXPECT_TRUE(GT(sptrDateHi, sptrDateLo));
                    EXPECT_TRUE(EQ(sptrDateLo, sptrDateLoAlt));
                    EXPECT_TRUE(!EQ(sptrDateLo, sptrDateHi));
                }

                // Time
                {
                    auto sptrTimeLo = MySqlDriverFactory::CreateTime(22, 12, 35);
                    auto sptrTimeHi = MySqlDriverFactory::CreateTime(23, 7, 16);
                    auto sptrTimeLoAlt = MySqlDriverFactory::CreateTime(22, 12, 35);

                    EXPECT_TRUE(LT(sptrTimeLo, sptrTimeHi));
                    EXPECT_TRUE(GT(sptrTimeHi, sptrTimeLo));
                    EXPECT_TRUE(EQ(sptrTimeLo, sptrTimeLoAlt));
                    EXPECT_TRUE(!EQ(sptrTimeLo, sptrTimeHi));
                }

                // Date & Time
                {
                    auto sptrDateTimeLo = MySqlDriverFactory::CreateDateTime(2015, 7, 15, 22, 12, 35);
                    auto sptrDateTimeHi = MySqlDriverFactory::CreateDateTime(2015, 7, 18, 23, 7, 16);
                    auto sptrDateTimeAlt = MySqlDriverFactory::CreateDateTime(2015, 7, 15, 22, 12, 35);

                    EXPECT_TRUE(LT(sptrDateTimeLo, sptrDateTimeHi));
                    EXPECT_TRUE(GT(sptrDateTimeHi, sptrDateTimeLo));
                    EXPECT_TRUE(EQ(sptrDateTimeLo, sptrDateTimeAlt));
                    EXPECT_TRUE(!EQ(sptrDateTimeLo, sptrDateTimeHi));
                }
            }
        }
    }
}


#endif //CLDEPLUS_APPTEST_STORE_MYSQLSTORE002_HPP
