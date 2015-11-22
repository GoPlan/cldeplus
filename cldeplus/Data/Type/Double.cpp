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

#include "Double.h"
#include "../DataTypeException.h"

namespace CLDEPlus {
    namespace Data {
        namespace Type {

            Double::Double(double value) : _value(value),
                                           NumericValue(ValueType::Double, sizeof(double)) {
                //
            }

            void *Double::PointerToBuffer() {
                return &_value;
            }

            string Double::CopyToString() const {
                return std::to_string(_value);
            }

            Value &Double::operator+(Value const &rhs) {
                auto cast = dynamic_cast<const Double &>(rhs);
                this->_value = this->_value + cast._value;
                return *this;
            }

            Value &Double::operator-(Value const &rhs) {
                auto cast = dynamic_cast<const Double &>(rhs);
                this->_value = this->_value - cast._value;
                return *this;
            }

            Value &Double::operator*(Value const &rhs) {
                auto cast = dynamic_cast<const Double &>(rhs);
                this->_value = this->_value * cast._value;
                return *this;
            }

            Value &Double::operator/(Value const &rhs) {
                auto cast = dynamic_cast<const Double &>(rhs);
                this->_value = this->_value / cast._value;
                return *this;
            }

            Value &Double::operator%(Value const &rhs) {
                throw DataTypeException("operator% can not be applied to Double type");
            }

            Value &Double::operator=(bool value) {
                _value = (bool) value;
                return *this;
            }

            Value &Double::operator=(double value) {
                _value = value;
                return *this;
            }

            Value &Double::operator=(float value) {
                _value = (double) value;
                return *this;
            }

            Value &Double::operator=(int16 value) {
                _value = (double) value;
                return *this;
            }

            Value &Double::operator=(int32 value) {
                _value = (double) value;
                return *this;
            }

            Value &Double::operator=(int64 value) {
                _value = (double) value;
                return *this;
            }

            Value &Double::operator=(uint16 value) {
                _value = (double) value;
                return *this;
            }

            Value &Double::operator=(uint32 value) {
                _value = (double) value;
                return *this;
            }

            Value &Double::operator=(uint64 value) {
                _value = (double) value;
                return *this;
            }
        }
    }
}


