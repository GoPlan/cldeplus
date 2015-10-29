//
// Created by LE, Duc Anh on 8/26/15.
//

#ifndef CLDEPLUS_DRIVERS_MYSQL_HELPER_MYSQLHELPER_H
#define CLDEPLUS_DRIVERS_MYSQL_HELPER_MYSQLHELPER_H

#include <string>
#include <mysql.h>
#include "../../Foundation/Data/TimeBasedValue.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {
            struct MySqlHelper {
                static MYSQL_TIME DateToMYSQLTIME(const Foundation::Data::TimeBasedValue::TSDate &date);
                static MYSQL_TIME TimeToMYSQLTIME(const Foundation::Data::TimeBasedValue::TSTime &time);
                static MYSQL_TIME DateTimeToMYSQLTIME(const Foundation::Data::TimeBasedValue::TSDateTime &dateTime);
                static bool Less(const MYSQL_TIME &lhs, const MYSQL_TIME &rhs);
                static bool Greater(const MYSQL_TIME &lhs, const MYSQL_TIME &rhs);
                static bool Compare(const MYSQL_TIME &lhs, const MYSQL_TIME &rhs);
                static std::string DateToISO8601String(const MYSQL_TIME &date);
                static std::string TimeToISO8601String(const MYSQL_TIME &time);
                static std::string DateTimeToISO8601String(const MYSQL_TIME &dateTime);
            };
        }
    }
}


#endif //CLDEPLUS_DRIVERS_MYSQL_HELPER_MYSQLHELPER_H
