//
// Created by GoPlan on 14/05/2015.
//

#include <iostream>
#include "Field.h"
#include "Exception/cldeNonSupportedDataTypeException.h"

using namespace std;

namespace Cloude {
    namespace Foundation {

        Field::Field(const SPtrColumn &column) : _column(column) {
            //
        }
    }
}