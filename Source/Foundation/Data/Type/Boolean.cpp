//
// Created by LE, Duc Anh on 6/24/15.
//

#include "../../Exception/CLDENonSupportedFunctionException.h"
#include "Boolean.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {


                Boolean::Boolean(bool value)
                        : NumericValue{ValueType::Boolean, sizeof(bool)}, _value{value} {
                    //
                }

                void *Boolean::PointerToBuffer() {
                    return &_value;
                }

                std::string Boolean::ToString() const {
                    return std::to_string(_value);
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
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Boolean type");
                }
            }
        }
    }
}


