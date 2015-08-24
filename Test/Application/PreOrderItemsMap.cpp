//
// Created by LE, Duc Anh on 7/3/15.
//

#include "PreOrderItemsMap.h"

namespace Cloude {
    namespace Test {
        namespace Application {

            std::string PreOrderItemsMap::TableName{"PreOrderItemsMap"};

            Foundation::SPtrColumn PreOrderItemsMap::Id = Foundation::CreateColumn("Id", "id", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn PreOrderItemsMap::OrderId = Foundation::CreateColumn("OrderId", "orderid", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn PreOrderItemsMap::ItemId = Foundation::CreateColumn("ItemId", "itemid", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn PreOrderItemsMap::Qty = Foundation::CreateColumn("Qty", "qty", Foundation::Data::ValueType::Double);
            Foundation::SPtrColumn PreOrderItemsMap::Price = Foundation::CreateColumn("Price", "price", Foundation::Data::ValueType::Double);
            Foundation::SPtrColumn PreOrderItemsMap::Amount = Foundation::CreateColumn("Amount", "amount", Foundation::Data::ValueType::Double);
            Foundation::SPtrColumn PreOrderItemsMap::Comment = Foundation::CreateColumn("Comment", "comment", Foundation::Data::ValueType::Text);

            const std::string &PreOrderItemsMap::TableNameCore() const {
                return TableName;
            }

            PreOrderItemsMap::PreOrderItemsMap() {
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


