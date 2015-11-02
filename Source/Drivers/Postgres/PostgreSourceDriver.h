//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_POSTGRES_POSTGRESOURCEDRIVER_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_POSTGRES_POSTGRESOURCEDRIVER_H

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
                using Options = struct {
                    string Host;
                    string User;
                    string Pass;
                    string Base;
                    unsigned int Port = 5432;
                };

            public:
                explicit PostgreSourceDriver(const Foundation::EntityMap &entityMap);
                ~PostgreSourceDriver();
                PostgreSourceDriver(const PostgreSourceDriver &srcPostgreSqlDriver) = default;
                PostgreSourceDriver &operator=(const PostgreSourceDriver &srcPostgreSqlDriver) = default;

                // Locals
                void Connect();
                void Disconnect();
                Options &getOptionArgs() { return _optionArgs; }

                // EntitySourceDriver
                int Load(shared_ptr<Foundation::Entity> &entity) const override;
                int Insert(shared_ptr<Foundation::Entity> &entity) const override;
                int Save(shared_ptr<Foundation::Entity> &entity) const override;
                int Delete(shared_ptr<Foundation::Entity> &entity) const override;
                SPtrProxySPtrVector Select(const SPtrPredicate &predicate,
                                           Foundation::EntityStore &entityStore) const override;
            private:
                class PgApiImpl;

                shared_ptr<PgApiImpl> _pgApiImpl;
                Options _optionArgs;
                string _getStatement;
                string _insertStatement;
                string _updateStatement;
                string _deleteStatement;
                bool _isConnected = false;

            private:
                void Init();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_SOURCEDRIVER_POSTGRES_POSTGRESOURCEDRIVER_H
