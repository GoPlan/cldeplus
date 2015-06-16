//
// Created by LE, Duc Anh on 6/10/15.
//

#include "cldeCharacterValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {

            cldeCharacterValue::cldeCharacterValue(cldeValueType dataType, size_t length)
                    : cldeValue(dataType, length) {
                //
            }

            cldeValueCategory cldeCharacterValue::_category = cldeValueCategory::CharacterBased;

            const cldeValueCategory &cldeCharacterValue::getCategory() const {
                return _category;
            }

            bool cldeCharacterValue::isNumeric() const {
                return false;
            }

            cldeValue &cldeCharacterValue::operator+(const cldeValue &rhs) {
                throw Exception::cldeNonSupportedFunctionException("operator+ can not be applied to Double type");
            }

            cldeValue &cldeCharacterValue::operator-(const cldeValue &rhs) {
                throw Exception::cldeNonSupportedFunctionException("operator- can not be applied to Double type");
            }

            cldeValue &cldeCharacterValue::operator*(const cldeValue &rhs) {
                throw Exception::cldeNonSupportedFunctionException("operator* can not be applied to Double type");
            }

            cldeValue &cldeCharacterValue::operator/(const cldeValue &rhs) {
                throw Exception::cldeNonSupportedFunctionException("operator/ can not be applied to Double type");
            }

            cldeValue &cldeCharacterValue::operator%(const cldeValue &rhs) {
                throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Double type");
            }
        }
    }
}


