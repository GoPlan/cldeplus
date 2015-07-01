//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Type/cldeNumericValue.h>
#include "cldeUInt16.h"


namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                cldeUInt16::cldeUInt16(uint16_t value) : _value(value),
                                                         cldeNumericValue(cldeValueType::UInt16, sizeof(int16_t)) {
                    //
                }

                void *cldeUInt16::RawPointerToValueBuffer() {
                    return &this->_value;
                }

                bool cldeUInt16::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const cldeUInt16 &>(rhs);
                        return (cast._value == this->_value);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                const std::string cldeUInt16::CopyToString() const {
                    return std::to_string(_value);
                }


                const std::string &cldeUInt16::ToString() const {

                    if (_string.empty()) {
                        _string.assign(std::to_string(_value));
                    }

                    return _string;
                }

                const char *cldeUInt16::ToCString() const {

                    if (_string.empty()) {
                        _string.assign(std::to_string(_value));
                    }

                    return _string.c_str();
                }

                cldeValue &cldeUInt16::operator+(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt16 &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeUInt16::operator-(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt16 &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeUInt16::operator*(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt16 &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeUInt16::operator/(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt16 &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeUInt16::operator%(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeUInt16 &>(rhs);
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





