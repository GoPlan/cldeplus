//
// Created by LE, Duc Anh on 6/7/15.
//

#include <stdlib.h>
#include <Foundation/Type/cldeValueFactory.h>
#include <Foundation/Exception/cldeNonSupportedDataTypeException.h>
#include <Foundation/Query/PredicateComposite.h>
#include <Foundation/Query/Comparative.h>
#include <Foundation/Query/Helper/SqlHelper.h>
#include <Foundation/Query/Helper/PredicateHelper.h>
#include "SQLiteSourceDriver.h"
#include "Amalgamation/sqlite3.h"

namespace Cloude {
    namespace SourceDriver {
        namespace SQLite {

            using ColumnsList = std::vector<std::shared_ptr<Foundation::Column>>;
            using Type = Foundation::Type::cldeValueType;

            class Command {

            public:
                Command(const std::string &query) : query(query) {
                    //
                };

                ~Command() {
                    if (_ptrStmt != nullptr) {
                        sqlite3_finalize(_ptrStmt);
                    }
                };

                int PrepareStatment(sqlite3 *ptrDb) {

                    if (ptrDb == NULL) {
                        fprintf(stderr, "Database is not open\n");
                    }

                    int resultCode = sqlite3_prepare_v2(ptrDb,
                                                        query.c_str(),
                                                        -1,
                                                        &_ptrStmt,
                                                        NULL);

                    if (resultCode != SQLITE_OK) {
                        // TODO: throw an appropriate exception
                        fprintf(stderr, "Could not prepare statement.\n");
                    }

                    return 1;
                }

                sqlite3_stmt *_ptrStmt = nullptr;

                const std::string &query;
            };

            class SQLiteSourceDriver::SQLiteApiImpl {

            public:
                SQLiteApiImpl(std::string &connectionString) : connectionString(connectionString) {
                    //
                };

                ~SQLiteApiImpl() {
                    if (_ptrSqlite3 != nullptr) {
                        sqlite3_close(_ptrSqlite3);
                    }
                };

                int Connect(const char *connString = 0) {

                    const char *tmpConnString = connString == 0 ? connectionString.c_str() : connString;

                    int resultCode = sqlite3_open_v2(tmpConnString, &_ptrSqlite3, SQLITE_OPEN_READWRITE, NULL);

                    if (resultCode != SQLITE_OK) {
                        // TODO: throw an approriate exception
                        fprintf(stderr, "%s\n", sqlite3_errmsg(_ptrSqlite3));
                        exit(EXIT_FAILURE);
                    }

                    return 1;
                }

                std::unique_ptr<Command> createCommand(const std::string &query) {
                    std::unique_ptr<Command> command(new Command(query));
                    command->PrepareStatment(_ptrSqlite3);
                    return command;
                }

                int initializeParamBindBuffers(const ColumnsList &columnsList,
                                               const std::unique_ptr<Command> &command,
                                               std::shared_ptr<Foundation::Entity> &entity) {

                    int index = 1;

                    std::for_each(columnsList.cbegin(),
                                  columnsList.cend(),
                                  [&command, &entity, &index](const std::shared_ptr<Foundation::Column> &column) {

                                      auto &field = entity->getField(column->getName());
                                      auto &value = field->getValue();

                                      if (!value) {
                                          sqlite3_bind_null(command->_ptrStmt, index++);
                                          return;
                                      }

                                      const auto ptrValueBuffer = field->getValue()->RawPointerToValueBuffer();

                                      switch (column->getDataType()) {
                                          case Type::Int64:
                                              sqlite3_int64 int64Value;
                                              int64Value = static_cast<sqlite3_int64 >(*((int64_t *) ptrValueBuffer));
                                              sqlite3_bind_int64(command->_ptrStmt,
                                                                 index++,
                                                                 int64Value);
                                              break;
                                          case Type::Varchar:
                                              sqlite3_bind_text(command->_ptrStmt,
                                                                index++,
                                                                (const char *) ptrValueBuffer,
                                                                -1,
                                                                SQLITE_STATIC);
                                              break;
                                          default:
                                              break;
                                      }
                                  });
                    return 1;
                }

                int initializeParamBindBuffers(const ColumnsList &columnsList,
                                               const std::unique_ptr<Command> &command,
                                               const std::vector<std::string> &params) {

                    int index = 1;

                    return 1;
                }

                std::string &connectionString;
                sqlite3 *_ptrSqlite3 = nullptr;
            };

