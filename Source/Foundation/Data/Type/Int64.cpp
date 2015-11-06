//
// Created by LE, Duc Anh on 6/10/15.
//

#include <cstdlib>
#include "Int64.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Int64::Int64(int64_t value) : _value(value),
                                              NumericValue(ValueType::Int64, sizeof(int64_t)) {
                    //
                }

                void *Int64::PointerToBuffer() {
                    return &this->_value;
                }

                string Int64::ToString() const {
                    return std::to_string(_value);
                }

                Value &Int64::operator+(Value const &rhs) {
                    auto cast = dynamic_cast< Int64 const &>(rhs);
                    this->_value = this->_value + cast._value;
                    return *this;
                }

                Value &Int64::operator-(Value const &rhs) {
                    auto cast = dynamic_cast<const Int64 &>(rhs);
                    this->_value = this->_value - cast._value;
                    return *this;
                }

                Value &Int64::operator*(Value const &rhs) {
                    auto cast = dynamic_cast<const Int64 &>(rhs);
                    this->_value = this->_value * cast._value;
                    return *this;
                }

                Value &Int64::operator/(Value const &rhs) {
                    auto cast = dynamic_cast<const Int64 &>(rhs);
                    this->_value = this->_value / cast._value;
                    return *this;
                }

                Value &Int64::operator%(const Value &rhs) {
                    auto cast = dynamic_cast<const Int64 &>(rhs);
                    this->_value = this->_value % cast._value;
                    return *this;
                }
            }
        }
    }
}


