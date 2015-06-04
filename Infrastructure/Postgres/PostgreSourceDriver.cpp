//
// Created by LE, Duc Anh on 5/27/15.
//

#include <memory>
#include <cstdlib>
#include <libpq-fe.h>
#include <Architecture/Helper/SqlGenerator.h>
#include "PostgreSourceDriver.h"

using namespace std;

namespace Cloude {
    namespace Infrastructure {

        class Command {

        public:
            Command(const PGconn &conn, const string &query) : PGConn(conn),
                                                               Query(query) {
                //
            };

            virtual ~Command() {

                if (PtrParamTypes != nullptr)
                    free(PtrParamTypes);

                if (PtrParamLengths != nullptr)
                    free(PtrParamLengths);

                if (PtrParamFormats != nullptr)
                    free(PtrParamFormats);

                if (PtrParamValues != nullptr) {

                    for (int i = 0; i < nParam; ++i) {
                        free(PtrParamValues[i]);
                    }

                    free(PtrParamValues);
                }
            };

            int nParam = 0;
            int ResultFormat = 0;

            Oid *PtrParamTypes = 0;
            int *PtrParamFormats = 0;

            int *PtrParamLengths = nullptr;
            char **PtrParamValues = nullptr;

            const PGconn &PGConn;
            const string &Query;
        };

        class PostgreSourceDriver::PqApiImpl {

        public:
            PGconn *PtrPgConn;

        public:
            shared_ptr<Command> createCommand(const string &query) {
                shared_ptr<Command> command = make_shared<Command>(*PtrPgConn, query);
                return command;
            }

            void bindParamsBuffer(shared_ptr<Entity> &entity,
                                  const ColumnsList &columnsList,
                                  shared_ptr<Command> &command) {

                auto nParam = columnsList.size();

                command->nParam = (int) columnsList.size();
                command->PtrParamLengths = (int *) calloc(nParam, sizeof(int));
                command->PtrParamValues = (char **) calloc(nParam, sizeof(char *));

                for_each(columnsList.cbegin(), columnsList.cend(),
                         [&entity, &command](const shared_ptr<Column> &column) {


                         });
            }

            string getTypeName(Architecture::Enumeration::DbType dbType) {

                string type;

                switch (dbType) {
                    case Architecture::Enumeration::DbType::Boolean:
                        type = "boolean";
                        break;
                    case Architecture::Enumeration::DbType::Byte:
                        type = "bytea";
                        break;
                    case Architecture::Enumeration::DbType::Int16:
                        type = "smallint";
                        break;
                    case Architecture::Enumeration::DbType::Int32:
                        type = "integer";
                        break;
                    case Architecture::Enumeration::DbType::Int64:
                        type = "bigint";
                        break;
                    case Architecture::Enumeration::DbType::UInt16:
                        type = "smallint";
                        break;
                    case Architecture::Enumeration::DbType::UInt32:
                        type = "integer";
                        break;
                    case Architecture::Enumeration::DbType::UInt64:
                        type = "bigint";
                        break;
                    case Architecture::Enumeration::DbType::Double:
                        type = "double";
                        break;
                    case Architecture::Enumeration::DbType::Float:
                        type = "real";
                        break;
                    case Architecture::Enumeration::DbType::Decimal:
                        type = "decimal";
                        break;
                    case Architecture::Enumeration::DbType::Numeric:
                        type = "numeric";
                        break;
                    case Architecture::Enumeration::DbType::String:
                        type = "varchar";
                        break;
                    case Architecture::Enumeration::DbType::Currency:
                        type = "money";
                        break;
                    case Architecture::Enumeration::DbType::Date:
                        type = "date";
                        break;
                    case Architecture::Enumeration::DbType::Time:
                        type = "time";
                        break;
                    case Architecture::Enumeration::DbType::Timestamp:
                        type = "timestamp";
                        break;
                    case Architecture::Enumeration::DbType::Interval:
                        type = "interval";
                        break;
                }

                return type;
            }
        };

