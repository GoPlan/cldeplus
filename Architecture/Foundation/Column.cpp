//
// Created by GoPlan on 14/05/2015.
//

#include "Column.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            Column::~Column() {
                //
            }

            Column::Column(const std::string name, const std::string datasourceName, DbType dbtype) : _name(name),
                                                                                                      _datasourceName(datasourceName),
                                                                                                      _dbType(dbtype) {
                //
            }
        }
    }
}
