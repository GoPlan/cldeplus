//
// Created by LE, Duc Anh on 7/1/15.
//

#include "CustomerMap.h"

namespace Cloude {
    namespace Test {
        namespace Application {

            std::string CustomerMap::TableName{"Customer"};

            Foundation::SPtrColumn CustomerMap::Id = Foundation::CreateColumn("Id",
                                                                              Foundation::Data::ValueType::Int64,
                                                                              "id");
            Foundation::SPtrColumn CustomerMap::FirstName = Foundation::CreateColumn("FirstName",
                                                                                     Foundation::Data::ValueType::VarChar,
                                                                                     "firstname");
            Foundation::SPtrColumn CustomerMap::LastName = Foundation::CreateColumn("LastName",
                                                                                    Foundation::Data::ValueType::VarChar,
                                                                                    "lastname");
            Foundation::SPtrColumn CustomerMap::Email = Foundation::CreateColumn("Email",
                                                                                 Foundation::Data::ValueType::VarChar,
                                                                                 "email");
            Foundation::SPtrColumn CustomerMap::AddrStreet = Foundation::CreateColumn("AddrStreet",
                                                                                      Foundation::Data::ValueType::VarChar,
                                                                                      "addrstreet");
            Foundation::SPtrColumn CustomerMap::AddrZipCode = Foundation::CreateColumn("AddrZipCode",
                                                                                       Foundation::Data::ValueType::VarChar,
                                                                                       "addrzipcode");
            Foundation::SPtrColumn CustomerMap::AddrCity = Foundation::CreateColumn("AddrCity",
                                                                                    Foundation::Data::ValueType::VarChar,
                                                                                    "addrcity");
            Foundation::SPtrColumn CustomerMap::AddrCountry = Foundation::CreateColumn("AddrCountry",
                                                                                       Foundation::Data::ValueType::VarChar,
                                                                                       "addrcountry");

            CustomerMap::CustomerMap() : EntityMap(TableName) {

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


