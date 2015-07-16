//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Data/Helper/TimeBasedHelper.h>
#include "Date.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                void *Date::RawPointerToValueBuffer() {
                    return &_date;
                }
                std::string Date::ToString() const {
                    return Data::Helper::TimeBasedHelper::DateToISO8601String(_date);
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


