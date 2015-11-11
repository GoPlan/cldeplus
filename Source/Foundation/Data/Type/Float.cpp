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

#include "Float.h"
#include "../../Exception/CLDENonSupportedFunctionException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Float::Float(float value) : _value(value),
                                            NumericValue(ValueType::Float, sizeof(float)) {
                    //
                }

                void *Float::PointerToBuffer() {
                    return &_value;
                }

                string Float::ToString() const {
                    return std::to_string(_value);
                }

                Value &Float::operator+(Value const &rhs) {
                    auto cast = dynamic_cast<const Float &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Float::operator-(Value const &rhs) {
                    auto cast = dynamic_cast<const Float &>(rhs);
                    this->_value = this->_value - cast._value;
                    return *this;
                }

                Value &Float::operator*(Value const &rhs) {
                    auto cast = dynamic_cast<const Float &>(rhs);
                    this->_value = this->_value * cast._value;
                    return *this;
                }

                Value &Float::operator/(Value const &rhs) {
                    auto cast = dynamic_cast<const Float &>(rhs);
                    this->_value = this->_value / cast._value;
                    return *this;
                }

                Value &Float::operator%(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Double type");
                }

                Value &Float::operator=(bool value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(double value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(float value) {
                    _value = value;
                    return *this;
                }

                Value &Float::operator=(int16 value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(int32 value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(int64 value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(uint16 value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(uint32 value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(uint64 value) {
                    _value = (float) value;
                    return *this;
                }
            }
        }
    }
}


