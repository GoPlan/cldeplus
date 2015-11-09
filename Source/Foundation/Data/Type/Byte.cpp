//
// Created by LE, Duc Anh on 6/24/15.
//

#include "Byte.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {


                Byte::Byte(int byte) : NumericValue{ValueType::Boolean, sizeof(bool)},
                                       _value{byte} {
                    //
                }

                void *Byte::PointerToBuffer() {
                    return &this->_value;
                }

                string Byte::ToString() const {
                    return std::to_string(_value);
                }

                Value &Byte::operator+(Value const &rhs) {
                    auto cast = dynamic_cast<const Byte &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Byte::operator-(Value const &rhs) {
                    auto cast = dynamic_cast<const Byte &>(rhs);
                    this->_value = this->_value - cast._value;
                    return *this;
                }

                Value &Byte::operator*(Value const &rhs) {
                    auto cast = dynamic_cast<const Byte &>(rhs);
                    this->_value = this->_value * cast._value;
                    return *this;
                }

                Value &Byte::operator/(Value const &rhs) {
                    auto cast = dynamic_cast<const Byte &>(rhs);
                    this->_value = this->_value / cast._value;
                    return *this;
                }

                Value &Byte::operator%(Value const &rhs) {
                    auto cast = dynamic_cast<const Byte &>(rhs);
                    this->_value = this->_value % cast._value;
                    return *this;
                }

                Value &Byte::operator=(bool value) {
                    _value = (int) value;
                    return *this;
                }

                Value &Byte::operator=(double value) {
                    _value = (int) value;
                    return *this;
                }

                Value &Byte::operator=(float value) {
                    _value = (int) value;
                    return *this;
                }

                Value &Byte::operator=(int16 value) {
                    _value = (int) value;
                    return *this;
                }

                Value &Byte::operator=(int32 value) {
                    _value = (int) value;
                    return *this;
                }

                Value &Byte::operator=(int64 value) {
                    _value = (int) value;
                    return *this;
                }

                Value &Byte::operator=(uint16 value) {
                    _value = (int) value;
                    return *this;
                }

                Value &Byte::operator=(uint32 value) {
                    _value = (int) value;
                    return *this;
                }

                Value &Byte::operator=(uint64 value) {
                    _value = (int) value;
                    return *this;
                }
            }
        }
    }
}


