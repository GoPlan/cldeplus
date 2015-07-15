//
// Created by LE, Duc Anh on 7/1/15.
//

#include "CustomerMap.h"

namespace Cloude {
    namespace AppTest {
        namespace Application {

            std::string CustomerMap::TableName{"Customer"};

            Foundation::SPtrColumn CustomerMap::Id = std::make_shared<Foundation::Column>("Id", "id", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn CustomerMap::FirstName = std::make_shared<Foundation::Column>("FirstName", "firstname", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn CustomerMap::LastName = std::make_shared<Foundation::Column>("LastName", "lastname", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn CustomerMap::Email = std::make_shared<Foundation::Column>("Email", "email", Foundation::Data::ValueType::VarChar);

            const std::string &CustomerMap::TableNameCore() const { return TableName; }

            CustomerMap::CustomerMap() {
                _columnsForKey.push_back(Id);
                _columnsForGet.push_back(FirstName);
                _columnsForGet.push_back(LastName);
                _columnsForGet.push_back(Email);
                _columnsForSelect.push_back(Email);
                _columnsForUpdate.push_back(FirstName);
                _columnsForUpdate.push_back(LastName);
                _columnsForUpdate.push_back(Email);
            }
        }
    }
}


