//
// Created by LE, Duc Anh on 6/19/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_SEGMENTATION_HPP
#define CLOUD_E_PLUS_APPTEST_SEGMENTATION_HPP

#include <gtest/gtest.h>
#include <memory>
#include <iostream>
#include <functional>

#include "../../Source/Foundation/Foundation.h"
#include "../../Source/Segmentation/Segmentation.h"
#include "../../Source/Drivers/SQLite/SQLiteSourceDriver.h"
#include "../../Source/Drivers/MySql/MySqlSourceDriver.h"

#include "../Application/EnquiryMap.h"
#include "../Application/CustomerMap.h"
#include "../Application/PreOrderMap.h"
#include "../Application/MapFactory.h"

namespace Cloude {
    namespace Test {
        namespace Segmentation {

            TEST(Segmentation, LEFT_INNER_JOIN_01) {

                using CmpFactory = Foundation::Query::ComparativeFactory;

                auto sptrCustomerMap = Application::Create<Application::CustomerMap>();
                auto sptrPreOrderMap = Application::Create<Application::PreOrderMap>();
                auto sptrCustomerDriver = Drivers::SQLite::SQLiteSourceDriver::Create(sptrCustomerMap);
                auto sptrPreOrderDriver = Drivers::MySql::MySqlSourceDriver::Create(sptrPreOrderMap);

                auto sptrCustomerStore = Foundation::CreateEntityStore(sptrCustomerMap, sptrCustomerDriver);
                auto sptrCustomerQuery = Foundation::CreateEntityQuery(sptrCustomerMap, sptrCustomerDriver);
                auto sptrOrderStore = Foundation::CreateEntityStore(sptrPreOrderMap, sptrPreOrderDriver);
                auto sptrOrderQuery = Foundation::CreateEntityQuery(sptrPreOrderMap, sptrPreOrderDriver);

                sptrCustomerDriver->OptionArgs().ConnectionString = "example01.db";
                sptrCustomerDriver->Connect();

                sptrPreOrderDriver->OptionArgs().Host = "dell-3020";
                sptrPreOrderDriver->OptionArgs().User = "cloud-e";
                sptrPreOrderDriver->OptionArgs().Pass = "cloud-e";
                sptrPreOrderDriver->OptionArgs().Base = "cloud-e";
                sptrPreOrderDriver->OptionArgs().Port = 3306;
                sptrPreOrderDriver->Connect();

                // Select Customer set
                auto sptrCustomerId = Foundation::Data::ValueFactory::CreateInt64(0);
                auto sptrCustomerIdGt00 = CmpFactory::CreateGTE(sptrCustomerMap->Id, sptrCustomerId);
                auto rsCustomer = sptrCustomerQuery->Select(sptrCustomerIdGt00);

                // Select Order set
                auto sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(10);
                auto sptrOrderIdGt00 = CmpFactory::CreateLTE(sptrPreOrderMap->Id, sptrOrderId);
                auto rsPreOrder = sptrOrderQuery->Select(sptrOrderIdGt00);

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
                cmp.LhsCmpColumns().push_back(sptrPreOrderMap->CustId);
                cmp.RhsCmpColumns().push_back(sptrPreOrderMap->CustId);
                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);

                // INNER JOIN - PREORDER <> CUSTOMER
                Cloude::Segmentation::Join::Inner joinInner{};
                joinInner.LhsComparingColumns().push_back(sptrPreOrderMap->CustId);
                joinInner.RhsComparingColumns().push_back(sptrCustomerMap->Id);
                joinInner.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinInner.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                joinInner.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinInner.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                auto rsJoinInner = joinInner.Join(rsPreOrder, rsCustomer);
                EXPECT_TRUE(rsJoinInner.size() == 10);
                for (auto &item : rsJoinInner) {
                    EXPECT_TRUE(item->ToString().length() > 0);
                }

                // LEFT JOIN - PREORDER <> CUSTOMER
                Cloude::Segmentation::Join::Left joinLeft{};
                joinLeft.LhsComparingColumns().push_back(sptrPreOrderMap->CustId);
                joinLeft.RhsComparingColumns().push_back(sptrCustomerMap->Id);
                joinLeft.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinLeft.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                joinLeft.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinLeft.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                auto rsJoinLeft = joinLeft.Join(rsPreOrder, rsCustomer);
                EXPECT_TRUE(rsJoinLeft.size() == rsPreOrder.size());
                for (auto &item : rsJoinLeft) {
                    EXPECT_TRUE(item->ToString().length() > 0);
                }

                // Disconnect
                sptrCustomerDriver->Disconnect();
                sptrPreOrderDriver->Disconnect();
            }

