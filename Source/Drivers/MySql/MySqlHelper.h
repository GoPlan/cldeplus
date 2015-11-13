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

#ifndef CLDEPLUS_DRIVERS_MYSQL_HELPER_MYSQLHELPER_H
#define CLDEPLUS_DRIVERS_MYSQL_HELPER_MYSQLHELPER_H

#include <mysql.h>
#include "../../Portable/CommonTypes.h"
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
                static string DateToISO8601String(const MYSQL_TIME &date);
                static string TimeToISO8601String(const MYSQL_TIME &time);
                static string DateTimeToISO8601String(const MYSQL_TIME &dateTime);
            };
        }
    }
}


#endif //CLDEPLUS_DRIVERS_MYSQL_HELPER_MYSQLHELPER_H
