//
// Created by GoPlan on 14/05/2015.
//

#include "Field.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            Field::Field(Column &column, void *value) :
                    column(column),
                    value(value) {
            }

            Field::~Field() {
            }
        }
    }
}