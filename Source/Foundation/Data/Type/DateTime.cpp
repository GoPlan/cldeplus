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

                DateTime::DateTime(int year, int month, int day,
                                   int hour, int minute, int second, int millisecond,
                                   bool hasOffSet, int offset)
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

                std::string DateTime::ToString() const {
                    return Data::Helper::TimeBasedHelper::DateTimeToISO8601String(_dateTime);
                }

                Value &DateTime::operator+(const Value &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                Value &DateTime::operator-(const Value &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                Value &DateTime::operator*(const Value &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                Value &DateTime::operator/(const Value &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                Value &DateTime::operator%(const Value &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to DateTime type");
                }

                bool DateTime::LessThan(const Common::IComparable &target) const {
                    std::string msg{"LessThan"};
                    throw Exception::CLDENotImplementedException{msg};
                }

                bool DateTime::GreaterThan(const Common::IComparable &target) const {
                    std::string msg{"GreaterThan"};
                    throw Exception::CLDENotImplementedException{msg};
                }

                bool DateTime::EquivalentTo(const Common::IComparable &target) const {
                    std::string msg{"EquivalentTo"};
                    throw Exception::CLDENotImplementedException{msg};
                }
            }
        }
    }
}