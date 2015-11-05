//
// Created by LE, Duc Anh on 6/19/15.
//

#ifndef CLDEPLUS_APPTEST_SEGMENTATION_HPP
#define CLDEPLUS_APPTEST_SEGMENTATION_HPP

#include <gtest/gtest.h>

#include "../../Source/Foundation/Foundation.h"
#include "../../Source/Segmentation/Segmentation.h"
#include "../../Source/Drivers/SQLite/SQLiteSourceDriver.h"
#include "../../Source/Drivers/MySql/MySqlSourceDriver.h"

#include "../Application/MapFactory.h"
#include "../Application/EnquiryMap.h"
#include "../Application/CustomerMap.h"
#include "../Application/PreOrderMap.h"
#include "../Application/MapFactory.h"

namespace CLDEPlus {
    namespace Test {
        namespace Segmentation {

            TEST(Segmentation, LEFT_INNER_JOIN_01) {

                using CmpFactory = Foundation::Query::ComparativeFactory;

                auto const sptrCustomerMap = Application::Create<Application::CustomerMap>();
                auto const sptrPreOrderMap = Application::Create<Application::PreOrderMap>();
                auto sptrCustomerDriver = (Drivers::SQLite::SPtrSQLiteSourceDriver) Drivers::SQLite::SQLiteSourceDriver::CreateUnique(sptrCustomerMap);
                auto sptrPreOrderDriver = (Drivers::MySql::SPtrMySqlSourceDriver) Drivers::MySql::MySqlSourceDriver::Create(sptrPreOrderMap);

                auto sptrCustomerStore = Foundation::EntityStore::CreateUnique(sptrCustomerMap, sptrCustomerDriver);
                auto sptrCustomerQuery = Foundation::EntityQuery::Create(sptrCustomerMap, sptrCustomerDriver);
                auto sptrOrderStore = Foundation::EntityStore::CreateUnique(sptrPreOrderMap, sptrPreOrderDriver);
                auto sptrOrderQuery = Foundation::EntityQuery::Create(sptrPreOrderMap, sptrPreOrderDriver);

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
                auto sptrCustomerIdGt00 = CmpFactory::CreateGTE(sptrCustomerMap->GetColumn("Id"), sptrCustomerId);
                auto rsCustomer = sptrCustomerQuery->Select(sptrCustomerIdGt00);

                // Select Order set
                auto sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(10);
                auto sptrOrderIdGt00 = CmpFactory::CreateLTE(sptrPreOrderMap->GetColumn("Id"), sptrOrderId);
                auto rsPreOrder = sptrOrderQuery->Select(sptrOrderIdGt00);

                auto newCustomerIdColumn = Foundation::CreateColumn("_custId", Foundation::Data::ValueType::Int64);
                auto newCustomerEmailColumn = Foundation::CreateColumn("customerEmail", Foundation::Data::ValueType::VarChar);
                auto newPreOrderIdColumn = Foundation::CreateColumn("preorderId", Foundation::Data::ValueType::Int64);
                auto newPreOrderTotalColumn = Foundation::CreateColumn("preorderTotal", Foundation::Data::ValueType::Double);

                CLDEPlus::Segmentation::Transformation::CellTransformer customerIdCell{newCustomerIdColumn};
                CLDEPlus::Segmentation::Transformation::CellTransformer customerEmailCell{newCustomerEmailColumn};
                CLDEPlus::Segmentation::Transformation::CellTransformer preorderIdCell{newPreOrderIdColumn};
                CLDEPlus::Segmentation::Transformation::CellTransformer preorderTotalCell{newPreOrderTotalColumn};

                CLDEPlus::Foundation::Store::Helper::EntityOutputFormatter formatter{};
                formatter.DisplayColumns().push_back(newPreOrderIdColumn);
                formatter.DisplayColumns().push_back(newPreOrderTotalColumn);
                formatter.DisplayColumns().push_back(newCustomerIdColumn);
                formatter.DisplayColumns().push_back(newCustomerEmailColumn);

                // SORT PreOrder
                Foundation::Store::Comparer::Less cmp{};
                cmp.LhsCmpColumns().push_back(sptrPreOrderMap->GetColumn("CustId"));
                cmp.RhsCmpColumns().push_back(sptrPreOrderMap->GetColumn("CustId"));
                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);

