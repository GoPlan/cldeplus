//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_TRANSFORMATION_HPP
#define CLOUD_E_PLUS_APPTEST_TRANSFORMATION_HPP

#include "gtest/gtest.h"
#include <memory>
#include <iostream>
#include <functional>

#include <Foundation/Foundation.h>
#include <Foundation/Data/Comparer/Comparer.h>
#include <Segmentation/Segmentation.h>

#include "../Application/ProductMap.h"
#include "../Application/PreOrderMap.h"
#include "../Application/CustomerMap.h"

namespace Cloude {
    namespace Test {
        namespace Segmentation {

            using namespace Cloude::Segmentation;

            TEST(Transformation, case01) {

                Application::PreOrderMap orderMap{};
                Application::ProductMap productMap{};
                Application::CustomerMap customerMap{};

                auto sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(1);
                auto sptrCustmId = Foundation::Data::ValueFactory::CreateInt64(2);
                auto sptrOrderName = Foundation::Data::ValueFactory::CreateVarChar(std::string{"My Order"});
                auto sptrTotal = Foundation::Data::ValueFactory::CreateDouble(15.0);

                auto sptrOrderIdCell = Foundation::CreateCell(orderMap.Id);
                auto sptrCustmIdCell = Foundation::CreateCell(orderMap.CustId);
                auto sptrOrderNameCell = Foundation::CreateCell(orderMap.Name, sptrOrderName);
                auto sptrTotalCell = Foundation::CreateCell(orderMap.Total, sptrTotal);

                // Prepare source proxy
                auto sptrOrderProxy = Foundation::CreateEntityProxy();
                sptrOrderProxy->setCell(sptrCustmIdCell);
                sptrOrderProxy->setCell(sptrOrderNameCell);
                sptrOrderProxy->setCell(sptrTotalCell);

                // Double (Type) Caster
                auto sptrDoubleConverter = CasterFactory::CreateDoubleConverter();
                auto sptrInt64Total = sptrDoubleConverter->Cast(Foundation::Data::ValueType::Int64, sptrTotal);

                // Entity Transformer
                auto orderNewNameColumn = Foundation::CreateColumn("NewName", Foundation::Data::ValueType::VarChar);
                auto orderNewTotalColumn = Foundation::CreateColumn("NewTotal", Foundation::Data::ValueType::Int64);

                auto orderTransformer = Segmentation::Transformation::CreateEntityTransformer();
                orderTransformer->AddCellTransformer(orderMap.Name->getName(),
                                                     Transformation::CellTransformer{orderNewNameColumn});
                orderTransformer->AddCellTransformer(orderMap.Total->getName(),
                                                     Transformation::CellTransformer{orderNewTotalColumn,
                                                                                     sptrDoubleConverter});

                // Transforming Order into a new entity
                auto sptrNewProxy = Foundation::CreateEntityProxy();
                orderTransformer->Transform(sptrOrderProxy, sptrNewProxy);

                EXPECT_TRUE(sptrNewProxy.get() != 0);

                // Assert Cost(Double) cell transformation
                {
                    auto sptrNewProxyTotalCell = sptrNewProxy->getCell("NewTotal");
                    Foundation::Data::Comparer::Compare compare{};
                    Foundation::Data::Comparer::Less lesser{};
                    Foundation::Data::Comparer::Greater greater{};

                    EXPECT_TRUE(!lesser(sptrInt64Total, sptrNewProxyTotalCell->getValue()));
                    EXPECT_TRUE(!greater(sptrInt64Total, sptrNewProxyTotalCell->getValue()));
                    EXPECT_TRUE(compare(sptrInt64Total, sptrNewProxyTotalCell->getValue()));
                    EXPECT_TRUE(sptrNewProxyTotalCell->getColumn()->ToString().length() > 0);
                }

                // Assert Name(VarChar) cell transformation
                {
                    auto sptrNewProxyNameCell = sptrNewProxy->getCell("NewName");
                    Foundation::Data::Comparer::Compare compare{};
                    Foundation::Data::Comparer::Less lesser{};
                    Foundation::Data::Comparer::Greater greater{};

                    EXPECT_TRUE(!lesser(sptrOrderName, sptrNewProxyNameCell->getValue()));
                    EXPECT_TRUE(!greater(sptrOrderName, sptrNewProxyNameCell->getValue()));
                    EXPECT_TRUE(compare(sptrOrderName, sptrNewProxyNameCell->getValue()));
                    EXPECT_TRUE(sptrNewProxyNameCell->getColumn()->ToString().length() > 0);
                }
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_TRANSFORMATION_HPP
