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
#include <Foundation/Type/Comparer/cldeValueComparer.h>
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
                auto sptrOrderNameCell = std::make_shared<Foundation::Cell>(orderMap.Name, sptrOrderName);

                // Prepare source proxy
                Foundation::SPtrEntityProxy sptrOrderProxy = std::make_shared<Foundation::EntityProxy>();
                sptrOrderProxy->setCell(sptrCustmIdCell);
                sptrOrderProxy->setCell(sptrOrderNameCell);

                EXPECT_TRUE(sptrOrderProxy.get() != 0);

                // Prepare target proxy
                Foundation::SPtrColumn orderNewColumn = std::make_shared<Foundation::Column>("NewName", Foundation::Type::cldeValueType::VarChar);
                Transformation::SPtrEntityTransformer orderTransformer = std::make_shared<Transformation::EntityTransformer>();
                orderTransformer->CellTransformerMap()[orderMap.Name->getName()] = Transformation::CellTransformer{orderNewColumn};

                Foundation::SPtrEntityProxy sptrNewProxy = std::make_shared<Foundation::EntityProxy>();
                orderTransformer->Transform(sptrOrderProxy, sptrNewProxy);

                Foundation::SPtrCell sptrNewProxyNameCell = sptrNewProxy->getCell("NewName");
                Foundation::Type::Comparer::cldeValueCompare compare{};
                Foundation::Type::Comparer::cldeValueLess less{};
                Foundation::Type::Comparer::cldeValueGreater greater{};

                EXPECT_TRUE(sptrNewProxy.get() != 0);
                EXPECT_TRUE(!less(sptrOrderName, sptrNewProxyNameCell->getValue()));
                EXPECT_TRUE(!greater(sptrOrderName, sptrNewProxyNameCell->getValue()));
                EXPECT_TRUE(compare(sptrOrderName, sptrNewProxyNameCell->getValue()));
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_TRANSFORMATION_HPP
