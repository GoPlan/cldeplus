//
// Created by LE, Duc Anh on 6/17/15.
//

#ifndef CLDEPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEHELPER_H
#define CLDEPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEHELPER_H

#include "../../Port/Definitions.h"
#include "Amalgamation/sqlite3.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace SQLite {

            class SQLiteSourceHelper {

            public:
                static CLDEPlus::string CopyToString(int resultCode);

            private:
                SQLiteSourceHelper() = default;
                SQLiteSourceHelper(SQLiteSourceHelper const &) = default;
                SQLiteSourceHelper(SQLiteSourceHelper &&) = default;
                SQLiteSourceHelper &operator=(SQLiteSourceHelper const &) = default;
                SQLiteSourceHelper &operator=(SQLiteSourceHelper &&) = default;
                ~SQLiteSourceHelper() = default;
            };
        }
    }
}

#endif //CLDEPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEHELPER_H
