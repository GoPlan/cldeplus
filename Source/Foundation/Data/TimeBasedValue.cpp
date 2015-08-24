//
// Created by LE, Duc Anh on 7/16/15.
//

#include "TimeBasedValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {

            TimeBasedValue::TimeBasedValue(ValueType dataType, size_t size) : Value{dataType, size} {
                //
            }

            ValueCategory TimeBasedValue::_category{ValueCategory::DateTime};

            const ValueCategory &TimeBasedValue::getCategory() const {
                return _category;
            }

            bool TimeBasedValue::isNumeric() const {
                return false;
            }
        }
    }
}


