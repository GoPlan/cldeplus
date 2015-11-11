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

#include <cstdlib>
#include "UInt64.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                UInt64::UInt64(uint64_t value) : _value(value),
                                                 NumericValue(ValueType::UInt64, sizeof(uint64_t)) {
                    //
                }

                void *UInt64::PointerToBuffer() {
                    return &this->_value;
                }

                string UInt64::ToString() const {
                    return std::to_string(_value);
                }

                Value &UInt64::operator+(Value const &rhs) {
                    auto cast = dynamic_cast< UInt64 const &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &UInt64::operator-(Value const &rhs) {
                    auto cast = dynamic_cast< UInt64 const &>(rhs);
                    this->_value = this->_value - cast._value;
                    return *this;
                }

                Value &UInt64::operator*(Value const &rhs) {
                    auto cast = dynamic_cast< UInt64 const &>(rhs);
                    this->_value = this->_value * cast._value;
                    return *this;
                }

                Value &UInt64::operator/(Value const &rhs) {
                    auto cast = dynamic_cast< UInt64 const &>(rhs);
                    this->_value = this->_value / cast._value;
                    return *this;
                }

                Value &UInt64::operator%(Value const &rhs) {
                    auto cast = dynamic_cast< UInt64 const &>(rhs);
                    this->_value = this->_value % cast._value;
                    return *this;
                }

                Value &UInt64::operator=(bool value) {
                    _value = (uint64_t) value;
                    return *this;
                }

                Value &UInt64::operator=(double value) {
                    _value = (uint64_t) value;
                    return *this;
                }

                Value &UInt64::operator=(float value) {
                    _value = (uint64_t) value;
                    return *this;
                }

                Value &UInt64::operator=(int16 value) {
                    _value = (uint64_t) value;
                    return *this;
                }

                Value &UInt64::operator=(int32 value) {
                    _value = (uint64_t) value;
                    return *this;
                }

                Value &UInt64::operator=(int64 value) {
                    _value = (uint64_t) value;
                    return *this;
                }

                Value &UInt64::operator=(uint16 value) {
                    _value = (uint64_t) value;
                    return *this;
                }

                Value &UInt64::operator=(uint32 value) {
                    _value = (uint64_t) value;
                    return *this;
                }

                Value &UInt64::operator=(uint64 value) {
                    _value = (uint64_t) value;
                    return *this;
                }
            }
        }
    }
}


