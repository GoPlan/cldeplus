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

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEDRIVER_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEDRIVER_H

#include "../../Portable/CommonTypes.h"
#include "../../Foundation/EntitySourceDriver.h"
#include "../../Foundation/Query/Contract/IPredicateFormatter.h"
#include "SQLiteSourceException.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace SQLite {

            class SQLiteSourceDriver : public Foundation::EntitySourceDriver {

            public:
                using Options = struct {
                    string ConnectionString;
                };

            public:
                explicit SQLiteSourceDriver(Foundation::SPtrEntityMap const &entityMap);
                SQLiteSourceDriver(SQLiteSourceDriver const &) = default;
                SQLiteSourceDriver(SQLiteSourceDriver &&) = default;
                SQLiteSourceDriver &operator=(SQLiteSourceDriver const &) = default;
                SQLiteSourceDriver &operator=(SQLiteSourceDriver &&) = default;
                ~SQLiteSourceDriver();

                // Locals
                void Connect();
                void Disconnect();
                Options &OptionArgs() { return _optionArgs; }

                // EntitySourceDriver
                int Load(Foundation::SPtrEntity &entity) const override;
                int Insert(Foundation::SPtrEntity &entity) const override;
                int Save(Foundation::SPtrEntity &entity) const override;
                int Delete(Foundation::SPtrEntity &entity) const override;

                Foundation::SPtrEntityProxyVector Select(
                        Foundation::Query::SPtrCriteria const &sptrCriteria,
                        Foundation::SPtrColumnVector const &columnsForProjection) const override;

                // Factory methods
                static unique_ptr<SQLiteSourceDriver> CreateUnique(Foundation::SPtrEntityMap const &sptrEntityMap) {
                    return cldeplus_make_unique<SQLiteSourceDriver>(sptrEntityMap);
                }
                static shared_ptr<SQLiteSourceDriver> CreateShared(Foundation::SPtrEntityMap const &sptrEntityMap) {
                    return cldeplus_make_shared<SQLiteSourceDriver>(sptrEntityMap);
                }


            private:
                class SQLiteApiImpl;
                using SPtrSQLiteApiImpl = shared_ptr<SQLiteApiImpl>;
                SPtrSQLiteApiImpl _sqliteApiImpl;

                Options _optionArgs;

                string _getStatement;
                string _insertStatement;
                string _updateStatement;
                string _deleteStatement;

            private:
                void Init();
            };

            using UPtrSQLiteSourceDriver = unique_ptr<SQLiteSourceDriver>;
            using SPtrSQLiteSourceDriver = shared_ptr<SQLiteSourceDriver>;
        }
    }
}


#endif //CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEDRIVER_H
