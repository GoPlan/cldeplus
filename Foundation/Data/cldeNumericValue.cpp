//
// Created by LE, Duc Anh on 6/10/15.
//

#include "cldeNumericValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {

            cldeNumericValue::cldeNumericValue(cldeValueType dataType, size_t length)
                    : cldeValue(dataType, length) {
                //
            }

            cldeValueCategory cldeNumericValue::getCategory() {
                return cldeValueCategory::Numeric;
            }

            bool cldeNumericValue::isNumeric() {
                return true;
            }
        }
    }
}


