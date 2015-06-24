//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include "cldeBoolean.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {


                cldeBoolean::cldeBoolean(bool value)
                        : cldeNumericValue{cldeValueType::Boolean, sizeof(bool)}, _value{value} {
                    //
                }

                void *cldeBoolean::RawPointerToValueBuffer() {
                    return &_value;
                }

                bool cldeBoolean::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const cldeBoolean &>(rhs);
                        return (cast._value == this->_value);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                const std::string cldeBoolean::CopyToString() const {
                    return std::to_string(_value);
                }

                const std::string &cldeBoolean::ToString() const {
                    _string.assign(std::to_string(_value));
                    return _string;
                }

                const char *cldeBoolean::ToCString() const {
                    return ToString().c_str();
                }

                cldeValue &cldeBoolean::operator+(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeBoolean &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeBoolean::operator-(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeBoolean &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeBoolean::operator*(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeBoolean &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeBoolean::operator/(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeBoolean &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeBoolean::operator%(const cldeValue &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Boolean type");
                }
            }
        }
    }
}


