//
// Created by LE, Duc Anh on 6/24/15.
//

#include "Date.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                std::string Date::ToString() const {
                    return std::string{};
                }
                void *Date::RawPointerToValueBuffer() {
                    return &_date;
                }
                Value &Date::operator+(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to DateTime type");
                }
                Value &Date::operator-(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to DateTime type");
                }
                Value &Date::operator*(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to DateTime type");
                }
                Value &Date::operator/(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to DateTime type");
                }
                Value &Date::operator%(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to DateTime type");
                }
            }
        }
    }
}


