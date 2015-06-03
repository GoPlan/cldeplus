//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupMap.h"

using namespace std;
using namespace Cloude::Architecture;

namespace Cloude {
    namespace Application {
        namespace Mapper {

            string StockGroupMap::TableName = "StockGroup";

            shared_ptr<Column> StockGroupMap::Code = make_shared<Column>("Code", "code", 50, Enumeration::DbType::String);
            shared_ptr<Column> StockGroupMap::UniqueName = make_shared<Column>("UniqueName", "UniqueName", 50, Enumeration::DbType::String);
            shared_ptr<Column> StockGroupMap::DefaultStockCode = make_shared<Column>("DefaultStockCode", "DefaultStockCode", 50, Enumeration::DbType::String);

            StockGroupMap::StockGroupMap() {

                this->_columnsForKey.push_back(Code);
                this->_columnsForGet.push_back(UniqueName);
                this->_columnsForGet.push_back(DefaultStockCode);

                this->_columnsForSelect.push_back(Code);
                this->_columnsForSelect.push_back(UniqueName);
                this->_columnsForUpdate.push_back(UniqueName);
                this->_columnsForUpdate.push_back(DefaultStockCode);
            }

            const string &StockGroupMap::TableNameCore() const {
                return TableName;
            }
        }
    }
}
