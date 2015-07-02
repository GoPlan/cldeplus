//
// Created by LE, Duc Anh on 6/7/15.
//

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H

#include <Foundation/Exception/cldeException.h>

namespace Cloude {
    namespace Drivers {
        namespace SQLite {

            class SQLiteSourceException : public Foundation::Exception::cldeException {
                int _resultCode;

            public:
                explicit SQLiteSourceException(int resultCode);
                explicit SQLiteSourceException(int resultCode, const std::string &comment);
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
