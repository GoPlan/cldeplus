//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include "Boolean.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {


                Boolean::Boolean(bool value)
                        : NumericValue{ValueType::Boolean, sizeof(bool)}, _value{value} {
                    //
                }

                void *Boolean::RawPointerToValueBuffer() {
                    return &_value;
                }

                bool Boolean::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const Boolean &>(rhs);
                        return (cast._value == this->_value);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                const std::string Boolean::CopyToString() const {
                    return std::to_string(_value);
                }

                const std::string &Boolean::ToString() const {
                    _string.assign(std::to_string(_value));
                    return _string;
                }

                const char *Boolean::ToCString() const {
                    return ToString().c_str();
                }

                Value &Boolean::operator+(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Boolean &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Boolean::operator-(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Boolean &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Boolean::operator*(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Boolean &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Boolean::operator/(const Value &rhs) {
                    try {
                        auto cast = dynamic_cast<const Boolean &>(rhs);
                        this->_value = this->_value + cast._value;
                        return *this;
                    } catch (std::bad_cast &ex) {
                        throw;
                    }
                }

                Value &Boolean::operator%(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Boolean type");
                }
            }
        }
    }
}


