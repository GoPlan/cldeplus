//
// Created by GoPlan on 14/05/2015.
//

#include "Column.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {


            Column::Column(string name, string datasourceName, DbType dataType) :
                    name(name),
                    datasourceName(datasourceName),
                    dataType(dataType) {
            }

            Column::~Column() {
            }
        }
    }
}
