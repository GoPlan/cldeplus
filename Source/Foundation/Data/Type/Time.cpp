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

#include "Time.h"
#include "../Helper/TimeBasedHelper.h"
#include "../../Exception/CLDENonSupportedFunctionException.h"
#include "../../Exception/CLDENotImplementedException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Time::Time()
                        : TimeBasedValue{ValueType::Time, sizeof(TimeBasedValue::TSTime)} {
                    //
                }

                Time::Time(int hour, int minute, int second, int millisecond, bool hasOffSet, int offset)
                        : TimeBasedValue{ValueType::Time, sizeof(TimeBasedValue::TSTime)} {
                    _time.hour = hour;
                    _time.minute = minute;
                    _time.second = second;
                    _time.milliSecs = millisecond;
                    _time.offset = offset;
                    _hasOffSet = hasOffSet;
                }

                void *Time::PointerToBuffer() {
                    return &_time;
                }

                string Time::ToString() const {
                    return Data::Helper::TimeBasedHelper::TimeToISO8601String(_time, true, _hasOffSet);
                }

                Value &Time::operator+(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Time type");
                }

                Value &Time::operator-(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Time type");
                }

                Value &Time::operator*(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Time type");
                }

                Value &Time::operator/(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Time type");
                }

                Value &Time::operator%(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Time type");
                }

                bool Time::LessThan(Common::IComparable const &target) const {
                    string msg{"LessThan"};
                    throw Exception::CLDENotImplementedException{msg};
                }

                bool Time::GreaterThan(Common::IComparable const &target) const {
                    string msg{"GreaterThan"};
                    throw Exception::CLDENotImplementedException{msg};
                }

                bool Time::EquivalentTo(Common::IComparable const &target) const {
                    string msg{"EquivalentTo"};
                    throw Exception::CLDENotImplementedException{msg};
                }
            }
        }
    }
}