                // INNER JOIN - PREORDER <> CUSTOMER
                CLDEPlus::Segmentation::Join::Inner joinInner{};
                joinInner.LhsComparingColumns().push_back(sptrPreOrderMap->GetColumn("CustId"));
                joinInner.RhsComparingColumns().push_back(sptrCustomerMap->GetColumn("Id"));
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
                CLDEPlus::Segmentation::Join::Left joinLeft{};
                joinLeft.LhsComparingColumns().push_back(sptrPreOrderMap->GetColumn("CustId"));
                joinLeft.RhsComparingColumns().push_back(sptrCustomerMap->GetColumn("Id"));
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
                auto sptrCustomerDriver = (Drivers::SQLite::SPtrSQLiteSourceDriver) Drivers::SQLite::SQLiteSourceDriver::CreateUnique(sptrCustomerMap);
                auto sptrPreOrderDriver = (Drivers::MySql::SPtrMySqlSourceDriver) Drivers::MySql::MySqlSourceDriver::Create(sptrPreOrderMap);

                auto sptrCustomerStore = Foundation::EntityStore::CreateUnique(sptrCustomerMap, sptrCustomerDriver);
                auto sptrCustomerQuery = Foundation::EntityQuery::Create(sptrCustomerMap, sptrCustomerDriver);
                auto sptrOrderStore = Foundation::EntityStore::CreateUnique(sptrPreOrderMap, sptrPreOrderDriver);
                auto sptrOrderQuery = Foundation::EntityQuery::Create(sptrPreOrderMap, sptrPreOrderDriver);

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
                auto sptrCustomerIdLTE20 = CmpFactory::CreateLTE(sptrCustomerMap->GetColumn("Id"), sptrCustomerId);
                auto rsCustomer = sptrCustomerQuery->Select(sptrCustomerIdLTE20);

                // Select Order set
                auto sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(0);
                auto sptrOrderIdGt00 = CmpFactory::CreateGTE(sptrPreOrderMap->GetColumn("Id"), sptrOrderId);
                auto rsPreOrder = sptrOrderQuery->Select(sptrOrderIdGt00);

                auto newCustomerIdColumn = Foundation::CreateColumn("_custId", Foundation::Data::ValueType::Int64);
                auto newCustomerEmailColumn = Foundation::CreateColumn("customerEmail", Foundation::Data::ValueType::VarChar);
                auto newPreOrderIdColumn = Foundation::CreateColumn("preorderId", Foundation::Data::ValueType::Int64);
                auto newPreOrderTotalColumn = Foundation::CreateColumn("preorderTotal", Foundation::Data::ValueType::Double);

                CLDEPlus::Segmentation::Transformation::CellTransformer customerIdCell{newCustomerIdColumn};
                CLDEPlus::Segmentation::Transformation::CellTransformer customerEmailCell{newCustomerEmailColumn};
                CLDEPlus::Segmentation::Transformation::CellTransformer preorderIdCell{newPreOrderIdColumn};
                CLDEPlus::Segmentation::Transformation::CellTransformer preorderTotalCell{newPreOrderTotalColumn};

                CLDEPlus::Foundation::Store::Helper::EntityOutputFormatter formatter{};
                formatter.DisplayColumns().push_back(newPreOrderIdColumn);
                formatter.DisplayColumns().push_back(newPreOrderTotalColumn);
                formatter.DisplayColumns().push_back(newCustomerIdColumn);
                formatter.DisplayColumns().push_back(newCustomerEmailColumn);

