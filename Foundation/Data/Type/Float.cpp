//
// Created by LE, Duc Anh on 6/10/15.
//

#include "Float.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Float::Float(float value) : _value(value),
                                            NumericValue(ValueType::Float, sizeof(float)) {
                    //
                }

                bool Float::Equal(const Common::IEquatable &rhs) const {
                    return false;
                }

                void *Float::RawPointerToValueBuffer() {
                    return &_value;
                }

                std::string Float::ToString() const {
                    return std::to_string(_value);
                }

                Value &Float::operator+(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Float &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Float::operator-(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Float &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Float::operator*(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Float &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Float::operator/(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Float &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Float::operator%(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Double type");
                }
            }
        }
    }
}


