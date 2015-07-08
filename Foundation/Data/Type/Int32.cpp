//
// Created by LE, Duc Anh on 6/10/15.
//

#include "Int32.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Int32::Int32(int value) : _value(value),
                                          NumericValue(ValueType::Int32, sizeof(int32_t)) {
                    //
                }

                void *Int32::RawPointerToValueBuffer() {
                    return &this->_value;
                }

                bool Int32::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const Int32 &>(rhs);
                        return (cast._value == this->_value);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                std::string Int32::ToString() const {
                    return std::to_string(_value);
                }

                Value &Int32::operator+(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int32 &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Int32::operator-(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int32 &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Int32::operator*(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int32 &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Int32::operator/(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int32 &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Int32::operator%(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int32 &>(rhs);
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


