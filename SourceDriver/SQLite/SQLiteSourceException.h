//
// Created by LE, Duc Anh on 6/7/15.
//

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H

namespace Cloude {
    namespace SourceDriver {
        namespace SQLite {
            class SQLiteSourceException {
            public:
                SQLiteSourceException() = default;
                SQLiteSourceException(const SQLiteSourceException &) = default;
                SQLiteSourceException(SQLiteSourceException &&) = default;
                SQLiteSourceException &operator=(const SQLiteSourceException &) = default;
                SQLiteSourceException &operator=(SQLiteSourceException &&) = default;
                ~SQLiteSourceException() = default;
            };
        }
    }
}
#endif //CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H
