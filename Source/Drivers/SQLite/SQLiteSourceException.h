//
// Created by LE, Duc Anh on 6/7/15.
//

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H

#include "../../Foundation/Exception/CLDEException.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace SQLite {

            class SQLiteSourceException : public Foundation::Exception::CLDEException {

                int _resultCode;
                static const string _name;

            public:
                explicit SQLiteSourceException(int resultCode);
                explicit SQLiteSourceException(int resultCode, string const &comment);
                SQLiteSourceException(SQLiteSourceException const &) = default;
                SQLiteSourceException(SQLiteSourceException &&) = default;
                SQLiteSourceException &operator=(SQLiteSourceException const &) = default;
                SQLiteSourceException &operator=(SQLiteSourceException &&) = default;
                ~SQLiteSourceException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override { return _name; };
            };
        }
    }
}
#endif //CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H
