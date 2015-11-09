//
// Created by LE, Duc Anh on 6/24/15.
//

#include "UInt16.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                UInt16::UInt16(uint16_t value) : _value(value),
                                                 NumericValue(ValueType::UInt16, sizeof(int16_t)) {
                    //
                }

                void *UInt16::PointerToBuffer() {
                    return &this->_value;
                }

                string UInt16::ToString() const {
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
}





