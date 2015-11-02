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
                    std::string ConnectionString;
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
                static std::unique_ptr<SQLiteSourceDriver> Create(Foundation::SPtrEntityMap const &sptrEntityMap) {
                    return std::unique_ptr<SQLiteSourceDriver>(new SQLiteSourceDriver(sptrEntityMap));
                }

            private:
                class SQLiteApiImpl;
                using SPtrSQLiteApiImpl = std::shared_ptr<SQLiteApiImpl>;
                SPtrSQLiteApiImpl _sqliteApiImpl;

                Options _optionArgs;

                std::string _getStatement;
                std::string _insertStatement;
                std::string _updateStatement;
                std::string _deleteStatement;

            private:
                void Init();
            };

            using UPtrSQLiteSourceDriver = std::unique_ptr<SQLiteSourceDriver>;
            using SPtrSQLiteSourceDriver = std::shared_ptr<SQLiteSourceDriver>;
        }
    }
}


#endif //CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEDRIVER_H
