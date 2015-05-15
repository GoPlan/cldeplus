//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupMap.h"

namespace Cloude {
    namespace Application {

        Column StockGroupMap::Id("Id", "_id", DbType::Int64);
        Column StockGroupMap::Code("Code", "Code", DbType::Int64);
        Column StockGroupMap::Name("Name", "Name", DbType::String);
        Column StockGroupMap::DefaultStockCode("DefaultStockCode", "DefaultStockCode", DbType::String);
        string StockGroupMap::TableName("StockGroup");

        StockGroupMap::StockGroupMap() {
            this->columnsMap[Id.getName()] = &Id;
            this->columnsMap[Code.getName()] = &Code;
            this->columnsMap[Name.getName()] = &Name;
            this->columnsMap[DefaultStockCode.getName()] = &DefaultStockCode;

            // Keys
            this->columnsForKey.push_back(&Code);

            // Columns For Update
            this->columnsForUpdate.push_back(&Name);
            this->columnsForUpdate.push_back(&DefaultStockCode);

            // Columns For Select
            this->columnsForSelect.push_back(&Id);
            this->columnsForSelect.push_back(&Code);
        }

        StockGroupMap::~StockGroupMap() {
            this->columnsMap.clear();
            this->columnsForSelect.clear();
            this->columnsForKey.clear();
            this->columnsForUpdate.clear();
        }

        string StockGroupMap::TableNameCore() {
            return TableName;
        }
    }
}
