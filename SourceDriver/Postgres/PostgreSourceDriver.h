//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_POSTGRESOURCEDRIVER_H
#define CLOUD_E_CPLUS_POSTGRESOURCEDRIVER_H

#include <memory>
#include <vector>
#include <string>
#include <Foundation/EntitySourceDriver.h>
#include "PostgreSourceException.h"

namespace Cloude {
    namespace SourceDriver {
        namespace PostgreSql {

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

            class PostgreSourceDriver : public Foundation::EntitySourceDriver {
            public:
                using Predicate = Foundation::Query::Predication;
                using Options = struct {
                    std::string Host;
                    std::string User;
                    std::string Pass;
                    std::string Base;
                    unsigned int Port = 5432;
                };

            public:
                explicit PostgreSourceDriver(Foundation::EntityMap &entityMap);
                ~PostgreSourceDriver();
                PostgreSourceDriver(const PostgreSourceDriver &srcPostgreSqlDriver) = default;
                PostgreSourceDriver &operator=(const PostgreSourceDriver &srcPostgreSqlDriver) = default;

                void Connect();
                void Disconnect();

                int Load(std::shared_ptr<Foundation::Entity> &entity) const override;
                int Insert(std::shared_ptr<Foundation::Entity> &entity) const override;
                int Save(std::shared_ptr<Foundation::Entity> &entity) const override;
                int Delete(std::shared_ptr<Foundation::Entity> &entity) const override;

                std::vector<Foundation::EntityProxy> Select(std::shared_ptr<Predicate> &expr) const override;

                Options &getOptionArgs() {
                    return _optionArgs;
                }

            private:
                class PgApiImpl;

                std::shared_ptr<PgApiImpl> _pgApiImpl;
                Options _optionArgs;
                std::string _getStatement;
                std::string _insertStatement;
                std::string _updateStatement;
                std::string _deleteStatement;
                bool _isConnected = false;

            private:
                void init();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_POSTGRESOURCEDRIVER_H
