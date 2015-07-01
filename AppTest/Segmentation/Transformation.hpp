//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_TRANSFORMATION_HPP
#define CLOUD_E_PLUS_APPTEST_TRANSFORMATION_HPP

#include "gtest/gtest.h"
#include <memory>
#include <iostream>
#include <functional>
#include <Cloude.h>
#include <AppTest/Application/ProductMap.h>
#include <AppTest/Application/OrderMap.h>
#include <AppTest/Application/CustomerMap.h>
#include <Segmentation/Transformation/Transformation.h>

namespace Cloude {
    namespace AppTest {
        namespace Segmentation {

            TEST(Transformation, case01) {

                using namespace Cloude::Segmentation;

                Application::ProductMap productMap{};
                Application::OrderMap orderMap{};
                Application::CustomerMap customerMap{};

                auto sptrOrderId = Foundation::Type::cldeValueFactory::CreateInt64(1);
                auto sptrCustmId = Foundation::Type::cldeValueFactory::CreateInt64(2);
                auto sptrOrderName = Foundation::Type::cldeValueFactory::CreateVarChar(std::string{"My Order"});
                auto sptrCost = Foundation::Type::cldeValueFactory::CreateDouble(15.0);

                auto sptrOrderIdCell = std::make_shared<Foundation::Cell>(orderMap.Id);
                auto sptrCustmIdCell = std::make_shared<Foundation::Cell>(orderMap.CustId);
                auto sptrOrderNameCell = std::make_shared<Foundation::Cell>(orderMap.Name);

                Foundation::SPtrIdentity sptrOrderIdent = std::make_shared<Foundation::Identity>();
                sptrOrderIdent->setCell(sptrOrderIdCell);

                EXPECT_TRUE(sptrOrderIdent.get() != 0);

                Foundation::SPtrEntity sptrOrder = std::make_shared<Foundation::Entity>(sptrOrderIdent);
                sptrOrder->setCell(sptrCustmIdCell);
                sptrOrder->setCell(sptrOrderNameCell);

                EXPECT_TRUE(sptrOrder.get() != 0);

                Transformation::SPtrEntityTransformer orderTransformer{};
                Transformation::SPtrCellTransformerMap orderTransformMap = orderTransformer->CellTransformerMap();

            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_TRANSFORMATION_HPP
