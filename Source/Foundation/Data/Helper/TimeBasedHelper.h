//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_HELPER_TIMEBASEDHELPER_H
#define CLDEPLUS_FOUNDATION_DATA_HELPER_TIMEBASEDHELPER_H

#include "../../../Port/Definitions.h"
#include "../TimeBasedValue.h"

namespace CLDEPlus {
    namespace Foundation {
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
}


#endif //CLDEPLUS_FOUNDATION_DATA_HELPER_TIMEBASEDHELPER_H
