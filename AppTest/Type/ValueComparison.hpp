//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_TYPE_VALUECOMPARISON_H
#define CLOUD_E_PLUS_APPTEST_TYPE_VALUECOMPARISON_H

#include "gtest/gtest.h"
#include <iostream>
#include <Cloude.h>
#include <Foundation/Type/Comparer/cldeValueComparer.h>
#include <Foundation/Type/Helper/cldeValueHelper.h>

namespace Cloude {
    namespace AppTest {
        namespace Type {

            TEST(ValueComparison, int64) {

                using namespace Foundation;
                using namespace Foundation::Type::Comparer;

                auto sptrEnquiryId15 = Foundation::Type::cldeValueFactory::CreateInt64(15);
                auto sptrEnquiryId17 = Foundation::Type::cldeValueFactory::CreateInt64(17);
                auto sptrEnquiryId19_01 = Foundation::Type::cldeValueFactory::CreateInt64(19);
                auto sptrEnquiryId19_02 = Foundation::Type::cldeValueFactory::CreateInt64(19);

                cldeValueLess cldeLess{};
                cldeValueGreater cldeGreater{};
                cldeValueCompare cldeEqual{};

                EXPECT_TRUE(cldeLess(sptrEnquiryId15, sptrEnquiryId17));
                EXPECT_TRUE(cldeEqual(sptrEnquiryId19_01, sptrEnquiryId19_02));
                EXPECT_TRUE(cldeGreater(sptrEnquiryId17, sptrEnquiryId15));
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_TYPE_VALUECOMPARISON_H
