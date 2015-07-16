//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_DRIVERS_MYSQL_MYSQLSOURCEHELPER_H
#define CLOUD_E_PLUS_DRIVERS_MYSQL_MYSQLSOURCEHELPER_H

#include <mysql.h>
#include <Foundation/Data/TimeBasedValue.h>

namespace Cloude{
    namespace Drivers {
        namespace MySql {
            struct MySqlSourceHelper {
                static MYSQL_TIME DateToMYSQLTIME(const Foundation::Data::TimeBasedValue::TSDate& date);
                static MYSQL_TIME TimeToMYSQLTIME(const Foundation::Data::TimeBasedValue::TSTime& time);
                static MYSQL_TIME DateTimeToMYSQLTIME(const Foundation::Data::TimeBasedValue::TSDateTime& dateTime);
            };
        }
    }
}



#endif //CLOUD_E_PLUS_DRIVERS_MYSQL_MYSQLSOURCEHELPER_H
