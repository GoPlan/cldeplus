//
// Created by LE, Duc Anh on 6/24/15.
//

#include "Byte.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {


                Byte::Byte(int byte) : NumericValue{ValueType::Boolean, sizeof(bool)},
                                       _value{byte} {
                    //
                }

                void *Byte::RawPointerToValueBuffer() {
                    return &this->_value;
                }

                std::string Byte::ToString() const {
                    return std::to_string(_value);
                }

                Value &Byte::operator+(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Byte &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Byte::operator-(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Byte &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Byte::operator*(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Byte &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Byte::operator/(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Byte &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Byte::operator%(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Byte &>(rhs);
                        this->_value = this->_value % cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }
            }
        }
    }
}


