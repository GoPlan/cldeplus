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
#include <Foundation/Data/Comparer/Comparer.h>
#include <Segmentation/Transformation/Transformation.h>

namespace Cloude {
    namespace AppTest {
        namespace Segmentation {

            TEST(Transformation, case01) {

                using namespace Cloude::Segmentation;

                Application::OrderMap orderMap{};
                Application::ProductMap productMap{};
                Application::CustomerMap customerMap{};

                auto sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(1);
                auto sptrCustmId = Foundation::Data::ValueFactory::CreateInt64(2);
                auto sptrOrderName = Foundation::Data::ValueFactory::CreateVarChar(std::string{"My Order"});
                auto sptrTotal = Foundation::Data::ValueFactory::CreateDouble(15.0);

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
                Foundation::SPtrColumn orderNewNameColumn = std::make_shared<Foundation::Column>("NewName", Foundation::Data::ValueType::VarChar);
                Foundation::SPtrColumn orderNewTotalColumn = std::make_shared<Foundation::Column>("NewTotal", Foundation::Data::ValueType::Double);
                Transformation::SPtrEntityTransformer orderTransformer = std::make_shared<Transformation::EntityTransformer>();
                orderTransformer->AddCellTransformer(orderMap.Name->getName(),Transformation::CellTransformer{orderNewNameColumn});
                orderTransformer->AddCellTransformer(orderMap.Total->getName(),Transformation::CellTransformer{orderNewTotalColumn});

                Foundation::SPtrEntityProxy sptrNewProxy = std::make_shared<Foundation::EntityProxy>();
                orderTransformer->Transform(sptrOrderProxy, sptrNewProxy);

                EXPECT_TRUE(sptrNewProxy.get() != 0);

                // Assert Name(VarChar) cell transformation
                {
                    Foundation::SPtrCell sptrNewProxyNameCell = sptrNewProxy->getCell("NewName");
                    Foundation::Data::Comparer::Compare eq{};
                    Foundation::Data::Comparer::Less lt{};
                    Foundation::Data::Comparer::Greater gt{};

                    EXPECT_TRUE(!lt(sptrOrderName, sptrNewProxyNameCell->getValue()));
                    EXPECT_TRUE(!gt(sptrOrderName, sptrNewProxyNameCell->getValue()));
                    EXPECT_TRUE(eq(sptrOrderName, sptrNewProxyNameCell->getValue()));
                }

                // Assert Cost(VarChar) cell transformation
                {
                    Foundation::SPtrCell sptrNewProxyTotalCell = sptrNewProxy->getCell("NewTotal");
                    Foundation::Data::Comparer::Compare eq{};
                    Foundation::Data::Comparer::Less lt{};
                    Foundation::Data::Comparer::Greater gt{};

                    EXPECT_TRUE(!lt(sptrTotal, sptrNewProxyTotalCell->getValue()));
                    EXPECT_TRUE(!gt(sptrTotal, sptrNewProxyTotalCell->getValue()));
                    EXPECT_TRUE(eq(sptrTotal, sptrNewProxyTotalCell->getValue()));
                }
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_TRANSFORMATION_HPP
