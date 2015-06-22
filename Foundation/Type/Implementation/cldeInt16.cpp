//
// Created by LE, Duc Anh on 6/10/15.
//

#include "cldeInt16.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                cldeInt16::cldeInt16(int16_t value) : _value(value),
                                                      cldeNumericValue(cldeValueType::Int32, sizeof(int32_t)) {
                    //
                }

                void *cldeInt16::RawPointerToValueBuffer() {
                    return &this->_value;
                }

                bool cldeInt16::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const cldeInt16 &>(rhs);
                        return (cast._value == this->_value);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                const std::string cldeInt16::CopyToString() const {
                    return std::to_string(_value);
                }


                const std::string &cldeInt16::ToString() const {

                    if (_string.empty()) {
                        _string.assign(std::to_string(_value));
                    }

                    return _string;
                }

                const char *cldeInt16::ToCString() const {

                    if (_string.empty()) {
                        _string.assign(std::to_string(_value));
                    }

                    return _string.c_str();
                }

                cldeValue &cldeInt16::operator+(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeInt16 &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeInt16::operator-(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeInt16 &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeInt16::operator*(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeInt16 &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeInt16::operator/(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeInt16 &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeInt16::operator%(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeInt16 &>(rhs);
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


