//
// Created by GoPlan on 14/05/2015.
//

#include "Field.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            Field::Field(Column &column, void *value) :
                    _column(column),
                    _value(value) {
            }

            Field::~Field() {
            }
        }
    }
}