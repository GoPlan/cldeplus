//
// Created by LE, Duc Anh on 6/10/15.
//

#include <cstdlib>
#include "Double.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Double::Double(double value) : _value(value),
                                               NumericValue(ValueType::Double, sizeof(double)) {
                    //
                }

                bool Double::Equal(const Common::IEquatable &rhs) const {
                    return false;
                }

                void *Double::RawPointerToValueBuffer() {
                    return &_value;
                }

                std::string Double::ToString() const {
                    return std::to_string(_value);
                }

                Value &Double::operator+(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Double &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Double::operator-(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Double &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Double::operator*(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Double &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Double::operator/(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Double &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Double::operator%(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Double type");
                }
            }
        }
    }
}


