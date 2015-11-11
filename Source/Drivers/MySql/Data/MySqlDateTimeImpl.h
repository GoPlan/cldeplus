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
