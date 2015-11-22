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

#include "UInt32.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                UInt32::UInt32(uint32_t value) : _value(value),
                                                 NumericValue(ValueType::UInt32, sizeof(uint32_t)) {
                    //
                }

                void *UInt32::PointerToBuffer() {
                    return &this->_value;
                }

                string UInt32::ToString() const {
                    return std::to_string(_value);
                }

                Value &UInt32::operator+(Value const &rhs) {
                    auto cast = dynamic_cast< UInt32 const &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &UInt32::operator-(Value const &rhs) {
                    auto cast = dynamic_cast< UInt32 const &>(rhs);
                    this->_value = this->_value - cast._value;
                    return *this;
                }

                Value &UInt32::operator*(Value const &rhs) {
                    auto cast = dynamic_cast< UInt32 const &>(rhs);
                    this->_value = this->_value * cast._value;
                    return *this;
                }

                Value &UInt32::operator/(Value const &rhs) {
                    auto cast = dynamic_cast< UInt32 const &>(rhs);
                    this->_value = this->_value / cast._value;
                    return *this;
                }

                Value &UInt32::operator%(Value const &rhs) {
                    auto cast = dynamic_cast< UInt32 const &>(rhs);
                    this->_value = this->_value % cast._value;
                    return *this;
                }

                Value &UInt32::operator=(bool value) {
                    _value = (uint32_t) value;
                    return *this;
                }

                Value &UInt32::operator=(double value) {
                    _value = (uint32_t) value;
                    return *this;
                }

                Value &UInt32::operator=(float value) {
                    _value = (uint32_t) value;
                    return *this;
                }

                Value &UInt32::operator=(int16 value) {
                    _value = (uint32_t) value;
                    return *this;
                }

                Value &UInt32::operator=(int32 value) {
                    _value = (uint32_t) value;
                    return *this;
                }

                Value &UInt32::operator=(int64 value) {
                    _value = (uint32_t) value;
                    return *this;
                }

                Value &UInt32::operator=(uint16 value) {
                    _value = (uint32_t) value;
                    return *this;
                }

                Value &UInt32::operator=(uint32 value) {
                    _value = (uint32_t) value;
                    return *this;
                }

                Value &UInt32::operator=(uint64 value) {
                    _value = (uint32_t) value;
                    return *this;
                }
            }
        }
    }
}


