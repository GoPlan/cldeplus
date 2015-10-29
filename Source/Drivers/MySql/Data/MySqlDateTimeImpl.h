//
// Created by LE, Duc Anh on 8/26/15.
//

#ifndef CLDEPLUS_DRIVER_MYSQL_DATA_MYSQLTIMEIMPL_H
#define CLDEPLUS_DRIVER_MYSQL_DATA_MYSQLTIMEIMPL_H

#include "mysql.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {
            namespace Data {

                struct MySqlDateTimeImpl {

                    MYSQL_TIME mysql_datetime;

                    void SetTime(unsigned int hour,
                                 unsigned int minute,
                                 unsigned int second,
                                 unsigned int millisecond = 0);

                    void SetDate(unsigned year,
                                 unsigned month,
                                 unsigned day);

                    void SetDateTime(unsigned int year,
                                     unsigned int month,
                                     unsigned int day,
                                     unsigned int hour = 0,
                                     unsigned int minute = 0,
                                     unsigned int second = 0,
                                     unsigned long milliseconds = 0);
                };
            }
        }
    }
}

#endif //CLDEPLUS_DRIVER_MYSQL_DATA_MYSQLTIMEIMPL_H
