//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_TYPE_HPP
#define CLOUD_E_PLUS_APPTEST_TYPE_HPP

#include "gtest/gtest.h"
#include <iostream>
#include <Foundation/Foundation.h>

namespace Cloude {
    namespace AppTest {
        namespace Type {

            TEST(CreateValue, Int64AndVarChar) {

                using namespace Foundation;
                using namespace Foundation::Query;

                std::string email{"goplan@cloud-e.biz"};

                auto sptrEnquiryId = Foundation::Data::ValueFactory::CreateInt64(15);
                auto sptrEmail = Foundation::Data::ValueFactory::CreateVarChar(email);

                auto sptrCopiedEnquiryId = Foundation::Data::Helper::ValueHelper::CopySPtrValue(sptrEnquiryId);
                auto sptrCopiedEmail = Foundation::Data::Helper::ValueHelper::CopySPtrValue(sptrEmail);

                EXPECT_TRUE(strcmp(sptrCopiedEmail->ToString().c_str(), sptrEmail->ToString().c_str()) == 0);
                EXPECT_TRUE(sptrCopiedEmail.get() != sptrEmail.get());
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_TYPE_HPP
