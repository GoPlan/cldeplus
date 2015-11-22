/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include "DateTime.h"
#include "../DataTypeException.h"
#include "../Helper/TimeBasedHelper.h"
#include "../../Exceptions/NotImplementedException.h"

namespace CLDEPlus {
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

            string DateTime::CopyToString() const {
                return Data::Helper::TimeBasedHelper::DateTimeToISO8601String(_dateTime);
            }

            Value &DateTime::operator+(Value const &rhs) {
                throw DataTypeException("operator% can not be applied to DateTime type");
            }

            Value &DateTime::operator-(Value const &rhs) {
                throw DataTypeException("operator% can not be applied to DateTime type");
            }

            Value &DateTime::operator*(Value const &rhs) {
                throw DataTypeException("operator% can not be applied to DateTime type");
            }

            Value &DateTime::operator/(Value const &rhs) {
                throw DataTypeException("operator% can not be applied to DateTime type");
            }

            Value &DateTime::operator%(Value const &rhs) {
                throw DataTypeException("operator% can not be applied to DateTime type");
            }

            bool DateTime::LessThan(IComparable const &target) const {
                string msg{"LessThan"};
                throw Exceptions::NotImplementedException{msg};
            }

            bool DateTime::GreaterThan(IComparable const &target) const {
                string msg{"GreaterThan"};
                throw Exceptions::NotImplementedException{msg};
            }

            bool DateTime::EquivalentTo(IComparable const &target) const {
                string msg{"EquivalentTo"};
                throw Exceptions::NotImplementedException{msg};
            }
        }
    }
}