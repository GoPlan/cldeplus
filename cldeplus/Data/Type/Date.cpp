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

#include "Date.h"
#include "../DataTypeException.h"
#include "../Helper/TimeBasedHelper.h"
#include "../../Exceptions/NotImplementedException.h"

namespace CLDEPlus {
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

            Value &Date::operator+(Value const &rhs) {
                throw DataTypeException("operator% can not be applied to DateTime type");
            }

            Value &Date::operator-(Value const &rhs) {
                throw DataTypeException("operator% can not be applied to DateTime type");
            }

            Value &Date::operator*(Value const &rhs) {
                throw DataTypeException("operator% can not be applied to DateTime type");
            }

            Value &Date::operator/(Value const &rhs) {
                throw DataTypeException("operator% can not be applied to DateTime type");
            }

            Value &Date::operator%(Value const &rhs) {
                throw DataTypeException("operator% can not be applied to DateTime type");
            }

            bool Date::LessThan(IComparable const &target) const {
                string msg{"LessThan"};
                throw Exceptions::NotImplementedException{msg};
            }

            bool Date::GreaterThan(IComparable const &target) const {
                string msg{"GreaterThan"};
                throw Exceptions::NotImplementedException{msg};
            }

            bool Date::EquivalentTo(IComparable const &target) const {
                string msg{"EquivalentTo"};
                throw Exceptions::NotImplementedException{msg};
            }
        }
    }
}


