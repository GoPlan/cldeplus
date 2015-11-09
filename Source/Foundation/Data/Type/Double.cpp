//
// Created by LE, Duc Anh on 6/10/15.
//

#include "Double.h"
#include "../../Exception/CLDENonSupportedFunctionException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Double::Double(double value) : _value(value),
                                               NumericValue(ValueType::Double, sizeof(double)) {
                    //
                }

                void *Double::PointerToBuffer() {
                    return &_value;
                }

                string Double::ToString() const {
                    return std::to_string(_value);
                }

                Value &Double::operator+(Value const &rhs) {
                    auto cast = dynamic_cast<const Double &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Double::operator-(Value const &rhs) {
                    auto cast = dynamic_cast<const Double &>(rhs);
                    this->_value = this->_value - cast._value;
                    return *this;
                }

                Value &Double::operator*(Value const &rhs) {
                    auto cast = dynamic_cast<const Double &>(rhs);
                    this->_value = this->_value * cast._value;
                    return *this;
                }

                Value &Double::operator/(Value const &rhs) {
                    auto cast = dynamic_cast<const Double &>(rhs);
                    this->_value = this->_value / cast._value;
                    return *this;
                }

                Value &Double::operator%(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Double type");
                }

                Value &Double::operator=(bool value) {
                    _value = (bool) value;
                    return *this;
                }

                Value &Double::operator=(double value) {
                    _value = value;
                    return *this;
                }

                Value &Double::operator=(float value) {
                    _value = (double) value;
                    return *this;
                }

                Value &Double::operator=(int16 value) {
                    _value = (double) value;
                    return *this;
                }

                Value &Double::operator=(int32 value) {
                    _value = (double) value;
                    return *this;
                }

                Value &Double::operator=(int64 value) {
                    _value = (double) value;
                    return *this;
                }

                Value &Double::operator=(uint16 value) {
                    _value = (double) value;
                    return *this;
                }

                Value &Double::operator=(uint32 value) {
                    _value = (double) value;
                    return *this;
                }

                Value &Double::operator=(uint64 value) {
                    _value = (double) value;
                    return *this;
                }
            }
        }
    }
}


