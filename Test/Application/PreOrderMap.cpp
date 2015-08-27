//
// Created by LE, Duc Anh on 7/1/15.
//

#include "PreOrderMap.h"

namespace Cloude {
    namespace Test {
        namespace Application{

            std::string PreOrderMap::TableName{"PreOrder"};

            Foundation::SPtrColumn PreOrderMap::Id = Foundation::CreateColumn("Id",
                                                                              Foundation::Data::ValueType::Int64,
                                                                              "id");
            Foundation::SPtrColumn PreOrderMap::Name = Foundation::CreateColumn("Name",
                                                                                Foundation::Data::ValueType::VarChar,
                                                                                "name",
                                                                                255);
            Foundation::SPtrColumn PreOrderMap::CustId = Foundation::CreateColumn("CustId",
                                                                                  Foundation::Data::ValueType::Int64,
                                                                                  "custid");
            Foundation::SPtrColumn PreOrderMap::Total = Foundation::CreateColumn("Total",
                                                                                 Foundation::Data::ValueType::Double,
                                                                                 "total");

            PreOrderMap::PreOrderMap(): EntityMap(TableName) {

                SetColumn("Id", Id);
                SetColumn("Name", Name);
                SetColumn("CustId", CustId);
                SetColumn("Total", Total);

                _columnsForKey.push_back(Id);
                _columnsForGet.push_back(Name);
                _columnsForGet.push_back(CustId);
                _columnsForGet.push_back(Total);
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


