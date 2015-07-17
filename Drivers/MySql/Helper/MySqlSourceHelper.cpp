//
// Created by LE, Duc Anh on 7/16/15.
//

#include <Foundation/Data/TimeBasedValue.h>
#include <Drivers/MySql/Data/MySqlTime.h>
#include "MySqlSourceHelper.h"

namespace Cloude {
    namespace Drivers {
        namespace MySql {
            namespace Helper {

                using CldeTimeBasedValue = Foundation::Data::TimeBasedValue;

                MYSQL_TIME MySqlSourceHelper::DateToMYSQLTIME(const CldeTimeBasedValue::TSDate &date) {

                    MYSQL_TIME mysqlDate;
                    mysqlDate.year = static_cast<unsigned int>(date.year);
                    mysqlDate.month = static_cast<unsigned int>(date.month);
                    mysqlDate.day = static_cast<unsigned int>(date.day);

                    return mysqlDate;
                }

                MYSQL_TIME MySqlSourceHelper::TimeToMYSQLTIME(const CldeTimeBasedValue::TSTime &time) {

                    MYSQL_TIME mysqlTime;
                    mysqlTime.hour = static_cast<unsigned int>(time.hour);
                    mysqlTime.minute = static_cast<unsigned int>(time.minute);
                    mysqlTime.second = static_cast<unsigned int>(time.second);
                    mysqlTime.second_part = static_cast<unsigned long>(time.milliSecs);

                    return mysqlTime;
                }

                MYSQL_TIME MySqlSourceHelper::DateTimeToMYSQLTIME(const CldeTimeBasedValue::TSDateTime &dateTime) {

                    MYSQL_TIME mysqlDateTime;
                    mysqlDateTime.year = static_cast<unsigned int>(dateTime.date.year);
                    mysqlDateTime.month = static_cast<unsigned int>(dateTime.date.month);
                    mysqlDateTime.day = static_cast<unsigned int>(dateTime.date.day);
                    mysqlDateTime.hour = static_cast<unsigned int>(dateTime.time.hour);
                    mysqlDateTime.minute = static_cast<unsigned int>(dateTime.time.minute);
                    mysqlDateTime.second = static_cast<unsigned int>(dateTime.time.second);
                    mysqlDateTime.second_part = static_cast<unsigned long>(dateTime.time.milliSecs);

                    return mysqlDateTime;
                }

                bool MySqlSourceHelper::Less(const MYSQL_TIME &lhs, const MYSQL_TIME &rhs) {

                    if ((lhs.year - rhs.year) != 0) return lhs.year < rhs.year;
                    if ((lhs.month - rhs.month) != 0) return lhs.month < rhs.month;
                    if ((lhs.day - rhs.day) != 0) return lhs.day < rhs.day;
                    if ((lhs.hour - rhs.hour) != 0) return lhs.hour < rhs.hour;
                    if ((lhs.minute - rhs.minute) != 0) return lhs.minute < rhs.minute;
                    if ((lhs.second - rhs.second) != 0) return lhs.second < rhs.second;
                    if ((lhs.second_part - rhs.second_part) != 0) return lhs.second_part < rhs.second_part;

                    return false;
                }

                bool MySqlSourceHelper::Greater(const MYSQL_TIME &lhs, const MYSQL_TIME &rhs) {

                    if ((lhs.year - rhs.year) != 0) return lhs.year > rhs.year;
                    if ((lhs.month - rhs.month) != 0) return lhs.month > rhs.month;
                    if ((lhs.day - rhs.day) != 0) return lhs.day > rhs.day;
                    if ((lhs.hour - rhs.hour) != 0) return lhs.hour > rhs.hour;
                    if ((lhs.minute - rhs.minute) != 0) return lhs.minute > rhs.minute;
                    if ((lhs.second - rhs.second) != 0) return lhs.second > rhs.second;
                    if ((lhs.second_part - rhs.second_part) != 0) return lhs.second_part > rhs.second_part;

                    return false;
                }

                bool MySqlSourceHelper::Compare(const MYSQL_TIME &lhs, const MYSQL_TIME &rhs) {
                    return !MySqlSourceHelper::Less(lhs, rhs) && !MySqlSourceHelper::Greater(lhs, rhs);
                }

                std::string MySqlSourceHelper::DateToISO8601String(const MYSQL_TIME &date) {

                    std::string year{std::to_string(date.year)};
                    std::string month{std::to_string(date.month)};
                    std::string day{std::to_string(date.day)};
                    std::string result = year + "-" + month + "-" + day;

                    return result;
                }

                std::string MySqlSourceHelper::TimeToISO8601String(const MYSQL_TIME &time) {

                    std::string hour{std::to_string(time.hour)};
                    std::string minute{std::to_string(time.minute)};
                    std::string second{std::to_string(time.second)};
                    std::string milliseconds{std::to_string(time.second_part)};
                    std::string result = hour + ":" + minute + ":" + second + "." + milliseconds;

                    return result;
                }

                std::string MySqlSourceHelper::DateTimeToISO8601String(const MYSQL_TIME &dateTime) {

                    std::string year{std::to_string(dateTime.year)};
                    std::string month{std::to_string(dateTime.month)};
                    std::string day{std::to_string(dateTime.day)};
                    std::string dayPart = year + "-" + month + "-" + day;

                    std::string hour{std::to_string(dateTime.hour)};
                    std::string minute{std::to_string(dateTime.minute)};
                    std::string second{std::to_string(dateTime.second)};
                    std::string milliseconds{std::to_string(dateTime.second_part)};
                    std::string timePart = hour + ":" + minute + ":" + second + "." + milliseconds;

                    std::string result = dayPart + " " + timePart;

                    return result;
                }

                Data::SPtrMySqlDate MySqlSourceHelper::CreateDate() {
                    return std::make_shared<Data::MySqlDate>();
                }

                Data::SPtrMySqlDate MySqlSourceHelper::CreateDate(unsigned int year,
                                                                  unsigned int month,
                                                                  unsigned int day) {
                    return std::make_shared<Data::MySqlDate>(year, month, day);
                }

                Data::SPtrMySqlTime MySqlSourceHelper::CreateTime() {
                    return std::make_shared<Data::MySqlTime>();
                }

                Data::SPtrMySqlTime MySqlSourceHelper::CreateTime(unsigned int hour,
                                                                  unsigned int minute,
                                                                  unsigned int second,
                                                                  unsigned long millisecond) {
                    return std::make_shared<Data::MySqlTime>(hour, minute, second, millisecond);
                }

                Data::SPtrMySqlDateTime MySqlSourceHelper::CreateDateTime() {
                    return std::make_shared<Data::MySqlDateTime>();
                }

                Data::SPtrMySqlDateTime MySqlSourceHelper::CreateDateTime(unsigned int year,
                                                                          unsigned int month,
                                                                          unsigned int day) {
                    return std::make_shared<Data::MySqlDateTime>(year, month, day);
                }

                Data::SPtrMySqlDateTime MySqlSourceHelper::CreateDateTime(unsigned int year,
                                                                          unsigned int month,
                                                                          unsigned int day,
                                                                          unsigned int hour,
                                                                          unsigned int minute,
                                                                          unsigned int second,
                                                                          unsigned long millisecond) {
                    return std::make_shared<Data::MySqlDateTime>(year, month, day, hour, minute, second, millisecond);
                }

            }
        }
    }
}


