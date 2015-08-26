//
// Created by LE, Duc Anh on 8/26/15.
//

#include "MySqlDateTimeImpl.h"

namespace Cloude {
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
