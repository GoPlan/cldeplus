//
// Created by LE, Duc Anh on 7/3/15.
//

#include "PreOrderItemsMap.h"

namespace CLDEPlus {
    namespace Test {
        namespace Application {

            std::string PreOrderItemsMap::TableName{"PreOrderItemsMap"};

            Foundation::SPtrColumn PreOrderItemsMap::Id = Foundation::CreateColumn("Id",
                                                                                   Foundation::Data::ValueType::Int64,
                                                                                   "id");
            Foundation::SPtrColumn PreOrderItemsMap::OrderId = Foundation::CreateColumn("OrderId",
                                                                                        Foundation::Data::ValueType::Int64,
                                                                                        "orderid");
            Foundation::SPtrColumn PreOrderItemsMap::ItemId = Foundation::CreateColumn("ItemId",
                                                                                       Foundation::Data::ValueType::Int64,
                                                                                       "itemid");
            Foundation::SPtrColumn PreOrderItemsMap::Qty = Foundation::CreateColumn("Qty",
                                                                                    Foundation::Data::ValueType::Double,
                                                                                    "qty");
            Foundation::SPtrColumn PreOrderItemsMap::Price = Foundation::CreateColumn("Price",
                                                                                      Foundation::Data::ValueType::Double,
                                                                                      "price");
            Foundation::SPtrColumn PreOrderItemsMap::Amount = Foundation::CreateColumn("Amount",
                                                                                       Foundation::Data::ValueType::Double,
                                                                                       "amount");
            Foundation::SPtrColumn PreOrderItemsMap::Comment = Foundation::CreateColumn("Comment",
                                                                                        Foundation::Data::ValueType::Text,
                                                                                        "comment");

            PreOrderItemsMap::PreOrderItemsMap() : EntityMap(TableName) {

                SetColumn("Id", OrderId);
                SetColumn("OrderId", OrderId);
                SetColumn("ItemId", ItemId);
                SetColumn("Qty", Qty);
                SetColumn("Price", Price);
                SetColumn("Amount", Amount);
                SetColumn("Comment", Comment);

                _columnsForKey.push_back(Id);
                _columnsForGet.push_back(OrderId);
                _columnsForGet.push_back(ItemId);
                _columnsForGet.push_back(Qty);
                _columnsForGet.push_back(Price);
                _columnsForGet.push_back(Amount);
                _columnsForSelect.push_back(OrderId);
                _columnsForSelect.push_back(ItemId);
                _columnsForUpdate.push_back(OrderId);
                _columnsForUpdate.push_back(ItemId);
                _columnsForUpdate.push_back(Qty);
                _columnsForUpdate.push_back(Price);
                _columnsForUpdate.push_back(Amount);
            }
        }
    }
}