            SQLiteSourceDriver::SQLiteSourceDriver(const Foundation::EntityMap &entityMap)
                    : EntitySourceDriver(entityMap),
                      _sqliteApiImpl(new SQLiteApiImpl(_optionArgs.ConnectionString)) {
                Init();
            }

            SQLiteSourceDriver::~SQLiteSourceDriver() {
                Disconnect();
            }

            void SQLiteSourceDriver::Connect() {

                if (!_sqliteApiImpl) {
                    _sqliteApiImpl = std::make_shared<SQLiteApiImpl>(_optionArgs.ConnectionString);
                }

                _sqliteApiImpl->Connect();
            }

            void SQLiteSourceDriver::Disconnect() {
                _sqliteApiImpl.reset();
            }

            void SQLiteSourceDriver::Init() {

                auto fpValue = [](const std::shared_ptr<Foundation::Column> &column, int index)
                        -> std::string {
                    return std::string("?");
                };

                auto fpCondition = [](const std::shared_ptr<Foundation::Column> &column, int index)
                        -> std::string {
                    return column->getDatasourceName() + " = " + "?";
                };

                _getStatement = Foundation::Query::Helper::SqlHelper::CreateGetPreparedQuery(_entityMap,
                                                                                             fpCondition);

                _insertStatement = Foundation::Query::Helper::SqlHelper::CreateInsertPreparedQuery(_entityMap,
                                                                                                   fpValue);

                _updateStatement = Foundation::Query::Helper::SqlHelper::CreateUpdatePreparedQuery(_entityMap,
                                                                                                   fpCondition);

                _deleteStatement = Foundation::Query::Helper::SqlHelper::CreateDeletePreparedQuery(_entityMap,
                                                                                                   fpCondition);

            }

            int SQLiteSourceDriver::Load(std::shared_ptr<Foundation::Entity> &entity) const {

                using cldeFactory = Foundation::Type::cldeValueFactory;

                const auto &columnsForGet = _entityMap.getColumnsForGet();
                const auto &columnsForKey = _entityMap.getColumnsForKey();

                auto UPtrCommand = _sqliteApiImpl->createCommand(_getStatement);

                _sqliteApiImpl->initializeParamBindBuffers(columnsForKey, UPtrCommand, entity);

                int resultCode = sqlite3_step(UPtrCommand->_ptrStmt);

                if (resultCode != SQLITE_DONE && resultCode != SQLITE_ROW) {
                    // TODO: throws an appropriate exception
                    return 0;
                }

                if (sqlite3_column_type(UPtrCommand->_ptrStmt, 0) == SQLITE_NULL) {
                    return 0;
                }

                int index = 0;

                std::for_each(columnsForGet.cbegin(),
                              columnsForGet.cend(),
                              [&entity, &UPtrCommand, &index](const std::shared_ptr<Foundation::Column> &column) {

                                  if (sqlite3_column_type(UPtrCommand->_ptrStmt, index) == SQLITE_NULL) {
                                      ++index;
                                      return;
                                  }

                                  auto &field = entity->getField(column->getName());

                                  switch (column->getDataType()) {
                                      case Type::Int64:
                                          int64_t int64Value;
                                          int64Value =
                                                  static_cast<int64_t>(sqlite3_column_int64(UPtrCommand->_ptrStmt,
                                                                                            index++));
                                          field->setValue(cldeFactory::CreateInt64(int64Value));
                                          break;
                                      case Type::Varchar:
                                          const char *strValue;
                                          strValue =
                                                  reinterpret_cast<const char *>(sqlite3_column_text(
                                                          UPtrCommand->_ptrStmt,
                                                          index++));
                                          field->setValue(cldeFactory::CreateString(strValue));
                                          break;
                                      default:
                                          ++index;
                                          const char *msg = "MySqlSourceDriver does not support this type.";
                                          throw Foundation::Exception::cldeNonSupportedDataTypeException(msg);
                                  }
                              });

                return 1;
            }

            int SQLiteSourceDriver::Insert(std::shared_ptr<Foundation::Entity> &entity) const {

                auto &columnsForKey = _entityMap.getColumnsForKey();
                auto UPtrCommand = _sqliteApiImpl->createCommand(_insertStatement);

                _sqliteApiImpl->initializeParamBindBuffers(columnsForKey, UPtrCommand, entity);

                int resultCode = sqlite3_step(UPtrCommand->_ptrStmt);

                switch (resultCode) {
                    case SQLITE_BUSY:
                        break;
                    case SQLITE_DONE:
                        break;
                    case SQLITE_ERROR:
                        // TODO: throws an appropriate exception
                        break;
                    case SQLITE_MISUSE:
                        // TODO: throws an appropriate exception
                        return 0;
                    default:
                        break;
                }

                return 1;
            }

