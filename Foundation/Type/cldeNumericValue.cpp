//
// Created by LE, Duc Anh on 6/10/15.
//

#include "cldeNumericValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {

            cldeNumericValue::cldeNumericValue(cldeValueType dataType, size_t length)
                    : cldeValue(dataType, length) {
                //
            }

            cldeValueCategory cldeNumericValue::_category = cldeValueCategory::Numeric;

            const cldeValueCategory &cldeNumericValue::getCategory() const {
                return _category;
            }

            bool cldeNumericValue::isNumeric() const {
                return true;
            }
        }
    }
}


