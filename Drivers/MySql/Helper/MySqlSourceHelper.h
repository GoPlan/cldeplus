//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_DRIVERS_MYSQL_MYSQLSOURCEHELPER_H
#define CLOUD_E_PLUS_DRIVERS_MYSQL_MYSQLSOURCEHELPER_H

#include <mysql.h>
#include <Foundation/Data/TimeBasedValue.h>
#include <Drivers/MySql/Data/MySqlDate.h>
#include <Drivers/MySql/Data/MySqlTime.h>
#include <Drivers/MySql/Data/MySqlDateTime.h>

namespace Cloude {
    namespace Drivers {
        namespace MySql {
            namespace Helper {
                struct MySqlSourceHelper {

                    static MYSQL_TIME DateToMYSQLTIME(const Foundation::Data::TimeBasedValue::TSDate &date);
                    static MYSQL_TIME TimeToMYSQLTIME(const Foundation::Data::TimeBasedValue::TSTime &time);
                    static MYSQL_TIME DateTimeToMYSQLTIME(const Foundation::Data::TimeBasedValue::TSDateTime &dateTime);

                    static bool Less(const MYSQL_TIME& lhs, const MYSQL_TIME& rhs);
                    static bool Greater(const MYSQL_TIME& lhs, const MYSQL_TIME& rhs);
                    static bool Compare(const MYSQL_TIME& lhs, const MYSQL_TIME& rhs);

                    static std::string DateToISO8601String(const MYSQL_TIME &date);
                    static std::string TimeToISO8601String(const MYSQL_TIME &time);
                    static std::string DateTimeToISO8601String(const MYSQL_TIME &dateTime);

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
}


#endif //CLOUD_E_PLUS_DRIVERS_MYSQL_MYSQLSOURCEHELPER_H
