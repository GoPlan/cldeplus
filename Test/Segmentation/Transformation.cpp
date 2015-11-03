//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLDEPLUS_APPTEST_TRANSFORMATION_HPP
#define CLDEPLUS_APPTEST_TRANSFORMATION_HPP

#include <gtest/gtest.h>

#include "../../Source/Foundation/Foundation.h"
#include "../../Source/Segmentation/Segmentation.h"

#include "../Application/MapFactory.h"
#include "../Application/ProductMap.h"
#include "../Application/PreOrderMap.h"
#include "../Application/CustomerMap.h"

namespace CLDEPlus {
    namespace Test {
        namespace Segmentation {

            using namespace CLDEPlus::Segmentation;

            TEST(Transformation, case01) {

                Application::PreOrderMap orderMap{};
                Application::ProductMap productMap{};
                Application::CustomerMap customerMap{};

                auto sptrPreOrderMap = Application::Create<Application::PreOrderMap>();
                auto sptrProductMap = Application::Create<Application::ProductMap>();
                auto sptrCustomerMap = Application::Create<Application::CustomerMap>();

                auto sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(1);
                auto sptrCustmId = Foundation::Data::ValueFactory::CreateInt64(2);
                auto sptrOrderName = Foundation::Data::ValueFactory::CreateVarChar(std::string{"My Order"});
                auto sptrTotal = Foundation::Data::ValueFactory::CreateDouble(15.0);

                auto sptrOrderIdCell = (Foundation::SPtrCell)Foundation::Cell::Create(sptrPreOrderMap->GetColumn("Id"));
                auto sptrCustmIdCell = (Foundation::SPtrCell)Foundation::Cell::Create(sptrPreOrderMap->GetColumn("CustId"));
                auto sptrOrderNameCell = (Foundation::SPtrCell)Foundation::Cell::Create(sptrPreOrderMap->GetColumn("Name"), sptrOrderName);
                auto sptrTotalCell = (Foundation::SPtrCell)Foundation::Cell::Create(sptrPreOrderMap->GetColumn("Total"), sptrTotal);

                // Prepare source proxy
                auto sptrEntityProxy = (Foundation::SPtrEntityProxy) Foundation::EntityProxy::Create();
                sptrEntityProxy->setCell(sptrCustmIdCell);
                sptrEntityProxy->setCell(sptrOrderNameCell);
                sptrEntityProxy->setCell(sptrTotalCell);

                // Double (Type) Caster
                auto sptrDoubleConverter = CasterFactory::CreateDoubleCaster();
                auto sptrInt64Total = sptrDoubleConverter->Cast(Foundation::Data::ValueType::Int64, sptrTotal);

                // Entity Transformer
                auto orderNewNameColumn = Foundation::CreateColumn("NewName", Foundation::Data::ValueType::VarChar);
                auto orderNewTotalColumn = Foundation::CreateColumn("NewTotal", Foundation::Data::ValueType::Int64);

                auto uptrOrderTransformer = Segmentation::Transformation::CreateEntityTransformerInstance();
                uptrOrderTransformer->AddCellTransformer(sptrPreOrderMap->GetColumn("Name")->getName(), Transformation::CellTransformer{orderNewNameColumn});
                uptrOrderTransformer->AddCellTransformer(sptrPreOrderMap->GetColumn("Total")->getName(), Transformation::CellTransformer{orderNewTotalColumn, sptrDoubleConverter});

                // Transforming Order into a new entity
                auto sptrNewProxy = (Foundation::SPtrEntityProxy)Foundation::EntityProxy::Create();
                uptrOrderTransformer->Transform(sptrEntityProxy, sptrNewProxy);

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

#endif //CLDEPLUS_APPTEST_TRANSFORMATION_HPP
