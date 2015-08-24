//
// Created by LE, Duc Anh on 7/1/15.
//

#include "ProductMap.h"

namespace Cloude {
    namespace Test {
        namespace Application {

            std::string ProductMap::TableName{"Product"};

            Foundation::SPtrColumn ProductMap::Id = Foundation::CreateColumn("Id", "id", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn ProductMap::Name = Foundation::CreateColumn("Name", "name", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn ProductMap::Code = Foundation::CreateColumn("Code", "code", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn ProductMap::Price = Foundation::CreateColumn("Price", "price", Foundation::Data::ValueType::Double);

            const std::string &ProductMap::TableNameCore() const { return TableName; }

            ProductMap::ProductMap() {
                _columnsForKey.push_back(Id);
                _columnsForGet.push_back(Name);
                _columnsForGet.push_back(Code);
                _columnsForGet.push_back(Price);
                _columnsForUpdate.push_back(Name);
                _columnsForUpdate.push_back(Code);
                _columnsForUpdate.push_back(Price);
                _columnsForSelect.push_back(Name);
            }
        }
    }
}

