//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Data/Helper/TimeBasedHelper.h>
#include <Foundation/Exception/cldeNotImplementedException.h>
#include "Date.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Date::Date()
                        : TimeBasedValue{ValueType::Date, sizeof(TimeBasedValue::TSDate)} {
                    //
                }

                Date::Date(int year, int month, int day)
                        : TimeBasedValue{ValueType::Date, sizeof(TimeBasedValue::TSDate)} {
                    _date.year = year;
                    _date.month = month;
                    _date.day = day;
                }

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

                bool Date::LessThan(const Common::IComparable &target) const {
                    std::string msg{"LessThan"};
                    throw Exception::cldeNotImplementedException{msg};
                }

                bool Date::GreaterThan(const Common::IComparable &target) const {
                    std::string msg{"GreaterThan"};
                    throw Exception::cldeNotImplementedException{msg};
                }

                bool Date::EquivalentTo(const Common::IComparable &target) const {
                    std::string msg{"EquivalentTo"};
                    throw Exception::cldeNotImplementedException{msg};
                }
            }
        }
    }
}


