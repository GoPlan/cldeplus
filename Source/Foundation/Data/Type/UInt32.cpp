//
// Created by LE, Duc Anh on 6/24/15.
//

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


