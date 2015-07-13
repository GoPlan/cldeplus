//
// Created by LE, Duc Anh on 6/19/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_SEGMENTATION_HPP
#define CLOUD_E_PLUS_APPTEST_SEGMENTATION_HPP

#include "gtest/gtest.h"
#include <memory>
#include <iostream>
#include <functional>
#include <Foundation/Foundation.h>
#include <Segmentation/Segmentation.h>
#include <Drivers/SQLite/SQLiteSourceDriver.h>
#include <AppTest/Application/EnquiryMap.h>
#include <AppTest/Application/CustomerMap.h>
#include <AppTest/Application/PreOrderMap.h>


namespace Cloude {
    namespace AppTest {
        namespace Segmentation {

            TEST(Segmentation, LEFT_INNER_JOIN_01) {

                Application::CustomerMap mapCustomer;
                Application::PreOrderMap mapPreOrder;

                Drivers::SQLite::SQLiteSourceDriver driverCustomer{mapCustomer};
                Drivers::SQLite::SQLiteSourceDriver driverOrder{mapPreOrder};

                Foundation::SPtrEntityStore sptrCustomerStore = std::make_shared<Foundation::EntityStore>(mapCustomer, driverCustomer);
                Foundation::SPtrEntityStore sptrOrderStore = std::make_shared<Foundation::EntityStore>(mapPreOrder, driverOrder);

                Foundation::EntityQuery queryCustomer{mapCustomer, driverCustomer};
                Foundation::EntityQuery queryOrder{mapPreOrder, driverOrder};

                driverCustomer.OptionArgs().ConnectionString = "example01.db";
                driverOrder.OptionArgs().ConnectionString = "example01.db";

                driverCustomer.Connect();
                driverOrder.Connect();

                // Select Customer set
                Foundation::Data::SPtrValue sptrCustomerId = Foundation::Data::ValueFactory::CreateInt64(0);
                Foundation::Query::SPtrCriteria sptrCustomerIdGt00(new Foundation::Query::Comparative::Greater(mapCustomer.Id, sptrCustomerId));
                Foundation::SPtrEntityProxyVector rsCustomer = queryCustomer.Select(sptrCustomerIdGt00);

                // Select Order set
                Foundation::Data::SPtrValue sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(10);
                Foundation::Query::SPtrCriteria sptrOrderIdGt00(new Foundation::Query::Comparative::LesserOrEqual(mapPreOrder.Id, sptrOrderId));
                Foundation::SPtrEntityProxyVector rsPreOrder = queryOrder.Select(sptrOrderIdGt00);

                Foundation::SPtrColumn newCustomerIdColumn = std::make_shared<Foundation::Column>("_custId", Foundation::Data::ValueType::Int64);
                Foundation::SPtrColumn newCustomerEmailColumn = std::make_shared<Foundation::Column>("customerEmail", Foundation::Data::ValueType::VarChar);
                Foundation::SPtrColumn newPreOrderIdColumn = std::make_shared<Foundation::Column>("preorderId", Foundation::Data::ValueType::Int64);
                Foundation::SPtrColumn newPreOrderTotalColumn = std::make_shared<Foundation::Column>("preorderTotal", Foundation::Data::ValueType::Double);

                Cloude::Segmentation::Transformation::CellTransformer customerIdCell{newCustomerIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer customerEmailCell{newCustomerEmailColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderIdCell{newPreOrderIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderTotalCell{newPreOrderTotalColumn};


                Cloude::Foundation::Store::Extra::EntityOutputFormatter formatter{};
                formatter.DisplayColumns().push_back(newPreOrderIdColumn);
                formatter.DisplayColumns().push_back(newPreOrderTotalColumn);
                formatter.DisplayColumns().push_back(newCustomerIdColumn);
                formatter.DisplayColumns().push_back(newCustomerEmailColumn);

                Foundation::Store::Comparer::Less cmp{};
                cmp.LhsCmpColumns().push_back(mapPreOrder.CustId);
                cmp.RhsCmpColumns().push_back(mapPreOrder.CustId);
                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);


                Cloude::Segmentation::Join::Inner joinInner{};
                joinInner.LhsComparingColumns().push_back(mapPreOrder.CustId);
                joinInner.RhsComparingColumns().push_back(mapCustomer.Id);
                joinInner.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinInner.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                joinInner.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinInner.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                Foundation::SPtrEntityProxyVector rsJoinInner = joinInner.Join(rsPreOrder, rsCustomer);
                EXPECT_TRUE(rsJoinInner.size() == 10);


                Cloude::Segmentation::Join::Left joinLeft{};
                joinLeft.LhsComparingColumns().push_back(mapPreOrder.CustId);
                joinLeft.RhsComparingColumns().push_back(mapCustomer.Id);
                joinLeft.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinLeft.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                joinLeft.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinLeft.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                Foundation::SPtrEntityProxyVector rsJoinLeft = joinLeft.Join(rsPreOrder, rsCustomer);
                EXPECT_TRUE(rsJoinLeft.size() * rsPreOrder.size());


                // Disconnect
                driverCustomer.Disconnect();
                driverOrder.Disconnect();
            }

            TEST(Segmentation, LEFT_JOIN_02){

                Application::CustomerMap mapCustomer;
                Application::PreOrderMap mapPreOrder;

                Drivers::SQLite::SQLiteSourceDriver driverCustomer{mapCustomer};
                Drivers::SQLite::SQLiteSourceDriver driverOrder{mapPreOrder};

                Foundation::SPtrEntityStore sptrCustomerStore = std::make_shared<Foundation::EntityStore>(mapCustomer, driverCustomer);
                Foundation::SPtrEntityStore sptrOrderStore = std::make_shared<Foundation::EntityStore>(mapPreOrder, driverOrder);

                Foundation::EntityQuery queryCustomer{mapCustomer, driverCustomer};
                Foundation::EntityQuery queryOrder{mapPreOrder, driverOrder};

                driverCustomer.OptionArgs().ConnectionString = "example01.db";
                driverOrder.OptionArgs().ConnectionString = "example01.db";

                driverCustomer.Connect();
                driverOrder.Connect();


                // Select Customer set
                Foundation::Data::SPtrValue sptrCustomerId = Foundation::Data::ValueFactory::CreateInt64(20);
                Foundation::Query::SPtrCriteria sptrCustomerIdGt00(new Foundation::Query::Comparative::Lesser(mapCustomer.Id, sptrCustomerId));
                Foundation::SPtrEntityProxyVector rsCustomer = queryCustomer.Select(sptrCustomerIdGt00);

                // Select Order set
                Foundation::Data::SPtrValue sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(0);
                Foundation::Query::SPtrCriteria sptrOrderIdGt00(new Foundation::Query::Comparative::Greater(mapPreOrder.Id, sptrOrderId));
                Foundation::SPtrEntityProxyVector rsPreOrder = queryOrder.Select(sptrOrderIdGt00);


                Foundation::SPtrColumn newCustomerIdColumn = std::make_shared<Foundation::Column>("_custId", Foundation::Data::ValueType::Int64);
                Foundation::SPtrColumn newCustomerEmailColumn = std::make_shared<Foundation::Column>("customerEmail", Foundation::Data::ValueType::VarChar);
                Foundation::SPtrColumn newPreOrderIdColumn = std::make_shared<Foundation::Column>("preorderId", Foundation::Data::ValueType::Int64);
                Foundation::SPtrColumn newPreOrderTotalColumn = std::make_shared<Foundation::Column>("preorderTotal", Foundation::Data::ValueType::Double);

                Cloude::Segmentation::Transformation::CellTransformer customerIdCell{newCustomerIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer customerEmailCell{newCustomerEmailColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderIdCell{newPreOrderIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderTotalCell{newPreOrderTotalColumn};

                Cloude::Foundation::Store::Extra::EntityOutputFormatter formatter{};
                formatter.DisplayColumns().push_back(newPreOrderIdColumn);
                formatter.DisplayColumns().push_back(newPreOrderTotalColumn);
                formatter.DisplayColumns().push_back(newCustomerIdColumn);
                formatter.DisplayColumns().push_back(newCustomerEmailColumn);


                // SORT
                Foundation::Store::Comparer::Less cmp{};
                cmp.LhsCmpColumns().push_back(mapPreOrder.CustId);
                cmp.RhsCmpColumns().push_back(mapPreOrder.CustId);
                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);

                // RIGHT JOIN
                Cloude::Segmentation::Join::Right joinRight{};
                joinRight.LhsComparingColumns().push_back(mapPreOrder.CustId);
                joinRight.RhsComparingColumns().push_back(mapCustomer.Id);
                joinRight.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinRight.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                joinRight.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinRight.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                Foundation::SPtrEntityProxyVector rsJoinRight = joinRight.Join(rsPreOrder, rsCustomer);
                EXPECT_TRUE(rsJoinRight.size() == 24);


                // Disconnect
                driverCustomer.Disconnect();
                driverOrder.Disconnect();
            }

            TEST(Segmentation, CROSS_JOIN){

                Application::CustomerMap mapCustomer;
                Application::PreOrderMap mapPreOrder;

                Drivers::SQLite::SQLiteSourceDriver driverCustomer{mapCustomer};
                Drivers::SQLite::SQLiteSourceDriver driverOrder{mapPreOrder};

                Foundation::SPtrEntityStore sptrCustomerStore = std::make_shared<Foundation::EntityStore>(mapCustomer, driverCustomer);
                Foundation::SPtrEntityStore sptrOrderStore = std::make_shared<Foundation::EntityStore>(mapPreOrder, driverOrder);

                Foundation::EntityQuery queryCustomer{mapCustomer, driverCustomer};
                Foundation::EntityQuery queryOrder{mapPreOrder, driverOrder};

                driverCustomer.OptionArgs().ConnectionString = "example01.db";
                driverOrder.OptionArgs().ConnectionString = "example01.db";

                driverCustomer.Connect();
                driverOrder.Connect();

                // Select Customer set
                Foundation::Data::SPtrValue sptrCustomerId = Foundation::Data::ValueFactory::CreateInt64(10);
                Foundation::Query::SPtrCriteria sptrCustomerIdGt00(new Foundation::Query::Comparative::Lesser(mapCustomer.Id, sptrCustomerId));
                Foundation::SPtrEntityProxyVector rsCustomer = queryCustomer.Select(sptrCustomerIdGt00);

                // Select Order set
                Foundation::Data::SPtrValue sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(10);
                Foundation::Query::SPtrCriteria sptrOrderIdGt00(new Foundation::Query::Comparative::Lesser(mapPreOrder.Id, sptrOrderId));
                Foundation::SPtrEntityProxyVector rsPreOrder = queryOrder.Select(sptrOrderIdGt00);

                Foundation::SPtrColumn newCustomerIdColumn = std::make_shared<Foundation::Column>("_custId", Foundation::Data::ValueType::Int64);
                Foundation::SPtrColumn newCustomerEmailColumn = std::make_shared<Foundation::Column>("customerEmail", Foundation::Data::ValueType::VarChar);
                Foundation::SPtrColumn newPreOrderIdColumn = std::make_shared<Foundation::Column>("preorderId", Foundation::Data::ValueType::Int64);
                Foundation::SPtrColumn newPreOrderTotalColumn = std::make_shared<Foundation::Column>("preorderTotal", Foundation::Data::ValueType::Double);

                Cloude::Segmentation::Transformation::CellTransformer customerIdCell{newCustomerIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer customerEmailCell{newCustomerEmailColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderIdCell{newPreOrderIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderTotalCell{newPreOrderTotalColumn};

                Cloude::Foundation::Store::Extra::EntityOutputFormatter formatter{};
                formatter.DisplayColumns().push_back(newPreOrderIdColumn);
                formatter.DisplayColumns().push_back(newPreOrderTotalColumn);
                formatter.DisplayColumns().push_back(newCustomerIdColumn);
                formatter.DisplayColumns().push_back(newCustomerEmailColumn);

                Foundation::Store::Comparer::Less cmp{};
                cmp.LhsCmpColumns().push_back(mapPreOrder.CustId);
                cmp.RhsCmpColumns().push_back(mapPreOrder.CustId);
                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);

                Cloude::Segmentation::Join::Cross crossJoin{};
                crossJoin.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                crossJoin.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                crossJoin.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                crossJoin.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                Foundation::SPtrEntityProxyVector rsCrossJoin = crossJoin.Join(rsPreOrder, rsCustomer);
                EXPECT_TRUE(rsCrossJoin.size() == rsPreOrder.size() * rsCustomer.size());

                // Disconnect
                driverCustomer.Disconnect();
                driverOrder.Disconnect();
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_SEGMENTATION_HPP
