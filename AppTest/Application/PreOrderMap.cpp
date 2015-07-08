//
// Created by LE, Duc Anh on 7/1/15.
//

#include "PreOrderMap.h"

namespace Cloude {
    namespace AppTest {
        namespace Application{

            std::string PreOrderMap::TableName{"PreOrder"};

            Foundation::SPtrColumn PreOrderMap::Id = std::make_shared<Foundation::Column>("Id", "id", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn PreOrderMap::Name = std::make_shared<Foundation::Column>("Name", "Name", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn PreOrderMap::CustId = std::make_shared<Foundation::Column>("CustId", "CustId", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn PreOrderMap::Total = std::make_shared<Foundation::Column>("Total", "Total", Foundation::Data::ValueType::Double);

            const std::string &PreOrderMap::TableNameCore() const { return TableName; }

            PreOrderMap::PreOrderMap() {
                _columnsForKey.push_back(Id);
                _columnsForGet.push_back(Name);
                _columnsForGet.push_back(CustId);
                _columnsForGet.push_back(Total);
                _columnsForSelect.push_back(Id);
                _columnsForSelect.push_back(Name);
                _columnsForSelect.push_back(CustId);
                _columnsForSelect.push_back(Total);
                _columnsForUpdate.push_back(Name);
                _columnsForUpdate.push_back(CustId);
                _columnsForUpdate.push_back(Total);
            }
        }
    }
}