                // SORT PreOrder
                Foundation::Store::Comparer::Less cmp{};
                cmp.LhsCmpColumns().push_back(sptrPreOrderMap->GetColumn("CustId"));
                cmp.RhsCmpColumns().push_back(sptrPreOrderMap->GetColumn("CustId"));
                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);

                // RIGHT JOIN - PREORDER <> CUSTOMER
                CLDEPlus::Segmentation::Join::Right joinRight{};
                joinRight.LhsComparingColumns().push_back(sptrPreOrderMap->GetColumn("CustId"));
                joinRight.RhsComparingColumns().push_back(sptrCustomerMap->GetColumn("Id"));
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
                auto sptrCustomerDriver = (Drivers::SQLite::SPtrSQLiteSourceDriver) Drivers::SQLite::SQLiteSourceDriver::CreateUnique(sptrCustomerMap);
                auto sptrPreOrderDriver = (Drivers::MySql::SPtrMySqlSourceDriver) Drivers::MySql::MySqlSourceDriver::Create(sptrPreOrderMap);

                auto sptrCustomerStore = Foundation::EntityStore::CreateUnique(sptrCustomerMap, sptrCustomerDriver);
                auto sptrCustomerQuery = Foundation::EntityQuery::Create(sptrCustomerMap, sptrCustomerDriver);
                auto sptrOrderStore = Foundation::EntityStore::CreateUnique(sptrPreOrderMap, sptrPreOrderDriver);
                auto sptrOrderQuery = Foundation::EntityQuery::Create(sptrPreOrderMap, sptrPreOrderDriver);

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
                auto sptrCustomerIdGt00 = CmpFactory::CreateGTE(sptrCustomerMap->GetColumn("Id"), sptrCustomerId);
                auto rsCustomer = sptrCustomerQuery->Select(sptrCustomerIdGt00);

                // Select Order set
                auto sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(10);
                auto sptrOrderIdGt00 = CmpFactory::CreateLTE(sptrPreOrderMap->GetColumn("Id"), sptrOrderId);
                auto rsPreOrder = sptrOrderQuery->Select(sptrOrderIdGt00);

                auto newCustomerIdColumn = Foundation::CreateColumn("_custId", Foundation::Data::ValueType::Int64);
                auto newCustomerEmailColumn = Foundation::CreateColumn("customerEmail", Foundation::Data::ValueType::VarChar);
                auto newPreOrderIdColumn = Foundation::CreateColumn("preorderId", Foundation::Data::ValueType::Int64);
                auto newPreOrderTotalColumn = Foundation::CreateColumn("preorderTotal", Foundation::Data::ValueType::Double);

                CLDEPlus::Segmentation::Transformation::CellTransformer customerIdCell{newCustomerIdColumn};
                CLDEPlus::Segmentation::Transformation::CellTransformer customerEmailCell{newCustomerEmailColumn};
                CLDEPlus::Segmentation::Transformation::CellTransformer preorderIdCell{newPreOrderIdColumn};
                CLDEPlus::Segmentation::Transformation::CellTransformer preorderTotalCell{newPreOrderTotalColumn};

                CLDEPlus::Foundation::Store::Helper::EntityOutputFormatter formatter{};
                formatter.DisplayColumns().push_back(newPreOrderIdColumn);
                formatter.DisplayColumns().push_back(newPreOrderTotalColumn);
                formatter.DisplayColumns().push_back(newCustomerIdColumn);
                formatter.DisplayColumns().push_back(newCustomerEmailColumn);

                // SORT PreOrder
                Foundation::Store::Comparer::Less cmp{};
                cmp.LhsCmpColumns().push_back(sptrPreOrderMap->GetColumn("CustId"));
                cmp.RhsCmpColumns().push_back(sptrPreOrderMap->GetColumn("CustId"));
                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);

                // CROSSJOIN - PREORDER <> CUSTOMER
                CLDEPlus::Segmentation::Join::Cross crossJoin{};
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

#endif //CLDEPLUS_APPTEST_SEGMENTATION_HPP
