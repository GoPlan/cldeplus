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
            string StockGroupMap::TableName("StockGroup");

            StockGroupMap::StockGroupMap() {
                this->_columns_map[Id.name()] = &Id;
                this->_columns_map[Code.name()] = &Code;
                this->_columns_map[Name.name()] = &Name;
                this->_columns_map[DefaultStockCode.name()] = &DefaultStockCode;

                // Keys
                this->_columns_for_key.push_back(&Code);

                // Columns For Update
                this->_columns_for_update.push_back(&Name);
                this->_columns_for_update.push_back(&DefaultStockCode);

                // Columns For Select
                this->_columns_for_select.push_back(&Id);
                this->_columns_for_select.push_back(&Code);
            }

            StockGroupMap::~StockGroupMap() {
                this->_columns_map.clear();
                this->_columns_for_select.clear();
                this->_columns_for_key.clear();
                this->_columns_for_update.clear();
            }

            string StockGroupMap::TableNameCore() {
                return TableName;
            }
        }
    }
}