            int SQLiteSourceDriver::Save(std::shared_ptr<Foundation::Entity> &entity) const {

                auto &columnsForUpdate = _entityMap.getColumnsForUpdate();
                auto &columnsForKey = _entityMap.getColumnsForKey();

                ColumnsList columnsList;
                columnsList.insert(columnsList.end(), columnsForUpdate.begin(), columnsForUpdate.end());
                columnsList.insert(columnsList.end(), columnsForKey.begin(), columnsForKey.end());

                auto command = _sqliteApiImpl->createCommand(_updateStatement);

                _sqliteApiImpl->initializeParamBindBuffers(columnsList, command, entity);

                int resultCode = sqlite3_step(command->_ptrStmt);

                switch (resultCode) {
                    case SQLITE_BUSY:
                        // TODO: throws an appropriate exception
                        return 0;
                    case SQLITE_DONE:
                        break;
                    case SQLITE_ERROR:
                        // TODO: throws an appropriate exception
                        return 0;
                    case SQLITE_MISUSE:
                        // TODO: throws an appropriate exception
                        return 0;
                    default:
                        break;
                }

                return 1;
            }

            int SQLiteSourceDriver::Delete(std::shared_ptr<Foundation::Entity> &entity) const {

                auto const &columnsForKey = _entityMap.getColumnsForKey();
                auto UPtrCommand = _sqliteApiImpl->createCommand(_deleteStatement);

                _sqliteApiImpl->initializeParamBindBuffers(columnsForKey, UPtrCommand, entity);

                int resultCode = sqlite3_step(UPtrCommand->_ptrStmt);

                switch (resultCode) {
                    case SQLITE_BUSY:
                        // TODO: throws an appropriate exception
                        return 0;
                    case SQLITE_DONE:
                        return 1;
                    case SQLITE_ERROR:
                        // TODO: throws an appropriate exception
                        return 0;
                    case SQLITE_MISUSE:
                        // TODO: throws an appropriate exception
                        return 0;
                    default:
                        return 0;
                }
            }

            SQLiteSourceDriver::SPtrProxySPtrVector SQLiteSourceDriver::Select(
                    const Foundation::EntitySourceDriver::SPtrPredicate &predicate,
                    Foundation::EntityStore &entityStore) const {

                using cldeFactory = Foundation::Type::cldeValueFactory;

                auto const &columnsForSelect = _entityMap.getColumnsForSelect();
                auto const F = [](const std::shared_ptr<Foundation::Column> &column, int index) -> std::string {

                    return std::string();
                };

                auto selectCompound = Foundation::Query::Helper::SqlHelper::CreateSelectPreparedQuery(_entityMap,
                                                                                                      *predicate,
                                                                                                      F);
                auto uptrCommand = _sqliteApiImpl->createCommand(selectCompound.statement);

//                _sqliteApiImpl->initializeParamBindBuffers(columnsForKey, uptrCommand, entity);

                SPtrProxySPtrVector proxies;

                int resultCode = sqlite3_step(uptrCommand->_ptrStmt);

                int index = 0;
//
//                std::for_each(columnsForSelect.cbegin(),
//                              columnsForSelect.cend(),
//                              [&entity, &uptrCommand, &index](const std::shared_ptr<Foundation::Column> &column) {
//
//                                  if (sqlite3_column_type(uptrCommand->_ptrStmt, index) == SQLITE_NULL) {
//                                      ++index;
//                                      return;
//                                  }
//
//                                  auto &field = entity->getField(column->getName());
//
//                                  switch (column->getDataType()) {
//                                      case Type::Int64:
//                                          int64_t int64Value;
//                                          int64Value =
//                                                  static_cast<int64_t>(sqlite3_column_int64(uptrCommand->_ptrStmt,
//                                                                                            index++));
//                                          field->setValue(cldeFactory::CreateInt64(int64Value));
//                                          break;
//                                      case Type::Varchar:
//                                          const char *strValue;
//                                          strValue =
//                                                  reinterpret_cast<const char *>(sqlite3_column_text(
//                                                          uptrCommand->_ptrStmt,
//                                                          index++));
//                                          field->setValue(cldeFactory::CreateString(strValue));
//                                          break;
//                                      default:
//                                          ++index;
//                                          const char *msg = "MySqlSourceDriver does not support this type.";
//                                          throw Foundation::Exception::cldeNonSupportedDataTypeException(msg);
//                                  }
//                              });

                return proxies;
            }

        }
    }
}

