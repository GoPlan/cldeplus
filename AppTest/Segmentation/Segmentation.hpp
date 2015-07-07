//
// Created by LE, Duc Anh on 6/19/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_SEGMENTATION_HPP
#define CLOUD_E_PLUS_APPTEST_SEGMENTATION_HPP

#include "gtest/gtest.h"
#include <memory>
#include <iostream>
#include <functional>
#include <Cloude.h>
#include <Drivers/SQLite/SQLiteSourceDriver.h>
#include <Foundation/Query/Helper/SqlHelper.h>
#include <AppTest/Application/EnquiryMap.h>
#include <AppTest/Application/EnquiryLoader.h>
#include <AppTest/Application/CustomerMap.h>
#include <AppTest/Application/CustomerLoader.h>
#include <AppTest/Application/PreOrderMap.h>
#include <AppTest/Application/PreOrderLoader.h>
#include <Segmentation/Join/TCross.hpp>
#include <Segmentation/Join/TFull.hpp>
#include <Segmentation/Join/TRight.hpp>
#include <Segmentation/Join/TLeft.hpp>
#include <Segmentation/Join/TInner.hpp>

namespace Cloude {
    namespace AppTest {
        namespace Segmentation {

            TEST(Segmentation, case01) {

                Application::CustomerMap mapCustomer;
                Application::CustomerLoader loaderCustomer;
                Application::PreOrderMap mapPreOrder;
                Application::PreOrderLoader loadPreOrder;

                Drivers::SQLite::SQLiteSourceDriver driverCustomer{mapCustomer};
                Drivers::SQLite::SQLiteSourceDriver driverOrder{mapPreOrder};

                Foundation::SPtrEntityStore sptrCustomerStore = std::make_shared<Foundation::EntityStore>(mapCustomer, loaderCustomer, driverCustomer);
                Foundation::SPtrEntityStore sptrOrderStore = std::make_shared<Foundation::EntityStore>(mapPreOrder, loadPreOrder, driverOrder);

                Foundation::EntityQuery queryCustomer{sptrCustomerStore};
                Foundation::EntityQuery queryOrder{sptrOrderStore};

                driverCustomer.OptionArgs().ConnectionString = "../ex1.db";
                driverCustomer.Connect();
                driverOrder.OptionArgs().ConnectionString = "../ex1.db";
                driverOrder.Connect();

                // Select Customer set
                Foundation::Data::SPtrValue sptrCustomerId = Foundation::Data::ValueFactory::CreateInt64(0);
                Foundation::Query::SPtrCriteria
                        sptrCustomerIdGt00(new Foundation::Query::Comparative::Greater(mapCustomer.Id, sptrCustomerId));
                Foundation::SPtrEntityProxyVector rsCustomer = queryCustomer.ComposeVector(sptrCustomerIdGt00);

                for (auto proxy : rsCustomer) {
                    std::cout << proxy->CopyToString() << std::endl;
                }

                // Select Order set
                Foundation::Data::SPtrValue sptrOrderId = Foundation::Data::ValueFactory::CreateInt64(0);
                Foundation::Query::SPtrCriteria
                        sptrOrderIdGt00(new Foundation::Query::Comparative::Greater(mapPreOrder.Id, sptrOrderId));
                Foundation::SPtrEntityProxyVector rsPreOrder = queryOrder.ComposeVector(sptrOrderIdGt00);

                for (auto proxy : rsPreOrder) {
                    std::cout << proxy->CopyToString() << std::endl;
                }

                Foundation::SPtrColumn newCustomerIdColumn = std::make_shared<Foundation::Column>("customerId", Foundation::Data::ValueType::Int64);
                Foundation::SPtrColumn newCustomerEmailColumn = std::make_shared<Foundation::Column>("email", Foundation::Data::ValueType::VarChar);
                Foundation::SPtrColumn newPreOrderIdColumn = std::make_shared<Foundation::Column>("preorderId", Foundation::Data::ValueType::Int64);
                Foundation::SPtrColumn newPreOrderTotalColumn = std::make_shared<Foundation::Column>("preorderTotal", Foundation::Data::ValueType::Double);

                Cloude::Segmentation::Transformation::CellTransformer customerIdCell{newCustomerIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer customerEmailCell{newCustomerEmailColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderIdCell{newPreOrderIdColumn};
                Cloude::Segmentation::Transformation::CellTransformer preorderCustIdCell{};
                Cloude::Segmentation::Transformation::CellTransformer preorderTotalCell{newPreOrderTotalColumn};


                std::cout << std::endl;
                std::cout << "CROSS JOIN result" << std::endl;
                Cloude::Segmentation::Join::Cross joinCross{};
                joinCross.LhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinCross.LhsTransformer()->AddCellTransformer("Email", customerEmailCell);
                joinCross.RhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinCross.RhsTransformer()->AddCellTransformer("Total", preorderTotalCell);

                Foundation::SPtrEntityProxyVector rsJoinCross = joinCross.Join(rsCustomer, rsPreOrder);
                for (auto proxy : rsJoinCross) {
                    std::cout << proxy->CopyToString() << std::endl;
                }


                std::cout << std::endl;
                std::cout << "SORT PreOrder by CustId" << std::endl;
                Foundation::Store::Comparer::Less cmp{};
                cmp.LhsCmpColumns().push_back(mapPreOrder.CustId);
                cmp.RhsCmpColumns().push_back(mapPreOrder.CustId);

                std::sort(rsPreOrder.begin(), rsPreOrder.end(), cmp);
                for (auto proxy : rsPreOrder) {
                    std::cout << proxy->CopyToString() << std::endl;
                }


                std::cout << std::endl;
                std::cout << "PreOrder LEFT JOIN Customer" << std::endl;
                Cloude::Segmentation::Join::Left joinLeft{};
                joinLeft.LhsComparingColumns().push_back(mapPreOrder.CustId);
                joinLeft.RhsComparingColumns().push_back(mapCustomer.Id);
                joinLeft.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinLeft.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                joinLeft.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinLeft.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                Foundation::SPtrEntityProxyVector rsJoinLeft = joinLeft.Join(rsPreOrder, rsCustomer);
                for (auto proxy : rsJoinLeft) {
                    std::cout << proxy->CopyToString() << std::endl;
                }


                std::cout << std::endl;
                std::cout << "PreOrder RIGHT JOIN Customer" << std::endl;
                Cloude::Segmentation::Join::Right joinRight{};
                joinRight.LhsComparingColumns().push_back(mapPreOrder.CustId);
                joinRight.RhsComparingColumns().push_back(mapCustomer.Id);
                joinRight.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinRight.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                joinRight.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinRight.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                Foundation::SPtrEntityProxyVector rsJoinRight = joinRight.Join(rsPreOrder, rsCustomer);
                for (auto proxy : rsJoinRight) {
                    std::cout << proxy->CopyToString() << std::endl;
                }


                std::cout << std::endl;
                std::cout << "PreOrder INNER JOIN Customer" << std::endl;
                Cloude::Segmentation::Join::Inner joinInner{};
                joinInner.LhsComparingColumns().push_back(mapPreOrder.CustId);
                joinInner.RhsComparingColumns().push_back(mapCustomer.Id);
                joinInner.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinInner.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                joinInner.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinInner.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                Foundation::SPtrEntityProxyVector rsJoinInner = joinInner.Join(rsPreOrder, rsCustomer);
                for (auto proxy : rsJoinInner) {
                    std::cout << proxy->CopyToString() << std::endl;
                }


                std::cout << std::endl;
                std::cout << "PreOrder FULL JOIN Customer" << std::endl;
                Cloude::Segmentation::Join::Full joinFull{};
                joinFull.LhsComparingColumns().push_back(mapPreOrder.CustId);
                joinFull.RhsComparingColumns().push_back(mapCustomer.Id);
                joinFull.LhsTransformer()->AddCellTransformer("Id", preorderIdCell);
                joinFull.LhsTransformer()->AddCellTransformer("Total", preorderTotalCell);
                joinFull.RhsTransformer()->AddCellTransformer("Id", customerIdCell);
                joinFull.RhsTransformer()->AddCellTransformer("Email", customerEmailCell);

                Foundation::SPtrEntityProxyVector rsJoinFull = joinFull.Join(rsPreOrder, rsCustomer);
                for (auto proxy : rsJoinFull) {
                    std::cout << proxy->CopyToString() << std::endl;
                }


                // Disconnect
                driverCustomer.Disconnect();
                driverOrder.Disconnect();
            }
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_SEGMENTATION_HPP
