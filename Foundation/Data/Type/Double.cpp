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

                const std::string Double::CopyToString() const {
                    return std::to_string(_value);
                }

                const std::string &Double::ToString() const {
                    _string.assign(std::to_string(_value));
                    return _string;
                }

                const char *Double::ToCString() const {
                    return ToString().c_str();
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


