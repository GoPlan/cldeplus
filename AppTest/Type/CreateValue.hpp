//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_TYPE_HPP
#define CLOUD_E_PLUS_APPTEST_TYPE_HPP

#include "gtest/gtest.h"
#include <iostream>
#include <Cloude.h>
#include <Foundation/Type/Helper/cldeValueHelper.h>

namespace Cloude {
    namespace AppTest {
        namespace Type {

            TEST(CreateValue, Int64AndVarChar) {

                using namespace Foundation;
                using namespace Foundation::Query;

                std::string email{"goplan@cloud-e.biz"};

                auto sptrEnquiryId = Foundation::Type::cldeValueFactory::CreateInt64(15);
                auto sptrEmail = Foundation::Type::cldeValueFactory::CreateVarChar(email);

                auto sptrCopiedEnquiryId = Foundation::Type::Helper::cldeValueHelper::CopySPtrValue(sptrEnquiryId);
                auto sptrCopiedEmail = Foundation::Type::Helper::cldeValueHelper::CopySPtrValue(sptrEmail);

                EXPECT_TRUE(strcmp(sptrCopiedEmail->ToCString(), sptrEmail->ToCString()) == 0);
                EXPECT_TRUE(sptrCopiedEmail.get() != sptrEmail.get());
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_TYPE_HPP
