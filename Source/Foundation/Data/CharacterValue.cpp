//
// Created by LE, Duc Anh on 6/10/15.
//

#include "CharacterValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            CharacterValue::CharacterValue(ValueType dataType, size_t size)
                    : Value(dataType, size) {
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
                throw Exception::CLDENonSupportedFunctionException("operator+ can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator-(const Value &rhs) {
                throw Exception::CLDENonSupportedFunctionException("operator- can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator*(const Value &rhs) {
                throw Exception::CLDENonSupportedFunctionException("operator* can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator/(const Value &rhs) {
                throw Exception::CLDENonSupportedFunctionException("operator/ can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator%(const Value &rhs) {
                throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator=(bool value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator=(double value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator=(float value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator=(int16 value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator=(int32 value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator=(int64 value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator=(uint16 value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator=(uint32 value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to CharacterValue type");
            }

            Value &CharacterValue::operator=(uint64 value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to CharacterValue type");
            }
        }
    }
}


