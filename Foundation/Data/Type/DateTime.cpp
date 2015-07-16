//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Data/Helper/TimeBasedHelper.h>
#include "DateTime.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                void *DateTime::RawPointerToValueBuffer() {
                    return &_dateTime;
                }
                std::string DateTime::ToString() const {
                    return Data::Helper::TimeBasedHelper::DateTimeToISO8601String(_dateTime);
                }
                Value &DateTime::operator+(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to DateTime type");
                }
                Value &DateTime::operator-(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to DateTime type");
                }
                Value &DateTime::operator*(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to DateTime type");
                }
                Value &DateTime::operator/(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to DateTime type");
                }
                Value &DateTime::operator%(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to DateTime type");
                }
            }
        }
    }
}