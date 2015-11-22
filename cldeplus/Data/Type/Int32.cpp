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

#include "Int32.h"

namespace CLDEPlus {
    namespace Data {
        namespace Type {

            Int32::Int32(int value) : _value(value),
                                      NumericValue(ValueType::Int32, sizeof(int32_t)) {
                //
            }

            void *Int32::PointerToBuffer() {
                return &this->_value;
            }

            string Int32::ToString() const {
                return std::to_string(_value);
            }

            Value &Int32::operator+(Value const &rhs) {
                auto cast = dynamic_cast<const Int32 &>(rhs);
                this->_value = this->_value + cast._value;
                return *this;
            }

            Value &Int32::operator-(Value const &rhs) {
                auto cast = dynamic_cast<const Int32 &>(rhs);
                this->_value = this->_value - cast._value;
                return *this;
            }

            Value &Int32::operator*(Value const &rhs) {
                auto cast = dynamic_cast<const Int32 &>(rhs);
                this->_value = this->_value * cast._value;
                return *this;
            }

            Value &Int32::operator/(Value const &rhs) {
                auto cast = dynamic_cast<const Int32 &>(rhs);
                this->_value = this->_value / cast._value;
                return *this;
            }

            Value &Int32::operator%(Value const &rhs) {
                auto cast = dynamic_cast<const Int32 &>(rhs);
                this->_value = this->_value % cast._value;
                return *this;
            }

            Value &Int32::operator=(bool value) {
                _value = (int32_t) value;
                return *this;
            }

            Value &Int32::operator=(double value) {
                _value = (int32_t) value;
                return *this;
            }

            Value &Int32::operator=(float value) {
                _value = (int32_t) value;
                return *this;
            }

            Value &Int32::operator=(int16 value) {
                _value = (int32_t) value;
                return *this;
            }

            Value &Int32::operator=(int32 value) {
                _value = (int32_t) value;
                return *this;
            }

            Value &Int32::operator=(int64 value) {
                _value = (int32_t) value;
                return *this;
            }

            Value &Int32::operator=(uint16 value) {
                _value = (int32_t) value;
                return *this;
            }

            Value &Int32::operator=(uint32 value) {
                _value = (int32_t) value;
                return *this;
            }

            Value &Int32::operator=(uint64 value) {
                _value = (int32_t) value;
                return *this;
            }
        }
    }
}


