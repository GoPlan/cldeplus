//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupMap.h"

using namespace std;
using namespace Cloude::Architecture;

namespace Cloude {
    namespace Application {
        namespace Mapper {

            std::string StockGroupMap::TableName = "StockGroup";

            std::shared_ptr<Column> StockGroupMap::Id = make_shared<Column>("Id", "_id", Enumeration::DbType::Int64);
            std::shared_ptr<Column> StockGroupMap::Code = make_shared<Column>("Code", "Code", Enumeration::DbType::String);
            std::shared_ptr<Column> StockGroupMap::Name = make_shared<Column>("Name", "Name", Enumeration::DbType::String);
            std::shared_ptr<Column> StockGroupMap::DefaultStockCode = make_shared<Column>("DefaultStockCode", "DefaultStockCode", Enumeration::DbType::String);

            StockGroupMap::StockGroupMap() {

                this->_columnsForKey.push_back(Code);

                this->_columnsForGet.push_back(Code);
                this->_columnsForGet.push_back(Name);
                this->_columnsForGet.push_back(DefaultStockCode);

                this->_columnsForSelect.push_back(Code);
                this->_columnsForSelect.push_back(Name);

                this->_columnsForUpdate.push_back(Code);
                this->_columnsForUpdate.push_back(Name);
                this->_columnsForUpdate.push_back(DefaultStockCode);
            }

            const std::string& StockGroupMap::TableNameCore() const {
                return TableName;
            }
        }
    }
}
