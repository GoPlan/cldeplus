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

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEEXCEPTION_H

#include "cldeException.h"

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
