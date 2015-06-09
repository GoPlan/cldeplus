//
// Created by LE, Duc Anh on 5/27/15.
//

#include <memory>
#include <cstdlib>
#include <iostream>
#include <libpq-fe.h>
#include <Foundation/Helper/SqlGenerator.h>
#include "PostgreSourceDriver.h"

using namespace std;

namespace Cloude {
    namespace SourceDriver {
        namespace PostgreSql {

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

            class PostgreSourceDriver::PgApiImpl {
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
                                 command->PtrParamValues[index] =
                                         reinterpret_cast<char *>(field->PointerToFieldValue());

                                 index++;
                             });
                }

                string getTypeAlias(Foundation::Enumeration::DbType dbType) {

                    switch (dbType) {
                        case Foundation::Enumeration::DbType::Boolean:
                            return "boolean";
                        case Foundation::Enumeration::DbType::Byte:
                            return "bytea";
                        case Foundation::Enumeration::DbType::Int16:
                            return "smallint";
                        case Foundation::Enumeration::DbType::Int32:
                            return "integer";
                        case Foundation::Enumeration::DbType::Int64:
                            return "bigint";
                        case Foundation::Enumeration::DbType::UInt16:
                            return "smallint";
                        case Foundation::Enumeration::DbType::UInt32:
                            return "integer";
                        case Foundation::Enumeration::DbType::UInt64:
                            return "bigint";
                        case Foundation::Enumeration::DbType::Double:
                            return "double";
                        case Foundation::Enumeration::DbType::Float:
                            return "real";
                        case Foundation::Enumeration::DbType::Decimal:
                            return "decimal";
                        case Foundation::Enumeration::DbType::Numeric:
                            return "numeric";
                        case Foundation::Enumeration::DbType::String:
                            return "varchar";
                        case Foundation::Enumeration::DbType::Currency:
                            return "money";
                        case Foundation::Enumeration::DbType::Date:
                            return "date";
                        case Foundation::Enumeration::DbType::Time:
                            return "time";
                        case Foundation::Enumeration::DbType::Timestamp:
                            return "timestamp";
                        case Foundation::Enumeration::DbType::Interval:
                            return "interval";
                    }
                }


