//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_POSTGRESOURCEDRIVER_H
#define CLOUD_E_CPLUS_POSTGRESOURCEDRIVER_H

#include <Architecture/EntitySourceDriver.h>

namespace Cloude {
    namespace Infrastructure {

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

            unsigned int Port = 5432;
        };

        class PostgreSourceDriver : public Architecture::EntitySourceDriver {
        public:
            Options OptionArgs;

        public:
            PostgreSourceDriver(const PostgreSourceDriver &srcPostgreSqlDriver) = default;
            PostgreSourceDriver &operator=(const PostgreSourceDriver &srcPostgreSqlDriver) = default;

            explicit PostgreSourceDriver(EntityMap& entityMap);
            ~PostgreSourceDriver();

            void Connect();
            void Disconnect();

            void LoadEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) override;
            void CreateEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) override;
            void SaveEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) override;
            void DeleteEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) override;

        private:
            class PqApiImpl;

            PqApiImpl *_pqApiImpl;

            std::string _getStatement;
            std::string _insertStatement;
            std::string _updateStatement;
            std::string _deleteStatement;

            bool _isConnected = false;

            void init();
        };
    }
}


#endif //CLOUD_E_CPLUS_POSTGRESOURCEDRIVER_H
