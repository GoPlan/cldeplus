//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_TYPE_VALUECOMPARISON_H
#define CLOUD_E_PLUS_APPTEST_TYPE_VALUECOMPARISON_H

#include "gtest/gtest.h"
#include <iostream>
#include "../../Source/Foundation/Foundation.h"

namespace Cloude {
    namespace AppTest {
        namespace Type {

            TEST(ValueComparison, int64) {

                using namespace Foundation;
                using namespace Foundation::Data::Comparer;

                auto sptrEnquiryId15 = Foundation::Data::ValueFactory::CreateInt64(15);
                auto sptrEnquiryId17 = Foundation::Data::ValueFactory::CreateInt64(17);
                auto sptrEnquiryId19_01 = Foundation::Data::ValueFactory::CreateInt64(19);
                auto sptrEnquiryId19_02 = Foundation::Data::ValueFactory::CreateInt64(19);

                Less lt{};
                Greater gt{};
                Compare eq{};

                EXPECT_TRUE(lt(sptrEnquiryId15, sptrEnquiryId17));
                EXPECT_TRUE(gt(sptrEnquiryId17, sptrEnquiryId15));
                EXPECT_TRUE(eq(sptrEnquiryId19_01, sptrEnquiryId19_02));
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_TYPE_VALUECOMPARISON_H
