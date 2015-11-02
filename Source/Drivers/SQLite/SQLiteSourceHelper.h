//
// Created by LE, Duc Anh on 6/17/15.
//

#ifndef CLDEPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEHELPER_H
#define CLDEPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEHELPER_H

#include "cldeplus_default"
#include "Amalgamation/sqlite3.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace SQLite {

            class SQLiteSourceHelper {

            public:
                static std::string CopyToString(int resultCode);

            private:
                SQLiteSourceHelper() = default;
                SQLiteSourceHelper(const SQLiteSourceHelper &) = default;
                SQLiteSourceHelper(SQLiteSourceHelper &&) = default;
                SQLiteSourceHelper &operator=(const SQLiteSourceHelper &) = default;
                SQLiteSourceHelper &operator=(SQLiteSourceHelper &&) = default;
                ~SQLiteSourceHelper() = default;
            };
        }
    }
}

#endif //CLDEPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEHELPER_H
