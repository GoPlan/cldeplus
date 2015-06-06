//
// Created by GoPlan on 18/05/2015.
//

#ifndef CLOUD_E_CPLUS_MYSQLSOUCRCEDRIVER_H
#define CLOUD_E_CPLUS_MYSQLSOUCRCEDRIVER_H

#include <vector>
#include <Architecture/EntitySourceDriver.h>
#include <Architecture/Field.h>

namespace Cloude {
    namespace Infrastructure {
        namespace MySql {

            enum class MySqlSourceExecutionStatus {

            };

            class MySqlSourceDriver : public Architecture::EntitySourceDriver {
            public:
                using Entity = Cloude::Architecture::Entity;
                using Column = Cloude::Architecture::Column;
                using Field = Cloude::Architecture::Field;
                using EntitySourceDriver = Cloude::Architecture::EntitySourceDriver;
                using EntityMap = Cloude::Architecture::EntityMap;
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

                int LoadEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const override;
                int CreateEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const override;
                int SaveEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const override;
                int DeleteEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const override;

                void setGetStatement(const std::string &getStatement) {
                    _getStatement = getStatement;
                }

                void setInsertStatement(const std::string &insertStatement) {
                    _insertStatement = insertStatement;
                }

                void setUpdateStatement(const std::string &updateStatement) {
                    _updateStatement = updateStatement;
                }

                void setDeleteStatement(const std::string &deleteStatement) {
                    _deleteStatement = deleteStatement;
                }

                Options &getOptionArgs() {
                    return _optionArgs;
                }

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


#endif //CLOUD_E_CPLUS_MYSQLSOUCRCEDRIVER_H
