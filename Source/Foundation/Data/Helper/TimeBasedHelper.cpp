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

#include "TimeBasedHelper.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Helper {

                string TimeBasedHelper::DateToISO8601String(const TimeBasedValue::TSDate &date) {

                    string year{std::to_string(date.year)};
                    string month{std::to_string(date.month)};
                    string day{std::to_string(date.day)};
                    string result = year + "-" + month + "-" + day;

                    return result;
                }
                string TimeBasedHelper::TimeToISO8601String(const TimeBasedValue::TSTime &time,
                                                                 bool hasMilliSecs,
                                                                 bool hasOffSet) {
                    string hour{std::to_string(time.hour)};
                    string minute{std::to_string(time.minute)};
                    string second{std::to_string(time.second)};
                    string milliSecs = hasMilliSecs ? "." + std::to_string(time.milliSecs) : "";
                    string offset = hasOffSet ? std::to_string(time.offset) : "";
                    string result = hour + ":" + minute + ":" + second + milliSecs + offset;

                    return result;
                }
                string TimeBasedHelper::DateTimeToISO8601String(const TimeBasedValue::TSDateTime &dateTime,
                                                                     bool hasMilliSecs,
                                                                     bool hasOffSet) {
                    return DateToISO8601String(dateTime.date) + TimeToISO8601String(dateTime.time,
                                                                                    hasMilliSecs,
                                                                                    hasOffSet);
                }
            }
        }
    }
}


