//
// Created by LE, Duc Anh on 6/10/15.
//

#include <cstdlib>
#include "cldeUInt64.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                cldeUInt64::cldeUInt64(uint64_t value) : _value(value),
                                                         cldeNumericValue(cldeValueType::UInt64, sizeof(uint64_t)) {
                    //
                }

                void *cldeUInt64::RawPointerToValueBuffer() {
                    return &this->_value;
                }

                bool cldeUInt64::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const cldeUInt64 &>(rhs);
                        return (cast._value == this->_value);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                const std::string cldeUInt64::CopyToString() const {
                    return std::to_string(_value);
                }

                const std::string &cldeUInt64::ToString() const {

                    if (_string.empty()) {
                        _string.assign(std::to_string(_value));
                    }

                    return _string;
                }

                const char *cldeUInt64::ToCString() const {

                    if (_string.empty()) {
                        _string.assign(std::to_string(_value));
                    }

                    return _string.c_str();
                }

                cldeValue &cldeUInt64::operator+(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt64 &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeUInt64::operator-(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt64 &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeUInt64::operator*(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt64 &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeUInt64::operator/(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt64 &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeUInt64::operator%(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt64 &>(rhs);
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


