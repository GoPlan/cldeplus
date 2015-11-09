//
// Created by LE, Duc Anh on 6/10/15.
//

#include "Float.h"
#include "../../Exception/CLDENonSupportedFunctionException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Float::Float(float value) : _value(value),
                                            NumericValue(ValueType::Float, sizeof(float)) {
                    //
                }

                void *Float::PointerToBuffer() {
                    return &_value;
                }

                string Float::ToString() const {
                    return std::to_string(_value);
                }

                Value &Float::operator+(Value const &rhs) {
                    auto cast = dynamic_cast<const Float &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Float::operator-(Value const &rhs) {
                    auto cast = dynamic_cast<const Float &>(rhs);
                    this->_value = this->_value - cast._value;
                    return *this;
                }

                Value &Float::operator*(Value const &rhs) {
                    auto cast = dynamic_cast<const Float &>(rhs);
                    this->_value = this->_value * cast._value;
                    return *this;
                }

                Value &Float::operator/(Value const &rhs) {
                    auto cast = dynamic_cast<const Float &>(rhs);
                    this->_value = this->_value / cast._value;
                    return *this;
                }

                Value &Float::operator%(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Double type");
                }

                Value &Float::operator=(bool value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(double value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(float value) {
                    _value = value;
                    return *this;
                }

                Value &Float::operator=(int16 value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(int32 value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(int64 value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(uint16 value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(uint32 value) {
                    _value = (float) value;
                    return *this;
                }

                Value &Float::operator=(uint64 value) {
                    _value = (float) value;
                    return *this;
                }
            }
        }
    }
}


