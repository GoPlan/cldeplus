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

#include "MySqlDateTimeImpl.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {
            namespace Data {


                void MySqlDateTimeImpl::SetTime(unsigned int hour,
                                                unsigned int minute,
                                                unsigned int second,
                                                unsigned int millisecond) {
                    mysql_datetime.year = 0;
                    mysql_datetime.month = 0;
                    mysql_datetime.day = 0;
                    mysql_datetime.hour = hour;
                    mysql_datetime.minute = minute;
                    mysql_datetime.second = second;
                    mysql_datetime.second_part = millisecond;
                    mysql_datetime.neg = false;
                    mysql_datetime.time_type = MYSQL_TIMESTAMP_TIME;
                }

                void MySqlDateTimeImpl::SetDate(unsigned year, unsigned month, unsigned day) {
                    mysql_datetime.year = year;
                    mysql_datetime.month = month;
                    mysql_datetime.day = day;
                    mysql_datetime.hour = 0;
                    mysql_datetime.minute = 0;
                    mysql_datetime.second = 0;
                    mysql_datetime.second_part = 0;
                    mysql_datetime.neg = false;
                    mysql_datetime.time_type = MYSQL_TIMESTAMP_DATE;
                }

                void MySqlDateTimeImpl::SetDateTime(unsigned int year,
                                                    unsigned int month,
                                                    unsigned int day,
                                                    unsigned int hour,
                                                    unsigned int minute,
                                                    unsigned int second,
                                                    unsigned long milliseconds) {
                    mysql_datetime.year = year;
                    mysql_datetime.month = month;
                    mysql_datetime.day = day;
                    mysql_datetime.hour = hour;
                    mysql_datetime.minute = minute;
                    mysql_datetime.second = second;
                    mysql_datetime.second_part = milliseconds;
                    mysql_datetime.neg = false;
                    mysql_datetime.time_type = MYSQL_TIMESTAMP_DATETIME;
                }
            }
        }
    }
}
