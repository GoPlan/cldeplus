//
// Created by LE, Duc Anh on 6/24/15.
//

#include "UInt32.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                UInt32::UInt32(int value) : _value(value),
                                            NumericValue(ValueType::UInt32, sizeof(uint32_t)) {
                    //
                }

                void *UInt32::RawPointerToValueBuffer() {
                    return &this->_value;
                }

                bool UInt32::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const UInt32 &>(rhs);
                        return (cast._value == this->_value);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                const std::string UInt32::CopyToString() const {
                    return std::to_string(_value);
                }

                const std::string &UInt32::ToString() const {
                    _string.assign(std::to_string(_value));
                    return _string;
                }

                const char *UInt32::ToCString() const {
                    return ToString().c_str();
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


