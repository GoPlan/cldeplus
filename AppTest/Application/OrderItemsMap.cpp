//
// Created by LE, Duc Anh on 7/3/15.
//

#include "OrderItemsMap.h"

namespace Cloude {
    namespace AppTest {
        namespace Application {

            std::string OrderItemsMap::TableName{"OrderItemsMap"};

            Foundation::SPtrColumn OrderItemsMap::Id = std::make_shared<Foundation::Column>("Id", "id", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn OrderItemsMap::OrderId = std::make_shared<Foundation::Column>("OrderId", "orderid", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn OrderItemsMap::ItemId = std::make_shared<Foundation::Column>("ItemId", "itemid", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn OrderItemsMap::Qty = std::make_shared<Foundation::Column>("Qty", "qty", Foundation::Data::ValueType::Double);
            Foundation::SPtrColumn OrderItemsMap::Price = std::make_shared<Foundation::Column>("Price", "price", Foundation::Data::ValueType::Double);
            Foundation::SPtrColumn OrderItemsMap::Ammount = std::make_shared<Foundation::Column>("Ammount", "ammount", Foundation::Data::ValueType::Double);

            const std::string &OrderItemsMap::TableNameCore() const {
                return TableName;
            }

            OrderItemsMap::OrderItemsMap() {
                _columnsForKey.push_back(Id);
                _columnsForGet.push_back(OrderId);
                _columnsForGet.push_back(ItemId);
                _columnsForGet.push_back(Qty);
                _columnsForGet.push_back(Price);
                _columnsForGet.push_back(Ammount);
                _columnsForSelect.push_back(Id);
                _columnsForSelect.push_back(OrderId);
                _columnsForSelect.push_back(ItemId);
                _columnsForUpdate.push_back(OrderId);
                _columnsForUpdate.push_back(ItemId);
                _columnsForUpdate.push_back(Qty);
                _columnsForUpdate.push_back(Price);
                _columnsForUpdate.push_back(Ammount);
            }
        }
    }
}


