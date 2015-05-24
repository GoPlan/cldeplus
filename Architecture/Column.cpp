//
// Created by GoPlan on 14/05/2015.
//

#include "Column.h"

using namespace Cloude::Architecture::Enumeration;

namespace Cloude {
    namespace Architecture {

        Column::Column(const std::string name, const std::string datasourceName, DbType dbtype) : _name(name),
                                                                                                  _datasourceName(
                                                                                                          datasourceName),
                                                                                                  _dbType(dbtype) {
            //
        }
    }
}
