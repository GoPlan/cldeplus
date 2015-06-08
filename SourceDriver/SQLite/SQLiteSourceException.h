//
// Created by LE, Duc Anh on 6/7/15.
//

#ifndef CLOUD_E_CPLUS_SQLITESOURCEEXCEPTION_H
#define CLOUD_E_CPLUS_SQLITESOURCEEXCEPTION_H

namespace Cloude {
    namespace SourceDriver {
        namespace SQLite {
            class SQLiteSourceException {
            public:
                SQLiteSourceException() = default;
                virtual ~SQLiteSourceException() = default;
                SQLiteSourceException(const SQLiteSourceException &srcSQLiteSourceException) = default;
                SQLiteSourceException &operator=(const SQLiteSourceException &srcSQLiteSourceException) = default;

            };
        }
    }
}
#endif //CLOUD_E_CPLUS_SQLITESOURCEEXCEPTION_H
