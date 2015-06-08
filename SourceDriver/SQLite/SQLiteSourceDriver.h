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
            class SQLiteSourceDriver : Framework::EntitySourceDriver {
            public:
                using EntityMap = Framework::EntityMap;
                using Entity = Framework::Entity;
                using EntitySourceDriver = Framework::EntitySourceDriver;
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

            private:
                class SQLiteImpl;

                std::shared_ptr<SQLiteImpl> _sqliteImpl;
                Options _optionArgs;
                std::string _getStatement;
                std::string _insertStatement;
                std::string _updateStatement;
                std::string _deleteStatement;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_SQLITESOURCEDRIVER_H
