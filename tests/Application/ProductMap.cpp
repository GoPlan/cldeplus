//
// Created by LE, Duc Anh on 7/1/15.
//

#include "ProductMap.h"

namespace CLDEPlus {
    namespace Test {
        namespace Application {

            std::string ProductMap::TableName{"Product"};

            Foundation::SPtrColumn ProductMap::Id = Foundation::CreateColumn("Id",
                                                                             Foundation::Data::ValueType::Int64,
                                                                             "id");
            Foundation::SPtrColumn ProductMap::Name = Foundation::CreateColumn("Name",
                                                                               Foundation::Data::ValueType::VarChar,
                                                                               "name");
            Foundation::SPtrColumn ProductMap::Code = Foundation::CreateColumn("Code",
                                                                               Foundation::Data::ValueType::VarChar,
                                                                               "code");
            Foundation::SPtrColumn ProductMap::Price = Foundation::CreateColumn("Price",
                                                                                Foundation::Data::ValueType::Double,
                                                                                "price");

            ProductMap::ProductMap() : EntityMap(TableName) {

                SetColumn("Id", Id);
                SetColumn("Name", Name);
                SetColumn("Code", Code);
                SetColumn("Price", Price);

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

