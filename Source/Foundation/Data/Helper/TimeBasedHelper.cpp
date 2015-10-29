//
// Created by LE, Duc Anh on 7/16/15.
//

#include "TimeBasedHelper.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Helper {

                std::string TimeBasedHelper::DateToISO8601String(const TimeBasedValue::TSDate &date) {

                    std::string year{std::to_string(date.year)};
                    std::string month{std::to_string(date.month)};
                    std::string day{std::to_string(date.day)};
                    std::string result = year + "-" + month + "-" + day;

                    return result;
                }
                std::string TimeBasedHelper::TimeToISO8601String(const TimeBasedValue::TSTime &time,
                                                                 bool hasMilliSecs,
                                                                 bool hasOffSet) {
                    std::string hour{std::to_string(time.hour)};
                    std::string minute{std::to_string(time.minute)};
                    std::string second{std::to_string(time.second)};
                    std::string milliSecs = hasMilliSecs ? "." + std::to_string(time.milliSecs) : "";
                    std::string offset = hasOffSet ? std::to_string(time.offset) : "";
                    std::string result = hour + ":" + minute + ":" + second + milliSecs + offset;

                    return result;
                }
                std::string TimeBasedHelper::DateTimeToISO8601String(const TimeBasedValue::TSDateTime &dateTime,
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


