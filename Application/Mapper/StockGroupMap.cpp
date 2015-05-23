//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupMap.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {

            std::shared_ptr<Column> StockGroupMap::Id = make_shared<Column>("Id", "_id", DbType::Int64);
            std::shared_ptr<Column> StockGroupMap::Code = make_shared<Column>("Code", "Code", DbType::String);
            std::shared_ptr<Column> StockGroupMap::Name = make_shared<Column>("Name", "Name", DbType::String);
            std::shared_ptr<Column> StockGroupMap::DefaultStockCode = make_shared<Column>("DefaultStockCode", "DefaultStockCode", DbType::String);

            std::string StockGroupMap::TableName("StockGroup");

            StockGroupMap::StockGroupMap() {
                this->_columnsMap[Id->getName()] = Id;
                this->_columnsMap[Code->getName()] = Code;
                this->_columnsMap[Name->getName()] = Name;
                this->_columnsMap[DefaultStockCode->getName()] = DefaultStockCode;

                this->_columnsForKey.push_back(Code);

                this->_columnsForSelect.push_back(Code);
                this->_columnsForSelect.push_back(Name);

                this->_columnsForUpdate.push_back(Name);
                this->_columnsForUpdate.push_back(DefaultStockCode);
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
