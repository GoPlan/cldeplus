//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_VALUECOMPARISON_H
#define CLOUD_E_PLUS_VALUECOMPARISON_H

#include "gtest/gtest.h"
#include <iostream>
#include <Cloude.h>
#include <Foundation/Type/Comparer/cldeValueEqual.h>
#include <Foundation/Type/Helper/cldeValueHelper.h>

namespace Cloude {
    namespace AppTest {

        TEST(ValueComparison, int64) {

            using namespace Foundation;
            using namespace Foundation::Type::Comparer;

            auto sptrEnquiryId15 = Type::cldeValueFactory::CreateInt64(15);
            auto sptrEnquiryId17 = Type::cldeValueFactory::CreateInt64(17);
            auto sptrEnquiryId19_01 = Type::cldeValueFactory::CreateInt64(19);
            auto sptrEnquiryId19_02 = Type::cldeValueFactory::CreateInt64(19);

            cldeValueEqual equal{};
            cldeValueGreater greater{};

            EXPECT_TRUE(greater(sptrEnquiryId17, sptrEnquiryId15));
            EXPECT_TRUE(equal(sptrEnquiryId19_01, sptrEnquiryId19_02));
        }
    }
}

#endif //CLOUD_E_PLUS_VALUECOMPARISON_H
