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

            class SQLiteSourceDriver
                    : public Foundation::EntitySourceDriver,
                      public Foundation::Query::Contract::IPredicateFormatter {

            public:
                using Options = struct {
                    std::string ConnectionString;
                };

            public:
                explicit SQLiteSourceDriver(const Foundation::EntityMap &entityMap);
                ~SQLiteSourceDriver();
                SQLiteSourceDriver(const SQLiteSourceDriver &srcSQLiteSourceDriver) = default;
                SQLiteSourceDriver &operator=(const SQLiteSourceDriver &srcSQLiteSourceDriver) = default;

                // Locals
                void Connect();
                void Disconnect();
                Options &getOptionArgs() { return _optionArgs; }

                // EntitySourceDriver
                int Load(std::shared_ptr<Foundation::Entity> &entity) const override;
                int Insert(std::shared_ptr<Foundation::Entity> &entity) const override;
                int Save(std::shared_ptr<Foundation::Entity> &entity) const override;
                int Delete(std::shared_ptr<Foundation::Entity> &entity) const override;
                SPtrProxySPtrVector Select(const SPtrPredicate &predicate,
                                           Foundation::EntityStore &entityStore) const override;

                // IPredicationFormatterPredication
                std::string ParsePredicateToStringCopy(const SPtrPredicate &predicate) const override;

            private:
                class SQLiteApiImpl;

                std::shared_ptr<SQLiteApiImpl> _sqliteApiImpl;

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
