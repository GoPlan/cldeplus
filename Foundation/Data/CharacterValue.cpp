//
// Created by LE, Duc Anh on 6/10/15.
//

#include "CharacterValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {

            CharacterValue::CharacterValue(ValueType dataType, size_t length)
                    : Value(dataType, length) {
                //
            }

            ValueCategory CharacterValue::_category = ValueCategory::CharacterBased;

            const ValueCategory &CharacterValue::getCategory() const {
                return _category;
            }

            bool CharacterValue::isNumeric() const {
                return false;
            }

            Value &CharacterValue::operator+(const Value &rhs) {
                throw Exception::cldeNonSupportedFunctionException("operator+ can not be applied to Double type");
            }

            Value &CharacterValue::operator-(const Value &rhs) {
                throw Exception::cldeNonSupportedFunctionException("operator- can not be applied to Double type");
            }

            Value &CharacterValue::operator*(const Value &rhs) {
                throw Exception::cldeNonSupportedFunctionException("operator* can not be applied to Double type");
            }

            Value &CharacterValue::operator/(const Value &rhs) {
                throw Exception::cldeNonSupportedFunctionException("operator/ can not be applied to Double type");
            }

            Value &CharacterValue::operator%(const Value &rhs) {
                throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Double type");
            }
        }
    }
}


