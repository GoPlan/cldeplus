//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_DRIVERS_MYSQL_MYSQLSOURCEHELPER_H
#define CLOUD_E_PLUS_DRIVERS_MYSQL_MYSQLSOURCEHELPER_H

#include "Data/MySqlDate.h"
#include "Data/MySqlTime.h"
#include "Data/MySqlDateTime.h"

namespace Cloude {
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


#endif //CLOUD_E_PLUS_DRIVERS_MYSQL_MYSQLSOURCEHELPER_H
