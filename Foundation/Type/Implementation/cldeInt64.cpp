//
// Created by LE, Duc Anh on 6/10/15.
//

#include <cstdlib>
#include "cldeInt64.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                cldeInt64::cldeInt64(int64_t value) : _value(value),
                                                      cldeNumericValue(cldeValueType::Int64, sizeof(int64_t)) {
                    //
                }

                void *cldeInt64::RawPointerToValueBuffer() {
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

                const std::string cldeInt64::CopyToString() const {
                    return std::to_string(_value);
                }

                const std::string &cldeInt64::ToString() const {

                    if (_string.empty()) {
                        _string.assign(std::to_string(_value));
                    }

                    return _string;
                }

                const char *cldeInt64::ToCString() const {

                    if (_string.empty()) {
                        _string.assign(std::to_string(_value));
                    }

                    return _string.c_str();
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


