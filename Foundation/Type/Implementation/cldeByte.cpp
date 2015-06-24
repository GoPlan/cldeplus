//
// Created by LE, Duc Anh on 6/24/15.
//

#include "cldeByte.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {


                cldeByte::cldeByte(int byte) : cldeNumericValue{cldeValueType::Boolean, sizeof(bool)},
                                               _value{byte} {
                    //
                }

                void *cldeByte::RawPointerToValueBuffer() {
                    return &this->_value;
                }

                bool cldeByte::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const cldeByte &>(rhs);
                        return (cast._value == this->_value);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                const std::string cldeByte::CopyToString() const {
                    return std::to_string(_value);
                }

                const std::string &cldeByte::ToString() const {
                    _string.assign(std::to_string(_value));
                    return _string;
                }

                const char *cldeByte::ToCString() const {
                    return ToString().c_str();
                }

                cldeValue &cldeByte::operator+(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeByte &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeByte::operator-(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeByte &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeByte::operator*(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeByte &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeByte::operator/(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeByte &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeByte::operator%(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeByte &>(rhs);
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


