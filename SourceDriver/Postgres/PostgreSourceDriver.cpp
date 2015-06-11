//
// Created by LE, Duc Anh on 5/27/15.
//

#include <memory>
#include <cstdlib>
#include <iostream>
#include <libpq-fe.h>
#include <Foundation/Helper/SqlGenerator.h>
#include <Foundation/Exception/cldeNonSupportedDataTypeException.h>
#include <Foundation/Type/cldeValueFactory.h>
#include "PostgreSourceDriver.h"

namespace Cloude {
    namespace SourceDriver {
        namespace PostgreSql {

            using ColumnsList = std::vector<std::shared_ptr<Foundation::Column>>;
            using Column = Foundation::Column;
            using Entity = Foundation::Entity;
            using EntityMap = Foundation::EntityMap;

            class Command {
            public:
                Command(const PGconn &conn, const std::string &query) : PGConn(conn),
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
                const char **PtrParamValues = nullptr;

                const PGconn &PGConn;
                const std::string &Query;
            };

            class PostgreSourceDriver::PgApiImpl {
            public:
                PGconn *PtrPgConn;

            public:
                std::shared_ptr<Command> createCommand(const std::string &query) {
                    std::shared_ptr<Command> command = std::make_shared<Command>(*PtrPgConn, query);
                    return command;
                }

                void initializeParamsBindBuffer(std::shared_ptr<Entity> &entity,
                                                const ColumnsList &columnsList,
                                                std::shared_ptr<Command> &command) {

                    auto nParam = columnsList.size();

                    command->nParam = (int) columnsList.size();
                    command->PtrParamLengths = (int *) calloc(nParam, sizeof(int));
                    command->PtrParamValues = (const char **) calloc(nParam, sizeof(char *));

                    int index = 0;

                    std::for_each(columnsList.cbegin(),
                                  columnsList.cend(),
                                  [&entity, &command, &index](const std::shared_ptr<Column> &column) {

                                      auto &field = entity->operator[](column->getName());
                                      auto &value = field->getValue();

                                      command->PtrParamLengths[index] = static_cast<int>(column->getLength());

                                      if (!value) {
                                          command->PtrParamValues[index] = NULL;
                                          ++index;
                                          return;
                                      }

                                      command->PtrParamValues[index] = value->ToString().c_str();

                                      ++index;
                                  });
                }

                std::string getTypeAlias(Foundation::Type::cldeValueType valueType) {

                    switch (valueType) {
                        case Foundation::Type::cldeValueType::Boolean:
                            return "boolean";
                        case Foundation::Type::cldeValueType::Byte:
                            return "bytea";
                        case Foundation::Type::cldeValueType::Int16:
                            return "smallint";
                        case Foundation::Type::cldeValueType::Int32:
                            return "integer";
                        case Foundation::Type::cldeValueType::Int64:
                            return "bigint";
                        case Foundation::Type::cldeValueType::UInt16:
                            return "smallint";
                        case Foundation::Type::cldeValueType::UInt32:
                            return "integer";
                        case Foundation::Type::cldeValueType::UInt64:
                            return "bigint";
                        case Foundation::Type::cldeValueType::Double:
                            return "double";
                        case Foundation::Type::cldeValueType::Float:
                            return "real";
                        case Foundation::Type::cldeValueType::Decimal:
                            return "decimal";
                        case Foundation::Type::cldeValueType::Numeric:
                            return "numeric";
                        case Foundation::Type::cldeValueType::Varchar:
                            return "varchar";
                        case Foundation::Type::cldeValueType::Currency:
                            return "money";
                        case Foundation::Type::cldeValueType::Date:
                            return "date";
                        case Foundation::Type::cldeValueType::Time:
                            return "time";
                        case Foundation::Type::cldeValueType::Timestamp:
                            return "timestamp";
                        case Foundation::Type::cldeValueType::Interval:
                            return "interval";
                        default:
                            throw Foundation::Exception::cldeNonSupportedDataTypeException();
                    }
                }


                int retrieveResult(const EntityMap &entityMap,
                                   const PGresult *ptrResult,
                                   std::shared_ptr<Entity> &entity) {

                    using cldeFactory = Foundation::Type::cldeValueFactory;

                    int resultCode = 0;

                    if ((resultCode = PQntuples(ptrResult)) == 0) {
                        return resultCode;
                    }

                    auto columnsForGet = entityMap.getColumnsForGet();

                    int index = 0;

                    std::for_each(columnsForGet.cbegin(),
                                  columnsForGet.cend(),
                                  [&entity, &ptrResult, &index](const std::shared_ptr<Column> &column) {

                                      auto &field = entity->getField(column->getName());

                                      if (PQgetisnull(ptrResult, 0, index)) {
                                          ++index;
                                          return;
                                      }

                                      switch (column->getDataType()) {
                                          case Foundation::Type::cldeValueType::Int64:
                                              field->setValue(cldeFactory::CreateInt64(atoll(PQgetvalue(ptrResult,
                                                                                                        0,
                                                                                                        index))));
                                              break;
                                          case Foundation::Type::cldeValueType::Varchar:
                                              field->setValue(cldeFactory::CreateString(PQgetvalue(ptrResult,
                                                                                                   0,
                                                                                                   index)));
                                              break;
                                          default:
                                              throw Foundation::Exception::cldeNonSupportedDataTypeException();
                                      }

                                      ++index;
                                  });

                    return resultCode;
                }
            };

