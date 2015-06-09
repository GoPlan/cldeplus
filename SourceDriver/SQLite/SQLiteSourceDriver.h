//
// Created by LE, Duc Anh on 6/7/15.
//

#ifndef CLOUD_E_CPLUS_SQLITESOURCEDRIVER_H
#define CLOUD_E_CPLUS_SQLITESOURCEDRIVER_H

#include <memory>
#include <Foundation/EntitySourceDriver.h>
#include "SQLiteSourceException.h"

namespace Cloude {
    namespace SourceDriver {
        namespace SQLite {

            class SQLiteSourceDriver : public Foundation::EntitySourceDriver {
            public:
                using QueryExpression = Foundation::Query::Expression;
                using Options = struct {
                    std::string ConnectionString;
                };

            public:
                explicit SQLiteSourceDriver(Foundation::EntityMap &entityMap);
                ~SQLiteSourceDriver();
                SQLiteSourceDriver(const SQLiteSourceDriver &srcSQLiteSourceDriver) = default;
                SQLiteSourceDriver &operator=(const SQLiteSourceDriver &srcSQLiteSourceDriver) = default;

                void Connect();
                void Disconnect();

                int Load(std::shared_ptr<Foundation::Entity> &entity) const;
                int Insert(std::shared_ptr<Foundation::Entity> &entity) const;
                int Save(std::shared_ptr<Foundation::Entity> &entity) const;
                int Delete(std::shared_ptr<Foundation::Entity> &entity) const;

                std::vector<Foundation::EntityProxy> Select(std::shared_ptr<QueryExpression> &expr) const override;

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
