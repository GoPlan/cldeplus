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

#ifndef CLDEPLUS_DATA_HELPER_TIMEBASEDHELPER_H
#define CLDEPLUS_DATA_HELPER_TIMEBASEDHELPER_H

#include "../TimeBasedValue.h"

namespace CLDEPlus {
    namespace Data {
        namespace Helper {
            struct TimeBasedHelper {
                static string DateToISO8601String(const TimeBasedValue::TSDate &date);
                static string TimeToISO8601String(const TimeBasedValue::TSTime &time, bool hasMilliSecs = true, bool hasOffSet = true);
                static string DateTimeToISO8601String(const TimeBasedValue::TSDateTime &dateTime, bool hasMilliSecs = true, bool hasOffSet = true);
            };
        }
    }
}


#endif //CLDEPLUS_DATA_HELPER_TIMEBASEDHELPER_H
