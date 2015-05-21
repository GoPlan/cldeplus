//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupMap.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {

            Column StockGroupMap::Id("Id", "_id", DbType::Int64);
            Column StockGroupMap::Code("Code", "Code", DbType::Int64);
            Column StockGroupMap::Name("Name", "Name", DbType::String);
            Column StockGroupMap::DefaultStockCode("DefaultStockCode", "DefaultStockCode", DbType::String);
            std::string StockGroupMap::TableName("StockGroup");

            StockGroupMap::StockGroupMap() {
                this->_columnsMap[Id.getName()] = &Id;
                this->_columnsMap[Code.getName()] = &Code;
                this->_columnsMap[Name.getName()] = &Name;
                this->_columnsMap[DefaultStockCode.getName()] = &DefaultStockCode;

                // Keys
                this->_columnsForKey.push_back(&Code);

                // Columns For Update
                this->_columnsForUpdate.push_back(&Name);
                this->_columnsForUpdate.push_back(&DefaultStockCode);

                // Columns For Select
                this->_columnsForSelect.push_back(&Id);
                this->_columnsForSelect.push_back(&Code);
            }

            StockGroupMap::~StockGroupMap() {
                this->_columnsMap.clear();
                this->_columnsForSelect.clear();
                this->_columnsForKey.clear();
                this->_columnsForUpdate.clear();
            }

            std::string StockGroupMap::TableNameCore() {
                return TableName;
            }
        }
    }
}
