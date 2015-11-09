//
// Created by LE, Duc Anh on 6/10/15.
//

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


