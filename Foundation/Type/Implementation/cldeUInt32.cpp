//
// Created by LE, Duc Anh on 6/24/15.
//

#include "cldeUInt32.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                cldeUInt32::cldeUInt32(int value) : _value(value),
                                                    cldeNumericValue(cldeValueType::UInt32, sizeof(uint32_t)) {
                    //
                }

                void *cldeUInt32::RawPointerToValueBuffer() {
                    return &this->_value;
                }

                bool cldeUInt32::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const cldeUInt32 &>(rhs);
                        return (cast._value == this->_value);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                const std::string cldeUInt32::CopyToString() const {
                    return std::to_string(_value);
                }

                const std::string &cldeUInt32::ToString() const {
                    _string.assign(std::to_string(_value));
                    return _string;
                }

                const char *cldeUInt32::ToCString() const {
                    return ToString().c_str();
                }

                cldeValue &cldeUInt32::operator+(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt32 &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeUInt32::operator-(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt32 &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeUInt32::operator*(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt32 &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeUInt32::operator/(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt32 &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeUInt32::operator%(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt32 &>(rhs);
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


