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

#include "UInt16.h"

namespace CLDEPlus {
    namespace Data {
        namespace Type {

            UInt16::UInt16(uint16_t value) : _value(value),
                                             NumericValue(ValueType::UInt16, sizeof(int16_t)) {
                //
            }

            void *UInt16::PointerToBuffer() {
                return &this->_value;
            }

            string UInt16::CopyToString() const {
                return std::to_string(_value);
            }

            Value &UInt16::operator+(Value const &rhs) {
                auto cast = dynamic_cast< UInt16 const &>(rhs);
                this->_value = this->_value + cast._value;
                return *this;
            }

            Value &UInt16::operator-(Value const &rhs) {
                auto cast = dynamic_cast< UInt16 const &>(rhs);
                this->_value = this->_value - cast._value;
                return *this;
            }

            Value &UInt16::operator*(Value const &rhs) {
                auto cast = dynamic_cast< UInt16 const &>(rhs);
                this->_value = this->_value * cast._value;
                return *this;
            }

            Value &UInt16::operator/(Value const &rhs) {
                auto cast = dynamic_cast< UInt16 const &>(rhs);
                this->_value = this->_value / cast._value;
                return *this;
            }

            Value &UInt16::operator%(Value const &rhs) {
                auto cast = dynamic_cast< UInt16 const &>(rhs);
                this->_value = this->_value % cast._value;
                return *this;
            }

            Value &UInt16::operator=(bool value) {
                _value = (uint16_t) value;
                return *this;
            }

            Value &UInt16::operator=(double value) {
                _value = (uint16_t) value;
                return *this;
            }

            Value &UInt16::operator=(float value) {
                _value = (uint16_t) value;
                return *this;
            }

            Value &UInt16::operator=(int16 value) {
                _value = (uint16_t) value;
                return *this;
            }

            Value &UInt16::operator=(int32 value) {
                _value = (uint16_t) value;
                return *this;
            }

            Value &UInt16::operator=(int64 value) {
                _value = (uint16_t) value;
                return *this;
            }

            Value &UInt16::operator=(uint16 value) {
                _value = (uint16_t) value;
                return *this;
            }

            Value &UInt16::operator=(uint32 value) {
                _value = (uint16_t) value;
                return *this;
            }

            Value &UInt16::operator=(uint64 value) {
                _value = (uint16_t) value;
                return *this;
            }
        }
    }
}





