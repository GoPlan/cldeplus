//
// Created by LE, Duc Anh on 6/10/15.
//

#include "cldeDouble.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Implementation {

                cldeDouble::cldeDouble(double value) : _value(value),
                                                       cldeNumericValue(cldeValueType::Double, sizeof(double)) {
                    //
                }

                bool cldeDouble::Equal(const Common::IEquatable &rhs) {
                    return false;
                }

                const std::string cldeDouble::ToString() const {
                    return std::to_string(_value);
                }

                const void *cldeDouble::RawPointerToValueBuffer() {
                    return &_value;
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


