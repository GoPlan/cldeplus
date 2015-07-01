//
// Created by LE, Duc Anh on 7/1/15.
//

#include "OrderMap.h"

namespace Cloude {
    namespace AppTest {
        namespace Application{

            std::string OrderMap::TableName{"Order"};

            Foundation::SPtrColumn OrderMap::Id = std::make_shared<Foundation::Column>("Id", "id", Foundation::Type::cldeValueType::Int64);
            Foundation::SPtrColumn OrderMap::Name = std::make_shared<Foundation::Column>("Name", "name", Foundation::Type::cldeValueType::VarChar);
            Foundation::SPtrColumn OrderMap::CustId = std::make_shared<Foundation::Column>("CustId", "custId", Foundation::Type::cldeValueType::Int64);
            Foundation::SPtrColumn OrderMap::Total = std::make_shared<Foundation::Column>("Total", "total", Foundation::Type::cldeValueType::Double);

            const std::string &OrderMap::TableNameCore() const { return TableName; }

            OrderMap::OrderMap() {
                _columnsForKey.push_back(Id);
                _columnsForGet.push_back(Name);
                _columnsForGet.push_back(CustId);
                _columnsForGet.push_back(Total);
                _columnsForSelect.push_back(Name);
                _columnsForSelect.push_back(Total);
                _columnsForUpdate.push_back(Name);
                _columnsForUpdate.push_back(CustId);
                _columnsForUpdate.push_back(Total);
            }
        }
    }
}


