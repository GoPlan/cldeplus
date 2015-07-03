//
// Created by LE, Duc Anh on 7/1/15.
//

#include "ProductMap.h"

namespace Cloude {
    namespace AppTest {
        namespace Application {

            std::string ProductMap::TableName{"Product"};

            Foundation::SPtrColumn ProductMap::Id = std::make_shared<Foundation::Column>("Id", "id", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn ProductMap::Name = std::make_shared<Foundation::Column>("Name", "name", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn ProductMap::Price = std::make_shared<Foundation::Column>("Price", "price", Foundation::Data::ValueType::Double);

            const std::string &ProductMap::TableNameCore() const { return TableName; }

            ProductMap::ProductMap() {
                _columnsForKey.push_back(Id);
                _columnsForGet.push_back(Name);
                _columnsForUpdate.push_back(Name);
                _columnsForSelect.push_back(Name);
            }
        }
    }
}

