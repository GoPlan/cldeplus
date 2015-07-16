//
// Created by LE, Duc Anh on 6/10/15.
//

#include "Int16.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Int16::Int16(int16_t value) : _value(value),
                                              NumericValue(ValueType::Int32, sizeof(int32_t)) {
                    //
                }

                void *Int16::RawPointerToValueBuffer() {
                    return &this->_value;
                }

                std::string Int16::ToString() const {
                    return std::to_string(_value);
                }

                Value &Int16::operator+(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int16 &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Int16::operator-(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int16 &>(rhs);
                        this->_value = this->_value - cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Int16::operator*(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int16 &>(rhs);
                        this->_value = this->_value * cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Int16::operator/(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int16 &>(rhs);
                        this->_value = this->_value / cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Int16::operator%(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Int16 &>(rhs);
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


