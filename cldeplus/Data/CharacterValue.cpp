/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include "DataTypeException.h"
#include "CharacterValue.h"

namespace CLDEPlus {
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
            throw DataTypeException("operator+ can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator-(const Value &rhs) {
            throw DataTypeException("operator- can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator*(const Value &rhs) {
            throw DataTypeException("operator* can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator/(const Value &rhs) {
            throw DataTypeException("operator/ can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator%(const Value &rhs) {
            throw DataTypeException("operator% can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator=(bool value) {
            throw DataTypeException("operator can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator=(double value) {
            throw DataTypeException("operator can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator=(float value) {
            throw DataTypeException("operator can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator=(int16 value) {
            throw DataTypeException("operator can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator=(int32 value) {
            throw DataTypeException("operator can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator=(int64 value) {
            throw DataTypeException("operator can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator=(uint16 value) {
            throw DataTypeException("operator can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator=(uint32 value) {
            throw DataTypeException("operator can not be applied to CharacterValue type");
        }

        Value &CharacterValue::operator=(uint64 value) {
            throw DataTypeException("operator can not be applied to CharacterValue type");
        }
    }
}


