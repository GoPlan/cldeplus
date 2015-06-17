//
// Created by LE, Duc Anh on 6/10/15.
//

#include "cldeFloat.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                cldeFloat::cldeFloat(float value) : _value(value),
                                                    cldeNumericValue(cldeValueType::Double, sizeof(double)) {
                    //
                }

                bool cldeFloat::Equal(const Common::IEquatable &rhs) {
                    return false;
                }

                void *cldeFloat::RawPointerToValueBuffer() {
                    return &_value;
                }

                const std::string cldeFloat::CopyToString() const {
                    return std::to_string(_value);
                }

                const std::string &cldeFloat::ToString() const {

                    if (_string.empty()) {
                        _string.assign(std::to_string(_value));
                    }

                    return _string;
                }

                const char *cldeFloat::ToCString() const {

                    if (_string.empty()) {
                        _string.assign(std::to_string(_value));
                    }

                    return _string.c_str();
                }

                cldeValue &cldeFloat::operator+(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeFloat &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeFloat::operator-(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeFloat &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeFloat::operator*(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeFloat &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeFloat::operator/(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeFloat &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeFloat::operator%(const cldeValue &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Double type");
                }
            }
        }
    }
}


