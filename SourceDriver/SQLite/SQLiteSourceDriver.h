//
// Created by LE, Duc Anh on 6/7/15.
//

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEDRIVER_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEDRIVER_H

#include <memory>
#include <Foundation/EntitySourceDriver.h>
#include <Foundation/Query/Contract/IPredicateFormatter.h>
#include "SQLiteSourceException.h"

namespace Cloude {
    namespace SourceDriver {
        namespace SQLite {

            class SQLiteSourceDriver : public Foundation::EntitySourceDriver {

            public:
                using Options = struct {
                    std::string ConnectionString;
                };

            public:
                explicit SQLiteSourceDriver(const Foundation::EntityMap &entityMap);
                SQLiteSourceDriver(const SQLiteSourceDriver &) = default;
                SQLiteSourceDriver(SQLiteSourceDriver &&) = default;
                SQLiteSourceDriver &operator=(const SQLiteSourceDriver &) = default;
                SQLiteSourceDriver &operator=(SQLiteSourceDriver &&) = default;
                ~SQLiteSourceDriver();

                // Locals
                void Connect();
                void Disconnect();
                Options &getOptionArgs() { return _optionArgs; }

                // EntitySourceDriver
                int Load(Foundation::SPtrEntity &entity) const override;
                int Insert(Foundation::SPtrEntity &entity) const override;
                int Save(Foundation::SPtrEntity &entity) const override;
                int Delete(Foundation::SPtrEntity &entity) const override;

                Foundation::SPtrEntityProxyVector
                        Select(const Foundation::Query::SPtrCriteria &sptrCriteria,
                               Foundation::EntityStore &entityStore) const override;

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
        }
    }
}


#endif //CLOUD_E_CPLUS_SOURCEDRIVER_SQLITE_SQLITESOURCEDRIVER_H
