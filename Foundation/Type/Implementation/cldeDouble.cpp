//
// Created by LE, Duc Anh on 6/10/15.
//

#include <cstdlib>
#include "cldeDouble.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                cldeDouble::cldeDouble(double value) : _value(value),
                                                       cldeNumericValue(cldeValueType::Double, sizeof(double)) {
                    //
                }

                bool cldeDouble::Equal(const Common::IEquatable &rhs) {
                    return false;
                }

                void *cldeDouble::RawPointerToValueBuffer() {
                    return &_value;
                }

                const std::string cldeDouble::CopyToString() const {
                    return std::to_string(_value);
                }

                const std::string &cldeDouble::ToString() const {

                    if (_string.empty()) {
                        _string.assign(std::to_string(_value));
                    }

                    return _string;
                }

                const char *cldeDouble::ToCString() const {
                    return _string.c_str();
                }

                cldeValue &cldeDouble::operator+(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeDouble &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeDouble::operator-(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeDouble &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeDouble::operator*(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeDouble &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeDouble::operator/(const cldeValue &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeDouble &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                cldeValue &cldeDouble::operator%(const cldeValue &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Double type");
                }
            }
        }
    }
}