            TEST(Segmentation, RIGHT_JOIN_01) {

                using CmpFactory = Foundation::Query::ComparativeFactory;

                auto sptrCustomerMap = Application::Create<Application::CustomerMap>();
                auto sptrPreOrderMap = Application::Create<Application::PreOrderMap>();
                auto sptrCustomerDriver = Drivers::SQLite::SQLiteSourceDriver::Create(sptrCustomerMap);
                auto sptrPreOrderDriver = Drivers::MySql::MySqlSourceDriver::Create(sptrPreOrderMap);

                auto sptrCustomerStore = Foundation::CreateEntityStore(sptrCustomerMap, sptrCustomerDriver);
                auto sptrCustomerQuery = Foundation::CreateEntityQuery(sptrCustomerMap, sptrCustomerDriver);
                auto sptrOrderStore = Foundation::CreateEntityStore(sptrPreOrderMap, sptrPreOrderDriver);
                auto sptrOrderQuery = Foundation::CreateEntityQuery(sptrPreOrderMap, sptrPreOrderDriver);

                sptrCustomerDriver->OptionArgs().ConnectionString = "example01.db";
                sptrCustomerDriver->Connect();

                sptrPreOrderDriver->OptionArgs().Host = "dell-3020";
                sptrPreOrderDriver->OptionArgs().User = "cloud-e";
                sptrPreOrderDriver->OptionArgs().Pass = "cloud-e";
                sptrPreOrderDriver->OptionArgs().Base = "cloud-e";
                sptrPreOrderDriver->OptionArgs().Port = 3306;
                sptrPreOrderDriver->Connect();

                // Select Customer set
                auto sptrCustomerId = Foundation::Data::ValueFactory::CreateInt64(20);
                auto sptrCustomerIdLTE20 = CmpFactory::CreateLTE(sptrCustomerMap->Id, sptrCustomerId);
                auto rsCustomer = sptrCustomerQuery->Select(sptrCustomerIdLTE20);

                // Select Order set
                auto sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(0);
                auto sptrOrderIdGt00 = CmpFactory::CreateGTE(sptrPreOrderMap->Id, sptrOrderId);
                auto rsPreOrder = sptrOrderQuery->Select(sptrOrderIdGt00);

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
                cmp.LhsCmpColumns().push_back(sptrPreOrderMap->CustId);
                cmp.RhsCmpColumns().push_back(sptrPreOrderMap->CustId);
                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);

                // RIGHT JOIN - PREORDER <> CUSTOMER
                Cloude::Segmentation::Join::Right joinRight{};
                joinRight.LhsComparingColumns().push_back(sptrPreOrderMap->CustId);
                joinRight.RhsComparingColumns().push_back(sptrCustomerMap->Id);
                joinRight.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinRight.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                joinRight.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinRight.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                auto rsJoinRight = joinRight.Join(rsPreOrder, rsCustomer);
                EXPECT_TRUE(rsJoinRight.size() >= 20);

                // Disconnect
                sptrCustomerDriver->Disconnect();
                sptrPreOrderDriver->Disconnect();
            }

            TEST(Segmentation, CROSS_JOIN) {

                using CmpFactory = Foundation::Query::ComparativeFactory;

                auto sptrCustomerMap = Application::Create<Application::CustomerMap>();
                auto sptrPreOrderMap = Application::Create<Application::PreOrderMap>();
                auto sptrCustomerDriver = Drivers::SQLite::SQLiteSourceDriver::Create(sptrCustomerMap);
                auto sptrPreOrderDriver = Drivers::MySql::MySqlSourceDriver::Create(sptrPreOrderMap);

                auto sptrCustomerStore = Foundation::CreateEntityStore(sptrCustomerMap, sptrCustomerDriver);
                auto sptrCustomerQuery = Foundation::CreateEntityQuery(sptrCustomerMap, sptrCustomerDriver);
                auto sptrOrderStore = Foundation::CreateEntityStore(sptrPreOrderMap, sptrPreOrderDriver);
                auto sptrOrderQuery = Foundation::CreateEntityQuery(sptrPreOrderMap, sptrPreOrderDriver);

                sptrCustomerDriver->OptionArgs().ConnectionString = "example01.db";
                sptrCustomerDriver->Connect();

                sptrPreOrderDriver->OptionArgs().Host = "dell-3020";
                sptrPreOrderDriver->OptionArgs().User = "cloud-e";
                sptrPreOrderDriver->OptionArgs().Pass = "cloud-e";
                sptrPreOrderDriver->OptionArgs().Base = "cloud-e";
                sptrPreOrderDriver->OptionArgs().Port = 3306;
                sptrPreOrderDriver->Connect();

                // Select Customer set
                auto sptrCustomerId = Foundation::Data::ValueFactory::CreateInt64(0);
                auto sptrCustomerIdGt00 = CmpFactory::CreateGTE(sptrCustomerMap->Id, sptrCustomerId);
                auto rsCustomer = sptrCustomerQuery->Select(sptrCustomerIdGt00);

                // Select Order set
                auto sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(10);
                auto sptrOrderIdGt00 = CmpFactory::CreateLTE(sptrPreOrderMap->Id, sptrOrderId);
                auto rsPreOrder = sptrOrderQuery->Select(sptrOrderIdGt00);

                auto newCustomerIdColumn = Foundation::CreateColumn("_custId", Foundation::Data::ValueType::Int64);
                auto newCustomerEmailColumn = Foundation::CreateColumn("customerEmail",
                                                                       Foundation::Data::ValueType::VarChar);
                auto newPreOrderIdColumn = Foundation::CreateColumn("preorderId", Foundation::Data::ValueType::Int64);
                auto newPreOrderTotalColumn = Foundation::CreateColumn("preorderTotal",
                                                                       Foundation::Data::ValueType::Double);

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
                cmp.LhsCmpColumns().push_back(sptrPreOrderMap->CustId);
                cmp.RhsCmpColumns().push_back(sptrPreOrderMap->CustId);
                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);

                // CROSSJOIN - PREORDER <> CUSTOMER
                Cloude::Segmentation::Join::Cross crossJoin{};
                crossJoin.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                crossJoin.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                crossJoin.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                crossJoin.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                auto rsCrossJoin = crossJoin.Join(rsPreOrder, rsCustomer);
                EXPECT_TRUE(rsCrossJoin.size() == rsPreOrder.size() * rsCustomer.size());

                // Disconnect
                sptrCustomerDriver->Disconnect();
                sptrPreOrderDriver->Disconnect();
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_SEGMENTATION_HPP
