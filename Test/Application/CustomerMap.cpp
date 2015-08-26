//
// Created by LE, Duc Anh on 7/1/15.
//

#include "CustomerMap.h"

namespace Cloude {
    namespace Test {
        namespace Application {

            std::string CustomerMap::TableName{"Customer"};

            Foundation::SPtrColumn CustomerMap::Id = Foundation::CreateColumn("Id", "id", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn CustomerMap::FirstName = Foundation::CreateColumn("FirstName", "firstname", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn CustomerMap::LastName = Foundation::CreateColumn("LastName", "lastname", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn CustomerMap::Email = Foundation::CreateColumn("Email", "email", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn CustomerMap::AddrStreet = Foundation::CreateColumn("AddrStreet", "addrstreet", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn CustomerMap::AddrZipCode = Foundation::CreateColumn("AddrZipCode", "addrzipcode", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn CustomerMap::AddrCity = Foundation::CreateColumn("AddrCity", "addrcity", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn CustomerMap::AddrCountry = Foundation::CreateColumn("AddrCountry", "addrcountry", Foundation::Data::ValueType::VarChar);

            const std::string &CustomerMap::TableNameCore() const { return TableName; }

            CustomerMap::CustomerMap() {

                SetColumn("Id", Id);
                SetColumn("FirstName", FirstName);
                SetColumn("LastName", LastName);
                SetColumn("Email", Email);
                SetColumn("AddrStreet", AddrStreet);
                SetColumn("AddrZipCode", AddrZipCode);
                SetColumn("AddrCity", AddrCity);
                SetColumn("AddrCountry", AddrCountry);

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


