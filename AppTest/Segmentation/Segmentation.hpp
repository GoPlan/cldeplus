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

                using CmpFactory = Foundation::Query::ComparativeFactory;

                Application::CustomerMap mapCustomer;
                Application::PreOrderMap mapPreOrder;

                Drivers::SQLite::SQLiteSourceDriver driverCustomer{mapCustomer};
                Drivers::SQLite::SQLiteSourceDriver driverOrder{mapPreOrder};

                auto sptrCustomerStore = Foundation::CreateEntityStore(mapCustomer, driverCustomer);
                auto sptrOrderStore = Foundation::CreateEntityStore(mapPreOrder, driverOrder);

                Foundation::EntityQuery queryCustomer{mapCustomer, driverCustomer};
                Foundation::EntityQuery queryOrder{mapPreOrder, driverOrder};

                driverCustomer.OptionArgs().ConnectionString = "example01.db";
                driverOrder.OptionArgs().ConnectionString = "example01.db";

                driverCustomer.Connect();
                driverOrder.Connect();

                // Select Customer set
                auto sptrCustomerId = Foundation::Data::ValueFactory::CreateInt64(0);
                auto sptrCustomerIdGt00 = CmpFactory::CreateGTE(mapCustomer.Id, sptrCustomerId);
                auto rsCustomer = queryCustomer.Select(sptrCustomerIdGt00);

                // Select Order set
                auto sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(10);
                auto sptrOrderIdGt00 = CmpFactory::CreateLTE(mapPreOrder.Id, sptrOrderId);
                auto rsPreOrder = queryOrder.Select(sptrOrderIdGt00);

                auto newCustomerIdColumn = Foundation::CreateColumn("_custId", Foundation::Data::ValueType::Int64);
                auto newCustomerEmailColumn = Foundation::CreateColumn("customerEmail", Foundation::Data::ValueType::VarChar);
                auto newPreOrderIdColumn = Foundation::CreateColumn("preorderId", Foundation::Data::ValueType::Int64);
                auto newPreOrderTotalColumn = Foundation::CreateColumn("preorderTotal", Foundation::Data::ValueType::Double);

                Cloude::Segmentation::Transformation::CellTransformer customerIdCell{newCustomerIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer customerEmailCell{newCustomerEmailColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderIdCell{newPreOrderIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderTotalCell{newPreOrderTotalColumn};

                Cloude::Foundation::Store::Extra::EntityOutputFormatter formatter{};
                formatter.DisplayColumns().push_back(newPreOrderIdColumn);
                formatter.DisplayColumns().push_back(newPreOrderTotalColumn);
                formatter.DisplayColumns().push_back(newCustomerIdColumn);
                formatter.DisplayColumns().push_back(newCustomerEmailColumn);

                // SORT PreOrder
                Foundation::Store::Comparer::Less cmp{};
                cmp.LhsCmpColumns().push_back(mapPreOrder.CustId);
                cmp.RhsCmpColumns().push_back(mapPreOrder.CustId);
                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);


                // INNER JOIN - PREORDER <> CUSTOMER
                Cloude::Segmentation::Join::Inner joinInner{};
                joinInner.LhsComparingColumns().push_back(mapPreOrder.CustId);
                joinInner.RhsComparingColumns().push_back(mapCustomer.Id);
                joinInner.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinInner.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                joinInner.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinInner.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                Foundation::SPtrEntityProxyVector rsJoinInner = joinInner.Join(rsPreOrder, rsCustomer);
                EXPECT_TRUE(rsJoinInner.size() == 10);
                for (auto &item : rsJoinInner) {
                    std::cout << item->ToString() << std::endl;
                }


                // LEFT JOIN - PREORDER <> CUSTOMER
                Cloude::Segmentation::Join::Left joinLeft{};
                joinLeft.LhsComparingColumns().push_back(mapPreOrder.CustId);
                joinLeft.RhsComparingColumns().push_back(mapCustomer.Id);
                joinLeft.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinLeft.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                joinLeft.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinLeft.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                Foundation::SPtrEntityProxyVector rsJoinLeft = joinLeft.Join(rsPreOrder, rsCustomer);
                EXPECT_TRUE(rsJoinLeft.size() == rsPreOrder.size());
                for (auto &item : rsJoinLeft) {
                    std::cout << item->ToString() << std::endl;
                }

                // Disconnect
                driverCustomer.Disconnect();
                driverOrder.Disconnect();
            }

            TEST(Segmentation, RIGHT_JOIN_01) {

                using CmpFactory = Foundation::Query::ComparativeFactory;

                Application::CustomerMap mapCustomer;
                Application::PreOrderMap mapPreOrder;

                Drivers::SQLite::SQLiteSourceDriver driverCustomer{mapCustomer};
                Drivers::SQLite::SQLiteSourceDriver driverOrder{mapPreOrder};

                auto sptrCustomerStore = Foundation::CreateEntityStore(mapCustomer, driverCustomer);
                auto sptrOrderStore = Foundation::CreateEntityStore(mapPreOrder, driverOrder);

                Foundation::EntityQuery queryCustomer{mapCustomer, driverCustomer};
                Foundation::EntityQuery queryOrder{mapPreOrder, driverOrder};

                driverCustomer.OptionArgs().ConnectionString = "example01.db";
                driverOrder.OptionArgs().ConnectionString = "example01.db";

                driverCustomer.Connect();
                driverOrder.Connect();

                // Select Customer set
                auto sptrCustomerId = Foundation::Data::ValueFactory::CreateInt64(20);
                auto sptrCustomerIdGt00 = CmpFactory::CreateLT(mapCustomer.Id, sptrCustomerId);
                auto rsCustomer = queryCustomer.Select(sptrCustomerIdGt00);

                // Select Order set
                auto sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(0);
                auto sptrOrderIdGt00 = CmpFactory::CreateGTE(mapPreOrder.Id, sptrOrderId);
                auto rsPreOrder = queryOrder.Select(sptrOrderIdGt00);

                auto newCustomerIdColumn = Foundation::CreateColumn("_custId", Foundation::Data::ValueType::Int64);
                auto newCustomerEmailColumn = Foundation::CreateColumn("customerEmail", Foundation::Data::ValueType::VarChar);
                auto newPreOrderIdColumn = Foundation::CreateColumn("preorderId", Foundation::Data::ValueType::Int64);
                auto newPreOrderTotalColumn = Foundation::CreateColumn("preorderTotal", Foundation::Data::ValueType::Double);

                Cloude::Segmentation::Transformation::CellTransformer customerIdCell{newCustomerIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer customerEmailCell{newCustomerEmailColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderIdCell{newPreOrderIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderTotalCell{newPreOrderTotalColumn};

                Cloude::Foundation::Store::Extra::EntityOutputFormatter formatter{};
                formatter.DisplayColumns().push_back(newPreOrderIdColumn);
                formatter.DisplayColumns().push_back(newPreOrderTotalColumn);
                formatter.DisplayColumns().push_back(newCustomerIdColumn);
                formatter.DisplayColumns().push_back(newCustomerEmailColumn);

                // SORT PreOrder
                Foundation::Store::Comparer::Less cmp{};
                cmp.LhsCmpColumns().push_back(mapPreOrder.CustId);
                cmp.RhsCmpColumns().push_back(mapPreOrder.CustId);
                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);


                // RIGHT JOIN - PREORDER <> CUSTOMER
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

            TEST(Segmentation, CROSS_JOIN) {

                using CmpFactory = Foundation::Query::ComparativeFactory;

                Application::CustomerMap mapCustomer;
                Application::PreOrderMap mapPreOrder;

                Drivers::SQLite::SQLiteSourceDriver driverCustomer{mapCustomer};
                Drivers::SQLite::SQLiteSourceDriver driverOrder{mapPreOrder};

                auto sptrCustomerStore = Foundation::CreateEntityStore(mapCustomer, driverCustomer);
                auto sptrOrderStore = Foundation::CreateEntityStore(mapPreOrder, driverOrder);

                Foundation::EntityQuery queryCustomer{mapCustomer, driverCustomer};
                Foundation::EntityQuery queryOrder{mapPreOrder, driverOrder};

                driverCustomer.OptionArgs().ConnectionString = "example01.db";
                driverOrder.OptionArgs().ConnectionString = "example01.db";

                driverCustomer.Connect();
                driverOrder.Connect();

                // Select Customer set
                auto sptrCustomerId = Foundation::Data::ValueFactory::CreateInt64(0);
                auto sptrCustomerIdGt00 = CmpFactory::CreateGTE(mapCustomer.Id, sptrCustomerId);
                auto rsCustomer = queryCustomer.Select(sptrCustomerIdGt00);

                // Select Order set
                auto sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(10);
                auto sptrOrderIdGt00 = CmpFactory::CreateLTE(mapPreOrder.Id, sptrOrderId);
                auto rsPreOrder = queryOrder.Select(sptrOrderIdGt00);

                auto newCustomerIdColumn = Foundation::CreateColumn("_custId", Foundation::Data::ValueType::Int64);
                auto newCustomerEmailColumn = Foundation::CreateColumn("customerEmail", Foundation::Data::ValueType::VarChar);
                auto newPreOrderIdColumn = Foundation::CreateColumn("preorderId", Foundation::Data::ValueType::Int64);
                auto newPreOrderTotalColumn = Foundation::CreateColumn("preorderTotal", Foundation::Data::ValueType::Double);

                Cloude::Segmentation::Transformation::CellTransformer customerIdCell{newCustomerIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer customerEmailCell{newCustomerEmailColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderIdCell{newPreOrderIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderTotalCell{newPreOrderTotalColumn};

                Cloude::Foundation::Store::Extra::EntityOutputFormatter formatter{};
                formatter.DisplayColumns().push_back(newPreOrderIdColumn);
                formatter.DisplayColumns().push_back(newPreOrderTotalColumn);
                formatter.DisplayColumns().push_back(newCustomerIdColumn);
                formatter.DisplayColumns().push_back(newCustomerEmailColumn);

                // SORT PreOrder
                Foundation::Store::Comparer::Less cmp{};
                cmp.LhsCmpColumns().push_back(mapPreOrder.CustId);
                cmp.RhsCmpColumns().push_back(mapPreOrder.CustId);
                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);

                // CROSSJOIN - PREORDER <> CUSTOMER
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
