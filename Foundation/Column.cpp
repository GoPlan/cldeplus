//
// Created by GoPlan on 14/05/2015.
//

#include "Column.h"

namespace Cloude {
    namespace Foundation {

        Column::Column(std::string name,
                       std::string datasourceName,
                       Enumeration::DbType dbtype) : _name(name),
                                        _datasourceName(datasourceName),
                                        _dbType(dbtype) {
            //
        }

        Column::Column(std::string name,
                       std::string datasourceName,
                       size_t length,
                       Enumeration::DbType dbtype) : _name(name),
                                        _datasourceName(datasourceName),
                                        _length(length),
                                        _dbType(dbtype) {
            //
        }
    }
}
