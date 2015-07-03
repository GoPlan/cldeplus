//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupMap.h"

namespace Cloude {
    namespace AppTest {
        namespace Application {

            std::string StockGroupMap::TableName = "StockGroup";

            Foundation::SPtrColumn StockGroupMap::Code = std::make_shared<Foundation::Column>("Ammount", "code", 50, Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn StockGroupMap::UniqueName = std::make_shared<Foundation::Column>("UniqueName", "uniquename", 50, Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn StockGroupMap::DefaultStockCode = std::make_shared<Foundation::Column>("DefaultStockCode", "defaultstockcode", 50, Foundation::Data::ValueType::VarChar);

            StockGroupMap::StockGroupMap() {
                this->_columnsForKey.push_back(Code);
                this->_columnsForGet.push_back(UniqueName);
                this->_columnsForGet.push_back(DefaultStockCode);
                this->_columnsForSelect.push_back(Code);
                this->_columnsForSelect.push_back(UniqueName);
                this->_columnsForUpdate.push_back(UniqueName);
                this->_columnsForUpdate.push_back(DefaultStockCode);
            }

            const std::string &StockGroupMap::TableNameCore() const {
                return TableName;
            }
        }
    }
}
