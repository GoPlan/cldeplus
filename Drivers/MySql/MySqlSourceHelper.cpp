//
// Created by LE, Duc Anh on 7/16/15.
//

#include <Foundation/Data/TimeBasedValue.h>
#include "MySqlSourceHelper.h"

namespace Cloude {
    namespace Drivers {
        namespace MySql {

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
        }
    }
}


