//
// Created by LE, Duc Anh on 6/7/15.
//

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H

#include <Foundation/Exception/CLDEException.h>

namespace Cloude {
    namespace Drivers {
        namespace SQLite {

            class SQLiteSourceException : public Foundation::Exception::CLDEException {

                int _resultCode;
                static const std::string _name;

            public:
                explicit SQLiteSourceException(int resultCode);
                explicit SQLiteSourceException(int resultCode, const std::string &comment);
                SQLiteSourceException(const SQLiteSourceException &) = default;
                SQLiteSourceException(SQLiteSourceException &&) = default;
                SQLiteSourceException &operator=(const SQLiteSourceException &) = default;
                SQLiteSourceException &operator=(SQLiteSourceException &&) = default;
                ~SQLiteSourceException() = default;

                // CLDEException
                virtual const std::string &Name() const noexcept override { return _name; };
            };
        }
    }
}
#endif //CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H
