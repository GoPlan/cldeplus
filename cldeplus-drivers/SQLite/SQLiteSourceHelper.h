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

#ifndef CLDEPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEHELPER_H
#define CLDEPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEHELPER_H

#include "../../Portable/CommonTypes.h"
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
