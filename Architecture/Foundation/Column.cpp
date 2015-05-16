//
// Created by GoPlan on 14/05/2015.
//

#include "Column.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {


            Column::Column(string name, string datasourceName, DbType dataType) :
                    _name(name),
                    _datasource_name(datasourceName),
                    _db_type(dataType) {
            }

            Column::~Column() {
            }
        }
    }
}
