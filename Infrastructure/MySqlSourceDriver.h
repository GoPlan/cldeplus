//
// Created by GoPlan on 18/05/2015.
//

#ifndef CLOUD_E_CPLUS_MYSQLSOUCRCEDRIVER_H
#define CLOUD_E_CPLUS_MYSQLSOUCRCEDRIVER_H

#include <vector>
#include <Architecture/EntitySourceDriver.h>

namespace Cloude {
    namespace Infrastructure {

        using Entity = Cloude::Architecture::Entity;
        using Column = Cloude::Architecture::Column;
        using Field = Cloude::Architecture::Field;
        using EntitySourceDriver = Cloude::Architecture::EntitySourceDriver;
        using EntityMap = Cloude::Architecture::EntityMap;
        using ColumnsList = std::vector<std::shared_ptr<Column>>;

        using MySqlDriverOptions = struct {

            std::string Host;
            std::string User;
            std::string Pass;
            std::string Base;

            unsigned int Port = 3306;
        };

        class MySqlSourceDriver : public EntitySourceDriver {
        public:
            MySqlDriverOptions OptionArgs;

        public:
            MySqlSourceDriver();
            ~MySqlSourceDriver();

            void Connect();
            void Disconnect();

            void LoadEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) override;
            void CreateEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) override;
            virtual void SaveEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) override;
            virtual void DeleteEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) override;

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

        private:
            class implMySqlApi;
            implMySqlApi *_ptrMySqlApiImpl;

            std::string _getStatement;
            std::string _insertStatement;
            std::string _updateStatement;
            std::string _deleteStatement;
        };
    }
}


#endif //CLOUD_E_CPLUS_MYSQLSOUCRCEDRIVER_H
