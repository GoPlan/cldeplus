//
// Created by LE, Duc Anh on 5/27/15.
//

#include <memory>
#include <cstdlib>
#include <libpq-fe.h>
#include <Architecture/Helper/SqlGenerator.h>
#include <iostream>
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

                if (PtrParamTypes != nullptr && PtrParamTypes != NULL)
                    free(PtrParamTypes);

                if (PtrParamFormats != nullptr && PtrParamFormats != NULL)
                    free(PtrParamFormats);

                if (PtrParamLengths != nullptr && PtrParamLengths != NULL)
                    free(PtrParamLengths);

                if (PtrParamValues != nullptr && PtrParamValues != NULL) {
                    // Elementary value(buffer) pointer is freed by Entity.
                    // Therefore, we only need to free param values array.
                    free(PtrParamValues);
                }
            };

            int nParam = 0;
            int ResultFormat = 0;

            Oid *PtrParamTypes = NULL;      // Set entry pointer to 0 (NULL) for using text format
            int *PtrParamFormats = NULL;    // Set entry pointer to 0 (NULL) for using text format

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

            void initializeParamsBindBuffer(shared_ptr<Entity> &entity,
                                            const ColumnsList &columnsList,
                                            shared_ptr<Command> &command) {

                auto nParam = columnsList.size();

                command->nParam = (int) columnsList.size();
                command->PtrParamLengths = (int *) calloc(nParam, sizeof(int));
                command->PtrParamValues = (char **) calloc(nParam, sizeof(char *));

                int index = 0;

                for_each(columnsList.cbegin(), columnsList.cend(),
                         [&entity, &command, &index](const shared_ptr<Column> &column) {

                             auto field = entity->operator[](column->getName());

                             command->PtrParamLengths[index] = static_cast<int>(column->getLength());
                             command->PtrParamValues[index] = reinterpret_cast<char *>(field->PointerToFieldValue());

                             index++;
                         });
            }

            string getTypeAlias(Architecture::Enumeration::DbType dbType) {

                switch (dbType) {
                    case Architecture::Enumeration::DbType::Boolean:
                        return "boolean";
                    case Architecture::Enumeration::DbType::Byte:
                        return "bytea";
                    case Architecture::Enumeration::DbType::Int16:
                        return "smallint";
                    case Architecture::Enumeration::DbType::Int32:
                        return "integer";
                    case Architecture::Enumeration::DbType::Int64:
                        return "bigint";
                    case Architecture::Enumeration::DbType::UInt16:
                        return "smallint";
                    case Architecture::Enumeration::DbType::UInt32:
                        return "integer";
                    case Architecture::Enumeration::DbType::UInt64:
                        return "bigint";
                    case Architecture::Enumeration::DbType::Double:
                        return "double";
                    case Architecture::Enumeration::DbType::Float:
                        return "real";
                    case Architecture::Enumeration::DbType::Decimal:
                        return "decimal";
                    case Architecture::Enumeration::DbType::Numeric:
                        return "numeric";
                    case Architecture::Enumeration::DbType::String:
                        return "varchar";
                    case Architecture::Enumeration::DbType::Currency:
                        return "money";
                    case Architecture::Enumeration::DbType::Date:
                        return "date";
                    case Architecture::Enumeration::DbType::Time:
                        return "time";
                    case Architecture::Enumeration::DbType::Timestamp:
                        return "timestamp";
                    case Architecture::Enumeration::DbType::Interval:
                        return "interval";
                }
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
                            int index) -> string {

                auto typeName = _pqApiImpl->getTypeAlias(column->getDbType());
                auto expr = "$" + std::to_string(++index) + "::" + typeName;

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

            _pqApiImpl->initializeParamsBindBuffer(entity, columnList, command);

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

            auto command = _pqApiImpl->createCommand(_insertStatement);

            _pqApiImpl->initializeParamsBindBuffer(entity, entityMap.getColumnsForKey(), command);

            const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

            PGresult *result = PQexecParams(_pqApiImpl->PtrPgConn,
                                            command->Query.c_str(),
                                            command->nParam,
                                            command->PtrParamTypes,
                                            ptrParamValues,
                                            command->PtrParamLengths,
                                            command->PtrParamFormats,
                                            0);

            // TODO: Verify result status
            ExecStatusType statusType = PQresultStatus(result);
            char *errorMessage = nullptr;


            switch (statusType) {
                case PGRES_EMPTY_QUERY:
                    break;
                case PGRES_COMMAND_OK:
                    break;
                case PGRES_TUPLES_OK:
                    break;
                case PGRES_COPY_OUT:
                    break;
                case PGRES_COPY_IN:
                    break;
                case PGRES_BAD_RESPONSE:
                    errorMessage = PQresultErrorMessage(result);
                    cout << errorMessage << endl;
                    break;
                case PGRES_NONFATAL_ERROR:
                    errorMessage = PQresultErrorMessage(result);
                    cout << errorMessage << endl;
                    break;
                case PGRES_FATAL_ERROR:
                    errorMessage = PQresultErrorMessage(result);
                    cout << errorMessage << endl;
                    break;
                case PGRES_COPY_BOTH:
                    break;
                case PGRES_SINGLE_TUPLE:
                    break;
            }

            PQclear(result);

            return 1;
        }

        int PostgreSourceDriver::SaveEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const {

            ColumnsList columnList;

            shared_ptr<Command> command = _pqApiImpl->createCommand(_updateStatement);

            _pqApiImpl->initializeParamsBindBuffer(entity, columnList, command);

            const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

            PGresult *result = PQexecParams(_pqApiImpl->PtrPgConn,
                                            command->Query.c_str(),
                                            command->nParam,
                                            command->PtrParamTypes,
                                            ptrParamValues,
                                            command->PtrParamLengths,
                                            command->PtrParamFormats, 0);

            ExecStatusType statusType = PQresultStatus(result);

            switch (statusType) {
                case PGRES_EMPTY_QUERY:
                    break;
                case PGRES_COMMAND_OK:
                    break;
                case PGRES_TUPLES_OK:
                    break;
                case PGRES_COPY_OUT:
                    break;
                case PGRES_COPY_IN:
                    break;
                case PGRES_BAD_RESPONSE:
                    break;
                case PGRES_NONFATAL_ERROR:
                    break;
                case PGRES_FATAL_ERROR:
                    break;
                case PGRES_COPY_BOTH:
                    break;
                case PGRES_SINGLE_TUPLE:
                    break;
            }

            // TODO: Verify result status
//            PQclear(result);

            return 1;
        }

        int PostgreSourceDriver::DeleteEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const {

            ColumnsList columnList;

            shared_ptr<Command> command = _pqApiImpl->createCommand(_deleteStatement);

            _pqApiImpl->initializeParamsBindBuffer(entity, columnList, command);

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

