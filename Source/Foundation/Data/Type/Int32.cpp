//
// Created by LE, Duc Anh on 6/10/15.
//

#include "Int32.h"

namespace CLDEPlus {
    namespace Foundation {
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
}


