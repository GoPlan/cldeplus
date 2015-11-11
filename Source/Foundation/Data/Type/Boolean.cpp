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

#include "../../Exception/CLDENonSupportedFunctionException.h"
#include "Boolean.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {


                Boolean::Boolean(bool value)
                        : NumericValue{ValueType::Boolean, sizeof(bool)}, _value{value} {
                    //
                }

                void *Boolean::PointerToBuffer() {
                    return &_value;
                }

                string Boolean::ToString() const {
                    return std::to_string(_value);
                }

                Value &Boolean::operator+(const Value &rhs) {
                    auto cast = dynamic_cast<const Boolean &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Boolean::operator-(const Value &rhs) {
                    auto cast = dynamic_cast<const Boolean &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Boolean::operator*(const Value &rhs) {
                    auto cast = dynamic_cast<const Boolean &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Boolean::operator/(const Value &rhs) {
                    auto cast = dynamic_cast<const Boolean &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Boolean::operator%(const Value &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Boolean type");
                }

                Value &Boolean::operator=(bool value) {
                    _value = value;
                    return *this;
                }

                Value &Boolean::operator=(double value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(float value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(int16 value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(int32 value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(int64 value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(uint16 value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(uint32 value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(uint64 value) {
                    _value = (bool) value;
                    return *this;
                }
            }
        }
    }
}


