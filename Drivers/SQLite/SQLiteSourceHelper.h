//
// Created by LE, Duc Anh on 6/17/15.
//

#ifndef CLOUD_E_PLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEHELPER_H
#define CLOUD_E_PLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEHELPER_H

#include <string>
#include "Amalgamation/sqlite3.h"

namespace Cloude {
    namespace SourceDriver {
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

#endif //CLOUD_E_PLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEHELPER_H
