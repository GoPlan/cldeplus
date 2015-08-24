//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_HELPER_TIMEBASEDHELPER_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_HELPER_TIMEBASEDHELPER_H

#include <string>
#include "../TimeBasedValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Helper {
                struct TimeBasedHelper {
                    static std::string DateToISO8601String(const TimeBasedValue::TSDate &date);
                    static std::string TimeToISO8601String(const TimeBasedValue::TSTime &time, bool hasMilliSecs = true, bool hasOffSet = true);
                    static std::string DateTimeToISO8601String(const TimeBasedValue::TSDateTime &dateTime, bool hasMilliSecs = true, bool hasOffSet = true);
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_HELPER_TIMEBASEDHELPER_H
