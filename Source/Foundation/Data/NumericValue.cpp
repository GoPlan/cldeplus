//
// Created by LE, Duc Anh on 6/10/15.
//

#include "NumericValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            NumericValue::NumericValue(ValueType dataType, size_t size)
                    : Value(dataType, size) {
                //
            }

            ValueCategory NumericValue::_category = ValueCategory::Numeric;

            const ValueCategory &NumericValue::getCategory() const { return _category; }

            bool NumericValue::isNumeric() const { return true; }

        }
    }
}


