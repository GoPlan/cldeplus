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

                string Boolean::ToString() const {
                    return std::to_string(_value);
                }

                Value &Boolean::operator+(const Value &rhs) {
                    auto cast = dynamic_cast<const Boolean &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Boolean::operator-(const Value &rhs) {
                    auto cast = dynamic_cast<const Boolean &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Boolean::operator*(const Value &rhs) {
                    auto cast = dynamic_cast<const Boolean &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Boolean::operator/(const Value &rhs) {
                    auto cast = dynamic_cast<const Boolean &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Boolean::operator%(const Value &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Boolean type");
                }

                Value &Boolean::operator=(bool value) {
                    _value = value;
                    return *this;
                }

                Value &Boolean::operator=(double value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(float value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(int16 value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(int32 value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(int64 value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(uint16 value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(uint32 value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Boolean::operator=(uint64 value) {
                    _value = (bool) value;
                    return *this;
                }
            }
        }
    }
}