                void retrieveResult(const EntityMap &entityMap,
                                    const PGresult *ptrResult,
                                    std::shared_ptr<Entity> &entity) {

                    auto columnsForGet = entityMap.getColumnsForGet();

                    int index = 0;

                    std::for_each(columnsForGet.cbegin(), columnsForGet.cend(),
                                  [&entity, &ptrResult, &index](const shared_ptr<Column> &column) {

                                      auto field = entity->getField(column->getName());

                                      // TODO: set value into variable that suits its type
                                      auto cvalue = strdup(PQgetvalue(ptrResult, 0, index));
                                      field->setCString(cvalue);

                                      index++;
                                  });

                }
            };

            PostgreSourceDriver::PostgreSourceDriver(EntityMap &entityMap)
                    : EntitySourceDriver(entityMap),
                      _pgApiImpl(new PgApiImpl()) {
                init();
            }

            PostgreSourceDriver::~PostgreSourceDriver() {

            }

            void PostgreSourceDriver::init() {

                auto fpValue = [this](const std::shared_ptr<Column> &column,
                                      int index) -> string {

                    auto typeName = _pgApiImpl->getTypeAlias(column->getDbType());
                    auto expr = "$" + std::to_string(++index) + "::" + typeName;

                    return expr;
                };

                auto fpCondition = [this](const std::shared_ptr<Column> &column,
                                          int index) -> string {

                    auto typeName = _pgApiImpl->getTypeAlias(column->getDbType());
                    auto expr = column->getDatasourceName() + " = " + "$" + std::to_string(++index) + "::" + typeName;

                    return expr;
                };

                _getStatement = Foundation::Helper::CreateGetPreparedQuery(_entityMap, fpCondition);
                _insertStatement = Foundation::Helper::CreateInsertPreparedQuery(_entityMap, fpValue);
                _updateStatement = Foundation::Helper::CreateUpdatePreparedQuery(_entityMap, fpCondition);
                _deleteStatement = Foundation::Helper::CreateDeletePreparedQuery(_entityMap, fpCondition);
            }

            int PostgreSourceDriver::LoadEntity(std::shared_ptr<Entity> &entity) const {

                const ColumnsList &columnList = _entityMap.getColumnsForKey();

                shared_ptr<Command> command = _pgApiImpl->createCommand(_getStatement);

                _pgApiImpl->initializeParamsBindBuffer(entity, columnList, command);

                const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

                PGresult *result = PQexecParams(_pgApiImpl->PtrPgConn,
                                                command->Query.c_str(),
                                                command->nParam,
                                                command->PtrParamTypes,
                                                ptrParamValues,
                                                command->PtrParamLengths,
                                                command->PtrParamFormats,
                                                command->ResultFormat);

                // TODO: Verify result status
                ExecStatusType statusType = PQresultStatus(result);

                char *errorMessage = nullptr;

                switch (statusType) {
                    case PGRES_EMPTY_QUERY:
                        break;
                    case PGRES_COMMAND_OK:
                        break;
                    case PGRES_TUPLES_OK:
                        _pgApiImpl->retrieveResult(_entityMap, result, entity);
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

            int PostgreSourceDriver::CreateEntity(std::shared_ptr<Entity> &entity) const {

                const ColumnsList &columnsList = _entityMap.getColumnsForKey();

                auto command = _pgApiImpl->createCommand(_insertStatement);

                _pgApiImpl->initializeParamsBindBuffer(entity, columnsList, command);

                const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

                PGresult *result = PQexecParams(_pgApiImpl->PtrPgConn,
                                                command->Query.c_str(),
                                                command->nParam,
                                                command->PtrParamTypes,
                                                ptrParamValues,
                                                command->PtrParamLengths,
                                                command->PtrParamFormats,
                                                command->ResultFormat);

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

            int PostgreSourceDriver::SaveEntity(std::shared_ptr<Entity> &entity) const {

                ColumnsList columnList;

                columnList.insert(columnList.end(),
                                  _entityMap.getColumnsForUpdate().begin(),
                                  _entityMap.getColumnsForUpdate().end());

                columnList.insert(columnList.end(),
                                  _entityMap.getColumnsForKey().begin(),
                                  _entityMap.getColumnsForKey().end());

                auto command = _pgApiImpl->createCommand(_updateStatement);

                _pgApiImpl->initializeParamsBindBuffer(entity, columnList, command);

                const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

                PGresult *result = PQexecParams(_pgApiImpl->PtrPgConn,
                                                command->Query.c_str(),
                                                command->nParam,
                                                command->PtrParamTypes,
                                                ptrParamValues,
                                                command->PtrParamLengths,
                                                command->PtrParamFormats,
                                                command->ResultFormat);

                ExecStatusType statusType = PQresultStatus(result);

                // TODO: Verify result status
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

            int PostgreSourceDriver::DeleteEntity(std::shared_ptr<Entity> &entity) const {

                const ColumnsList &columnList = _entityMap.getColumnsForKey();

                shared_ptr<Command> command = _pgApiImpl->createCommand(_deleteStatement);

                _pgApiImpl->initializeParamsBindBuffer(entity, columnList, command);

                const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

                PGresult *result = PQexecParams(_pgApiImpl->PtrPgConn,
                                                command->Query.c_str(),
                                                command->nParam,
                                                command->PtrParamTypes,
                                                ptrParamValues,
                                                command->PtrParamLengths,
                                                command->PtrParamFormats,
                                                command->ResultFormat);

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

            void PostgreSourceDriver::Connect() {

                if (_pgApiImpl->PtrPgConn == nullptr) {

                    _pgApiImpl->PtrPgConn = PQsetdbLogin(_optionArgs.Host.c_str(),
                                                         std::to_string(_optionArgs.Port).c_str(),
                                                         NULL,
                                                         NULL,
                                                         _optionArgs.Base.c_str(),
                                                         _optionArgs.User.c_str(),
                                                         _optionArgs.Pass.c_str());
                    _isConnected = true;
                }
            }

            void PostgreSourceDriver::Disconnect() {

                if (_pgApiImpl->PtrPgConn != nullptr) {

                    PQfinish(_pgApiImpl->PtrPgConn);
                    _isConnected = false;
                }
            }
        }
    }
}