        PostgreSourceDriver::PostgreSourceDriver(EntityMap &entityMap) : EntitySourceDriver(entityMap),
                                                                         _pqApiImpl(new PqApiImpl()) {
            init();
        }

        PostgreSourceDriver::~PostgreSourceDriver() {

        }

        void PostgreSourceDriver::init() {

            auto F = [this](const std::shared_ptr<Column> &column,
                            const int index) -> string {

                auto typeName = _pqApiImpl->getTypeName(column->getDbType());
                auto expr = "$" + std::to_string(index) + "::" + typeName;

                return expr;
            };

            _getStatement = Architecture::Helper::CreateGetPreparedQuery(_entityMap, F);
            _insertStatement = Architecture::Helper::CreateInsertPreparedQuery(_entityMap, F);
            _updateStatement = Architecture::Helper::CreateUpdatePreparedQuery(_entityMap, F);
            _deleteStatement = Architecture::Helper::CreateDeletePreparedQuery(_entityMap, F);
        }

        int PostgreSourceDriver::LoadEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const {

            ColumnsList columnList;

            shared_ptr<Command> command = _pqApiImpl->createCommand(_getStatement);

            _pqApiImpl->bindParamsBuffer(entity, columnList, command);

            const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

            PQexecParams(_pqApiImpl->PtrPgConn,
                         command->Query.c_str(),
                         command->nParam,
                         command->PtrParamTypes,
                         ptrParamValues,
                         command->PtrParamLengths,
                         command->PtrParamFormats,
                         command->ResultFormat);

            // TODO: Verify result status

            return 1;
        }

        int PostgreSourceDriver::CreateEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const {

            ColumnsList columnList;

            shared_ptr<Command> command = _pqApiImpl->createCommand(_insertStatement);

            _pqApiImpl->bindParamsBuffer(entity, columnList, command);

            const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

            PQexecParams(_pqApiImpl->PtrPgConn,
                         command->Query.c_str(),
                         command->nParam,
                         command->PtrParamTypes,
                         ptrParamValues,
                         command->PtrParamLengths,
                         command->PtrParamFormats, 0);

            // TODO: Verify result status

            return 1;
        }

        int PostgreSourceDriver::SaveEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const {

            ColumnsList columnList;

            shared_ptr<Command> command = _pqApiImpl->createCommand(_updateStatement);

            _pqApiImpl->bindParamsBuffer(entity, columnList, command);

            const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

            PQexecParams(_pqApiImpl->PtrPgConn,
                         command->Query.c_str(),
                         command->nParam,
                         command->PtrParamTypes,
                         ptrParamValues,
                         command->PtrParamLengths,
                         command->PtrParamFormats, 0);

            // TODO: Verify result status

            return 1;
        }

        int PostgreSourceDriver::DeleteEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const {

            ColumnsList columnList;

            shared_ptr<Command> command = _pqApiImpl->createCommand(_deleteStatement);

            _pqApiImpl->bindParamsBuffer(entity, columnList, command);

            const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

            PQexecParams(_pqApiImpl->PtrPgConn,
                         command->Query.c_str(),
                         command->nParam,
                         command->PtrParamTypes,
                         ptrParamValues,
                         command->PtrParamLengths,
                         command->PtrParamFormats, 0);

            // TODO: Verify result status

            return 1;
        }

        void PostgreSourceDriver::Connect() {

            if (_pqApiImpl->PtrPgConn == nullptr) {

                _pqApiImpl->PtrPgConn = PQsetdbLogin(OptionArgs.Host.c_str(),
                                                     std::to_string(OptionArgs.Port).c_str(),
                                                     NULL,
                                                     NULL,
                                                     OptionArgs.Base.c_str(),
                                                     OptionArgs.User.c_str(),
                                                     OptionArgs.Pass.c_str());
                _isConnected = true;
            }
        }

        void PostgreSourceDriver::Disconnect() {

            if (_pqApiImpl->PtrPgConn != nullptr) {

                PQfinish(_pqApiImpl->PtrPgConn);
                _isConnected = false;
            }
        }
    }
}

