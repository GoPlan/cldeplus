//
// Created by LE, Duc Anh on 6/7/15.
//

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEDRIVER_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEDRIVER_H

#include "cldeplus_default"
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
                explicit SQLiteSourceDriver(const Foundation::SPtrEntityMap &entityMap);
                SQLiteSourceDriver(const SQLiteSourceDriver &) = default;
                SQLiteSourceDriver(SQLiteSourceDriver &&) = default;
                SQLiteSourceDriver &operator=(const SQLiteSourceDriver &) = default;
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
                        const Foundation::Query::SPtrCriteria &sptrCriteria,
                        const Foundation::SPtrColumnVector &columnsForProjection) const override;

                // Factory methods
                static unique_ptr<SQLiteSourceDriver> Create(Foundation::SPtrEntityMap const &sptrEntityMap) {
                    return cldeplus_make_unique<SQLiteSourceDriver>(sptrEntityMap);
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
