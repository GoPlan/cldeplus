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

                Application::OrderMap orderMap{};
                Application::ProductMap productMap{};
                Application::CustomerMap customerMap{};

                auto sptrOrderId = Foundation::Type::cldeValueFactory::CreateInt64(1);
                auto sptrCustmId = Foundation::Type::cldeValueFactory::CreateInt64(2);
                auto sptrOrderName = Foundation::Type::cldeValueFactory::CreateVarChar(std::string{"My Order"});
                auto sptrTotal = Foundation::Type::cldeValueFactory::CreateDouble(15.0);

                auto sptrOrderIdCell = std::make_shared<Foundation::Cell>(orderMap.Id);
                auto sptrCustmIdCell = std::make_shared<Foundation::Cell>(orderMap.CustId);
                auto sptrOrderNameCell = std::make_shared<Foundation::Cell>(orderMap.Name, sptrOrderName);
                auto sptrTotalCell = std::make_shared<Foundation::Cell>(orderMap.Total, sptrTotal);

                // Prepare source proxy
                Foundation::SPtrEntityProxy sptrOrderProxy = std::make_shared<Foundation::EntityProxy>();
                sptrOrderProxy->setCell(sptrCustmIdCell);
                sptrOrderProxy->setCell(sptrOrderNameCell);
                sptrOrderProxy->setCell(sptrTotalCell);

                EXPECT_TRUE(sptrOrderProxy.get() != 0);

                // Prepare target proxy
                Foundation::SPtrColumn orderNewNameColumn = std::make_shared<Foundation::Column>("NewName", Foundation::Type::cldeValueType::VarChar);
                Foundation::SPtrColumn orderNewTotalColumn = std::make_shared<Foundation::Column>("NewTotal", Foundation::Type::cldeValueType::Double);
                Transformation::SPtrEntityTransformer orderTransformer = std::make_shared<Transformation::EntityTransformer>();
                Transformation::CellTransformerMap& transformerMap = orderTransformer->CellTransformerMap();
                transformerMap[orderMap.Name->getName()] = Transformation::CellTransformer{orderNewNameColumn};
                transformerMap[orderMap.Total->getName()] = Transformation::CellTransformer{orderNewTotalColumn};

                Foundation::SPtrEntityProxy sptrNewProxy = std::make_shared<Foundation::EntityProxy>();
                orderTransformer->Transform(sptrOrderProxy, sptrNewProxy);

                EXPECT_TRUE(sptrNewProxy.get() != 0);

                // Assert Name(VarChar) cell transformation
                {
                    Foundation::SPtrCell sptrNewProxyNameCell = sptrNewProxy->getCell("NewName");
                    Foundation::Type::Comparer::cldeValueCompare compare{};
                    Foundation::Type::Comparer::cldeValueLess less{};
                    Foundation::Type::Comparer::cldeValueGreater greater{};

                    EXPECT_TRUE(!less(sptrOrderName, sptrNewProxyNameCell->getValue()));
                    EXPECT_TRUE(!greater(sptrOrderName, sptrNewProxyNameCell->getValue()));
                    EXPECT_TRUE(compare(sptrOrderName, sptrNewProxyNameCell->getValue()));
                }

                // Assert Cost(VarChar) cell transformation
                {
                    Foundation::SPtrCell sptrNewProxyTotalCell = sptrNewProxy->getCell("NewTotal");
                    Foundation::Type::Comparer::cldeValueCompare compare{};
                    Foundation::Type::Comparer::cldeValueLess less{};
                    Foundation::Type::Comparer::cldeValueGreater greater{};

                    EXPECT_TRUE(!less(sptrTotal, sptrNewProxyTotalCell->getValue()));
                    EXPECT_TRUE(!greater(sptrTotal, sptrNewProxyTotalCell->getValue()));
                    EXPECT_TRUE(compare(sptrTotal, sptrNewProxyTotalCell->getValue()));
                }
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_TRANSFORMATION_HPP
