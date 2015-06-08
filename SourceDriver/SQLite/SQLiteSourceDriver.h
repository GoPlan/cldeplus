//
// Created by LE, Duc Anh on 6/7/15.
//

#ifndef CLOUD_E_CPLUS_SQLITESOURCEDRIVER_H
#define CLOUD_E_CPLUS_SQLITESOURCEDRIVER_H

namespace Cloude {
    namespace SourceDriver {
        namespace SQLite {
            class SQLiteSourceDriver {
            public:
                SQLiteSourceDriver() = default;
                virtual ~SQLiteSourceDriver() = default;
                SQLiteSourceDriver(const SQLiteSourceDriver &srcSQLiteSourceDriver) = default;
                SQLiteSourceDriver &operator=(const SQLiteSourceDriver &srcSQLiteSourceDriver) = default;

            };
        }
    }
}



#endif //CLOUD_E_CPLUS_SQLITESOURCEDRIVER_H
