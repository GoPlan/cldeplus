//
// Created by LE, Duc Anh on 6/9/15.
//

#include "Value.h"


namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            Value::Value(ValueType dataType, size_t size)
                    : _dataType(dataType), _reservedSize(size), _actualSize(size) {
                //
            }
        }
    }
}

