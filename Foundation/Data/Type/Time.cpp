//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Data/Helper/TimeBasedHelper.h>
#include "Time.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                void *Time::RawPointerToValueBuffer() {
                    return &_time;
                }
                std::string Time::ToString() const {
                    return Data::Helper::TimeBasedHelper::TimeToISO8601String(_time);
                }
                Value &Time::operator+(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Time type");
                }
                Value &Time::operator-(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Time type");
                }
                Value &Time::operator*(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Time type");
                }
                Value &Time::operator/(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Time type");
                }
                Value &Time::operator%(const Value &rhs) {
                    throw Exception::cldeNonSupportedFunctionException("operator% can not be applied to Time type");
                }
            }
        }
    }
}


