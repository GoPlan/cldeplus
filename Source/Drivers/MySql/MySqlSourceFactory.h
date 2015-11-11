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

#ifndef CLDEPLUS_DRIVERS_MYSQL_MYSQLSOURCEHELPER_H
#define CLDEPLUS_DRIVERS_MYSQL_MYSQLSOURCEHELPER_H

#include "Data/MySqlDate.h"
#include "Data/MySqlTime.h"
#include "Data/MySqlDateTime.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {
            struct MySqlSourceFactory {

                static Data::SPtrMySqlDate CreateDate();
                static Data::SPtrMySqlDate CreateDate(unsigned int year,
                                                      unsigned int month,
                                                      unsigned int day);

                static Data::SPtrMySqlTime CreateTime();
                static Data::SPtrMySqlTime CreateTime(unsigned int hour,
                                                      unsigned int minute,
                                                      unsigned int second,
                                                      unsigned long millisecond = 0);

                static Data::SPtrMySqlDateTime CreateDateTime();
                static Data::SPtrMySqlDateTime CreateDateTime(unsigned int year,
                                                              unsigned int month,
                                                              unsigned int day);
                static Data::SPtrMySqlDateTime CreateDateTime(unsigned int year,
                                                              unsigned int month,
                                                              unsigned int day,
                                                              unsigned int hour,
                                                              unsigned int minute,
                                                              unsigned int second,
                                                              unsigned long millisecond = 0);
            };
        }
    }
}


#endif //CLDEPLUS_DRIVERS_MYSQL_MYSQLSOURCEHELPER_H
