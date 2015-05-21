//
// Created by GoPlan on 14/05/2015.
//

#include "Column.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {


            Column::Column(std::string name, std::string datasourceName, DbType dataType) : _name(name),
                                                                                            _datasourceName(datasourceName),
                                                                                            _dbType(dataType) {
                //
            }

            Column::~Column() {

            }
        }
    }
}
