//
// Created by LE, Duc Anh on 6/10/15.
//

#include <cstdlib>
#include "UInt64.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                UInt64::UInt64(uint64_t value) : _value(value),
                                                 NumericValue(ValueType::UInt64, sizeof(uint64_t)) {
                    //
                }

                void *UInt64::RawPointerToValueBuffer() {
                    return &this->_value;
                }

                bool UInt64::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const UInt64 &>(rhs);
                        return (cast._value == this->_value);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                std::string UInt64::ToString() const {
                    return std::to_string(_value);
                }

                Value &UInt64::operator+(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const UInt64 &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &UInt64::operator-(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const UInt64 &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &UInt64::operator*(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const UInt64 &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &UInt64::operator/(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const UInt64 &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &UInt64::operator%(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const UInt64 &>(rhs);
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

