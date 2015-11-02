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


