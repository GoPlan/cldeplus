//
// Created by LE, Duc Anh on 6/10/15.
//

#include <cstdlib>
#include "Int64.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Int64::Int64(int64_t value) : _value(value),
                                              NumericValue(ValueType::Int64, sizeof(int64_t)) {
                    //
                }

                void *Int64::RawPointerToValueBuffer() {
                    return &this->_value;
                }

                bool Int64::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const Int64 &>(rhs);
                        return (cast._value == this->_value);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                std::string Int64::ToString() const {
                    return std::to_string(_value);
                }

                Value &Int64::operator+(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int64 &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Int64::operator-(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int64 &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Int64::operator*(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int64 &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Int64::operator/(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int64 &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Int64::operator%(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int64 &>(rhs);
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


