//
// Created by LE, Duc Anh on 6/7/15.
//

#ifndef CLOUD_E_CPLUS_SQLITESOURCEDRIVER_H
#define CLOUD_E_CPLUS_SQLITESOURCEDRIVER_H

#include <memory>
#include <Framework/EntitySourceDriver.h>

namespace Cloude {
    namespace SourceDriver {
        namespace SQLite {
            class SQLiteSourceDriver : public Cloude::Framework::EntitySourceDriver {
            public:
                using DbType = Cloude::Framework::Enumeration::DbType;
                using Column = Cloude::Framework::Column;
                using ColumnsList = std::vector<std::shared_ptr<Column>>;
                using EntityMap = Cloude::Framework::EntityMap;
                using Entity = Cloude::Framework::Entity;
                using EntitySourceDriver = Cloude::Framework::EntitySourceDriver;
                using Options = struct {
                    std::string ConnectionString;
                };

            public:
                explicit SQLiteSourceDriver(EntityMap &entityMap);
                ~SQLiteSourceDriver();
                SQLiteSourceDriver(const SQLiteSourceDriver &srcSQLiteSourceDriver) = default;
                SQLiteSourceDriver &operator=(const SQLiteSourceDriver &srcSQLiteSourceDriver) = default;

                void Connect();
                void Disconnect();

                int LoadEntity(std::shared_ptr<Entity> &entity) const;
                int CreateEntity(std::shared_ptr<Entity> &entity) const;
                int SaveEntity(std::shared_ptr<Entity> &entity) const;
                int DeleteEntity(std::shared_ptr<Entity> &entity) const;

                Options &getOptionArgs() {
                    return _optionArgs;
                }

            private:
                class SQLiteApiImpl;

                std::shared_ptr<SQLiteApiImpl> _sqliteApiImpl;
                Options _optionArgs;
                std::string _getStatement;
                std::string _insertStatement;
                std::string _updateStatement;
                std::string _deleteStatement;

                void init();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_SQLITESOURCEDRIVER_H
