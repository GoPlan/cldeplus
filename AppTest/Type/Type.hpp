//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_TYPE_HPP
#define CLOUD_E_PLUS_TYPE_HPP

#include "gtest/gtest.h"
#include <iostream>
#include <Cloude.h>
#include <Foundation/Type/Helper/cldeValueHelper.h>

namespace Cloude {
    namespace AppTest {

        TEST(Type, case01) {

            using namespace Foundation;
            using namespace Foundation::Query;

            std::string email{"goplan@cloud-e.biz"};

            auto sptrEnquiryId = Type::cldeValueFactory::CreateInt64(15);
            auto sptrEmail = Type::cldeValueFactory::CreateVarChar(email);

            auto sptrCopiedEnquiryId = Type::Helper::cldeValueHelper::CopySPtrValue(sptrEnquiryId);
            auto sptrCopiedEmail = Type::Helper::cldeValueHelper::CopySPtrValue(sptrEmail);

            EXPECT_TRUE(strcmp(sptrCopiedEmail->ToCString(), sptrEmail->ToCString()) == 0);
            EXPECT_TRUE(sptrCopiedEmail.get() != sptrEmail.get());
        }
    }
}

#endif //CLOUD_E_PLUS_TYPE_HPP
