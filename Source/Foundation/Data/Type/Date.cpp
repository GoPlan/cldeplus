//
// Created by LE, Duc Anh on 6/24/15.
//

#include "Date.h"
#include "../../Exception/CLDENonSupportedFunctionException.h"
#include "../../Exception/CLDENotImplementedException.h"
#include "../Helper/TimeBasedHelper.h"

namespace CLDEPlus {
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

                void *Date::PointerToBuffer() {
                    return &_date;
                }

                string Date::ToString() const {
                    return Data::Helper::TimeBasedHelper::DateToISO8601String(_date);
                }

                Value &Date::operator+(const Value &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                Value &Date::operator-(const Value &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                Value &Date::operator*(const Value &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                Value &Date::operator/(const Value &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                Value &Date::operator%(const Value &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                bool Date::LessThan(const Common::IComparable &target) const {
                    string msg{"LessThan"};
                    throw Exception::CLDENotImplementedException{msg};
                }

                bool Date::GreaterThan(const Common::IComparable &target) const {
                    string msg{"GreaterThan"};
                    throw Exception::CLDENotImplementedException{msg};
                }

                bool Date::EquivalentTo(const Common::IComparable &target) const {
                    string msg{"EquivalentTo"};
                    throw Exception::CLDENotImplementedException{msg};
                }
            }
        }
    }
}


