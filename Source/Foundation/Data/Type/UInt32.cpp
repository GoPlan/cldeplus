//
// Created by LE, Duc Anh on 6/24/15.
//

#include "UInt32.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                UInt32::UInt32(int value) : _value(value),
                                            NumericValue(ValueType::UInt32, sizeof(uint32_t)) {
                    //
                }

                void *UInt32::PointerToBuffer() {
                    return &this->_value;
                }

                std::string UInt32::ToString() const {
                    return std::to_string(_value);
                }

                Value &UInt32::operator+(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const UInt32 &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &UInt32::operator-(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const UInt32 &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &UInt32::operator*(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const UInt32 &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &UInt32::operator/(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const UInt32 &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &UInt32::operator%(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const UInt32 &>(rhs);
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


