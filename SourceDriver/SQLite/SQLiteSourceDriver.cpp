//
// Created by LE, Duc Anh on 6/7/15.
//

#include <Framework/Helper/SqlGenerator.h>
#include <stdlib.h>
#include "SQLiteSourceDriver.h"
#include "Amalgamation/sqlite3.h"

using namespace std;

namespace Cloude {
    namespace SourceDriver {
        namespace SQLite {

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

                sqlite3_stmt *_ptrStmt;
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

                std::shared_ptr<Command> createCommand(const std::string &query) {

                    auto command = std::make_shared<Command>(query);
                    auto resultCode = command->PrepareStatment(_ptrSqlite3);

                    return command;
                }

                int initializeParamBindBuffers(const ColumnsList &columnsList,
                                               std::shared_ptr<Entity> &entity,
                                               std::shared_ptr<Command> &command) {

                    int index = 1;

                    std::for_each(columnsList.cbegin(),
                                  columnsList.cend(),
                                  [&command, &entity, &index](const std::shared_ptr<Column> &column) {

                                      auto field = entity->getField(column->getName());

                                      switch (column->getDbType()) {
                                          case DbType::Int64:
                                              sqlite3_int64 int64Value;
                                              int64Value = static_cast<sqlite3_int64 >(field->getInt64());
                                              sqlite3_bind_int64(command->_ptrStmt,
                                                                 index,
                                                                 int64Value);
                                              break;
                                          case DbType::String:
                                              int charSize, strSize;

                                              charSize = sizeof(char);
                                              strSize = static_cast<int>(charSize *
                                                                         strlen(field->getCString()));

                                              sqlite3_bind_text(command->_ptrStmt,
                                                                index,
                                                                field->getCString(),
                                                                strSize,
                                                                SQLITE_STATIC);
                                              break;
                                          default:
                                              break;
                                      }

                                      ++index;
                                  });
                    return 1;
                }

                std::string &connectionString;
                sqlite3 *_ptrSqlite3 = nullptr;
            };

            SQLiteSourceDriver::SQLiteSourceDriver(EntityMap &entityMap)
                    : EntitySourceDriver(entityMap),
                      _sqliteApiImpl(new SQLiteApiImpl(_optionArgs.ConnectionString)) {
                init();
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

            int SQLiteSourceDriver::LoadEntity(std::shared_ptr<Entity> &entity) const {

                auto &columnsForGet = _entityMap.getColumnsForGet();
                auto &columnsForKey = _entityMap.getColumnsForKey();

                std::shared_ptr<Command> command = _sqliteApiImpl->createCommand(_getStatement);

                _sqliteApiImpl->initializeParamBindBuffers(columnsForKey, entity, command);

                int resultCode = sqlite3_step(command->_ptrStmt);

                if (resultCode != SQLITE_DONE && resultCode != SQLITE_ROW) {
                    // TODO: throws an appropriate exception
                    return 0;
                }

                if (sqlite3_column_type(command->_ptrStmt, 0) == SQLITE_NULL) {
                    return 0;
                }

                int index = 0;

                std::for_each(columnsForGet.cbegin(),
                              columnsForGet.cend(),
                              [&entity, &command, &index](const std::shared_ptr<Column> &column) {

                                  auto field = entity->getField(column->getName());

                                  switch (column->getDbType()) {
                                      case DbType::Int64:
                                          field->setInt64(static_cast<int64_t>(sqlite3_column_int64(command->_ptrStmt,
                                                                                                    index)));
                                          break;
                                      case DbType::String:
                                          const char *text;
                                          text = (const char *) (sqlite3_column_text(command->_ptrStmt,
                                                                                     index));
                                          field->setCString(text);
                                          break;
                                      default:
                                          break;
                                  }

                                  ++index;
                              });

                return 1;
            }

            int SQLiteSourceDriver::CreateEntity(std::shared_ptr<Entity> &entity) const {

                auto &columnsForKey = _entityMap.getColumnsForKey();

                std::shared_ptr<Command> command = _sqliteApiImpl->createCommand(_insertStatement);

                _sqliteApiImpl->initializeParamBindBuffers(columnsForKey, entity, command);

                int resultCode = sqlite3_step(command->_ptrStmt);

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

            int SQLiteSourceDriver::SaveEntity(std::shared_ptr<Entity> &entity) const {

                auto &columnsForUpdate = _entityMap.getColumnsForUpdate();
                auto &columnsForKey = _entityMap.getColumnsForKey();

                ColumnsList columnsList;
                columnsList.insert(columnsList.end(), columnsForUpdate.begin(), columnsForUpdate.end());
                columnsList.insert(columnsList.end(), columnsForKey.begin(), columnsForKey.end());

                std::shared_ptr<Command> command = _sqliteApiImpl->createCommand(_updateStatement);

                _sqliteApiImpl->initializeParamBindBuffers(columnsList, entity, command);

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

            int SQLiteSourceDriver::DeleteEntity(std::shared_ptr<Entity> &entity) const {

                auto &columnsForKey = _entityMap.getColumnsForKey();

                std::shared_ptr<Command> command = _sqliteApiImpl->createCommand(_deleteStatement);

                _sqliteApiImpl->initializeParamBindBuffers(columnsForKey, entity, command);

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

            void SQLiteSourceDriver::init() {

                auto fpValue = [this](const std::shared_ptr<Column> &column,
                                      int index) -> string {
                    return "?";
                };

                auto fpCondition = [this](const std::shared_ptr<Column> &column,
                                          int index) -> string {
                    return column->getDatasourceName() + " = " + "?";
                };

                _getStatement = Framework::Helper::CreateGetPreparedQuery(_entityMap, fpCondition);
                _insertStatement = Framework::Helper::CreateInsertPreparedQuery(_entityMap, fpValue);
                _updateStatement = Framework::Helper::CreateUpdatePreparedQuery(_entityMap, fpCondition);
                _deleteStatement = Framework::Helper::CreateDeletePreparedQuery(_entityMap, fpCondition);
            }
        }
    }
}

