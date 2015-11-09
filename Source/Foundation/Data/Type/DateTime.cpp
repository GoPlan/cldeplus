//
// Created by LE, Duc Anh on 6/24/15.
//

#include "DateTime.h"
#include "../../Exception/CLDENonSupportedFunctionException.h"
#include "../../Exception/CLDENotImplementedException.h"
#include "../Helper/TimeBasedHelper.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                DateTime::DateTime()
                        : TimeBasedValue{ValueType::DateTime, sizeof(TimeBasedValue::TSDateTime)} {
                    //
                }

                DateTime::DateTime(int year, int month, int day)
                        : TimeBasedValue{ValueType::DateTime, sizeof(TimeBasedValue::TSDateTime)} {
                    _dateTime.date.year = year;
                    _dateTime.date.month = month;
                    _dateTime.date.day = day;
                }

                DateTime::DateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, int offset)
                        : TimeBasedValue{ValueType::DateTime, sizeof(TimeBasedValue::TSDateTime)} {
                    _dateTime.date.year = year;
                    _dateTime.date.month = month;
                    _dateTime.date.day = day;
                    _dateTime.time.hour = hour;
                    _dateTime.time.minute = minute;
                    _dateTime.time.second = second;
                    _dateTime.time.milliSecs = millisecond;
                    _dateTime.time.offset = offset;
                }

                void *DateTime::PointerToBuffer() {
                    return &_dateTime;
                }

                string DateTime::ToString() const {
                    return Data::Helper::TimeBasedHelper::DateTimeToISO8601String(_dateTime);
                }

                Value &DateTime::operator+(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                Value &DateTime::operator-(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                Value &DateTime::operator*(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                Value &DateTime::operator/(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                Value &DateTime::operator%(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                bool DateTime::LessThan(Common::IComparable const &target) const {
                    string msg{"LessThan"};
                    throw Exception::CLDENotImplementedException{msg};
                }

                bool DateTime::GreaterThan(Common::IComparable const &target) const {
                    string msg{"GreaterThan"};
                    throw Exception::CLDENotImplementedException{msg};
                }

                bool DateTime::EquivalentTo(Common::IComparable const &target) const {
                    string msg{"EquivalentTo"};
                    throw Exception::CLDENotImplementedException{msg};
                }
            }
        }
    }
}