            PostgreSourceDriver::PostgreSourceDriver(EntityMap &entityMap)
                    : EntitySourceDriver(entityMap),
                      _pgApiImpl(new PgApiImpl()) {
                init();
            }

            PostgreSourceDriver::~PostgreSourceDriver() {

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

            void PostgreSourceDriver::init() {

                auto fpValue = [this](const std::shared_ptr<Column> &column,
                                      int index) -> std::string {

                    auto typeName = _pgApiImpl->getTypeAlias(column->getDataType());
                    auto expr = "$" + std::to_string(++index) + "::" + typeName;

                    return expr;
                };

                auto fpCondition = [this](const std::shared_ptr<Column> &column,
                                          int index) -> std::string {

                    auto typeName = _pgApiImpl->getTypeAlias(column->getDataType());
                    auto expr = column->getDatasourceName() + " = " + "$" + std::to_string(++index) + "::" + typeName;

                    return expr;
                };

                _getStatement = Foundation::Helper::CreateGetPreparedQuery(_entityMap, fpCondition);
                _insertStatement = Foundation::Helper::CreateInsertPreparedQuery(_entityMap, fpValue);
                _updateStatement = Foundation::Helper::CreateUpdatePreparedQuery(_entityMap, fpCondition);
                _deleteStatement = Foundation::Helper::CreateDeletePreparedQuery(_entityMap, fpCondition);
            }

            int PostgreSourceDriver::Load(std::shared_ptr<Entity> &entity) const {

                const ColumnsList &columnList = _entityMap.getColumnsForKey();

                auto command = _pgApiImpl->createCommand(_getStatement);

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

                int resultCode = 0;

                switch (statusType) {
                    case PGRES_EMPTY_QUERY:
                        break;
                    case PGRES_COMMAND_OK:
                        break;
                    case PGRES_TUPLES_OK:
                        resultCode = _pgApiImpl->retrieveResult(_entityMap, result, entity);
                        break;
                    case PGRES_COPY_OUT:
                        break;
                    case PGRES_COPY_IN:
                        break;
                    case PGRES_BAD_RESPONSE:
                        errorMessage = PQresultErrorMessage(result);
                        std::cout << errorMessage << std::endl;
                        break;
                    case PGRES_NONFATAL_ERROR:
                        errorMessage = PQresultErrorMessage(result);
                        std::cout << errorMessage << std::endl;
                        break;
                    case PGRES_FATAL_ERROR:
                        errorMessage = PQresultErrorMessage(result);
                        std::cout << errorMessage << std::endl;
                        break;
                    case PGRES_COPY_BOTH:
                        break;
                    case PGRES_SINGLE_TUPLE:
                        break;
                }

                PQclear(result);

                return resultCode;
            }

            int PostgreSourceDriver::Insert(std::shared_ptr<Entity> &entity) const {

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
                        std::cout << errorMessage << std::endl;
                        break;
                    case PGRES_NONFATAL_ERROR:
                        errorMessage = PQresultErrorMessage(result);
                        std::cout << errorMessage << std::endl;
                        break;
                    case PGRES_FATAL_ERROR:
                        errorMessage = PQresultErrorMessage(result);
                        std::cout << errorMessage << std::endl;
                        break;
                    case PGRES_COPY_BOTH:
                        break;
                    case PGRES_SINGLE_TUPLE:
                        break;
                }

                PQclear(result);

                return 1;
            }

            int PostgreSourceDriver::Save(std::shared_ptr<Entity> &entity) const {

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
                        std::cout << errorMessage << std::endl;
                        break;
                    case PGRES_NONFATAL_ERROR:
                        errorMessage = PQresultErrorMessage(result);
                        std::cout << errorMessage << std::endl;
                        break;
                    case PGRES_FATAL_ERROR:
                        errorMessage = PQresultErrorMessage(result);
                        std::cout << errorMessage << std::endl;
                        break;
                    case PGRES_COPY_BOTH:
                        break;
                    case PGRES_SINGLE_TUPLE:
                        break;
                }

                PQclear(result);

                return 1;
            }

            int PostgreSourceDriver::Delete(std::shared_ptr<Entity> &entity) const {

                const ColumnsList &columnList = _entityMap.getColumnsForKey();

                auto command = _pgApiImpl->createCommand(_deleteStatement);

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
                        std::cout << errorMessage << std::endl;
                        break;
                    case PGRES_NONFATAL_ERROR:
                        errorMessage = PQresultErrorMessage(result);
                        std::cout << errorMessage << std::endl;
                        break;
                    case PGRES_FATAL_ERROR:
                        errorMessage = PQresultErrorMessage(result);
                        std::cout << errorMessage << std::endl;
                        break;
                    case PGRES_COPY_BOTH:
                        break;
                    case PGRES_SINGLE_TUPLE:
                        break;
                }

                PQclear(result);

                return 1;
            }

            std::vector<Foundation::EntityProxy> PostgreSourceDriver::Select(
                    std::shared_ptr<Predicate> &expr) const {
                return std::vector<Foundation::EntityProxy>();
            }
        }
    }
}

