//
// Created by LE, Duc Anh on 6/10/15.
//

#include "cldeInt64.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Implementation {

                cldeInt64::cldeInt64(int64_t value) : _value(value),
                                                      cldeNumericValue(cldeValueType::Int64, sizeof(int64_t)) {
                    //
                }

                const void *cldeInt64::RawPointerToValueBuffer() {
                    return &this->_value;
                }

                bool cldeInt64::Equal(const Common::IEquatable &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeInt64 &>(rhs);
                        return (cast._value == this->_value);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                const std::string cldeInt64::ToString() const {
                    return std::to_string(_value);
                }

                cldeValue &cldeInt64::operator+(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeInt64 &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeInt64::operator-(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeInt64 &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeInt64::operator*(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeInt64 &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeInt64::operator/(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeInt64 &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeInt64::operator%(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeInt64 &>(rhs);
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


