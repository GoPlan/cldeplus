//
// Created by GoPlan on 18/05/2015.
//

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_MYSQL_MYSQLSOUCRCEDRIVER_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_MYSQL_MYSQLSOUCRCEDRIVER_H

#include <memory>
#include <vector>
#include <Foundation/EntitySourceDriver.h>
#include "MySqlSourceException.h"

namespace Cloude {
    namespace SourceDriver {
        namespace MySql {

            enum class MySqlSourceExecutionStatus {

            };

            class MySqlSourceDriver : public Foundation::EntitySourceDriver {
            public:
                using Predicate = Foundation::Query::Predicate;
                using Entity = Foundation::Entity;
                using Column = Foundation::Column;
                using Field = Foundation::Field;
                using EntitySourceDriver = Cloude::Foundation::EntitySourceDriver;
                using EntityMap = Foundation::EntityMap;
                using ColumnsList = std::vector<std::shared_ptr<Column>>;
                using Options = struct {
                    std::string Host;
                    std::string User;
                    std::string Pass;
                    std::string Base;
                    unsigned int Port = 3306;
                };

            public:
                explicit MySqlSourceDriver(EntityMap &entityMap);
                ~MySqlSourceDriver();
                MySqlSourceDriver(const MySqlSourceDriver &entityMap) = default;
                MySqlSourceDriver &operator=(const MySqlSourceDriver &entityMap) = default;

                void Connect();
                void Disconnect();

                int Load(std::shared_ptr<Entity> &entity) const override;
                int Insert(std::shared_ptr<Entity> &entity) const override;
                int Save(std::shared_ptr<Entity> &entity) const override;
                int Delete(std::shared_ptr<Entity> &entity) const override;

                std::vector<Foundation::EntityProxy> Select(std::shared_ptr<Predicate> &expr) const override;

                Options &getOptionArgs() { return _optionArgs; }

            private:
                class MySqlApiImpl;

                Options _optionArgs;
                std::shared_ptr<MySqlApiImpl> _mySqlApiImpl;
                std::string _getStatement;
                std::string _insertStatement;
                std::string _updateStatement;
                std::string _deleteStatement;
                bool isConnected = false;

            private:
                void init();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_SOURCEDRIVER_MYSQL_MYSQLSOUCRCEDRIVER_H
