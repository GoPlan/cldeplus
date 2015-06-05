//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_POSTGRESOURCEDRIVER_H
#define CLOUD_E_CPLUS_POSTGRESOURCEDRIVER_H

#include <Architecture/EntitySourceDriver.h>
#include <Architecture/Column.h>
#include <Architecture/Field.h>
#include <vector>

namespace Cloude {
    namespace Infrastructure {
        namespace PostgreSql {

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

            enum class PostgreSourceExecutionStatus {
                PGRES_EMPTY_QUERY,
                PGRES_COMMAND_OKAY,
                PGRES_TUPLE_OKAY,
                PGRES_COPY_OUT,
                PGRES_COPY_IN,
                PGRES_BAD_RESPONSE,
                PGRES_NONFATAL_ERROR,
                PGRES_FATAL_ERROR,
                PGRES_COPY_BOTH,
                PGRES_SINGLE_TUPLE
            };

            class PostgreSourceDriver : public Architecture::EntitySourceDriver {
            public:
                Options OptionArgs;

            public:
                PostgreSourceDriver(const PostgreSourceDriver &srcPostgreSqlDriver) = default;
                PostgreSourceDriver &operator=(const PostgreSourceDriver &srcPostgreSqlDriver) = default;

                explicit PostgreSourceDriver(EntityMap &entityMap);
                ~PostgreSourceDriver();

                void Connect();
                void Disconnect();

                int LoadEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const override;
                int CreateEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const override;
                int SaveEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const override;
                int DeleteEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const override;

            private:
                class PgApiImpl;

                std::shared_ptr<PgApiImpl> _pgApiImpl;

                std::string _getStatement;
                std::string _insertStatement;
                std::string _updateStatement;
                std::string _deleteStatement;

                bool _isConnected = false;

                void init();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_POSTGRESOURCEDRIVER_H
