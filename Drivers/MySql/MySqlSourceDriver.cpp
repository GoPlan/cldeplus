//
// Created by GoPlan on 18/05/2015.
//

#include <string>
#include <mysql.h>
#include <Foundation/Query/Helper/SqlHelper.h>
#include <Foundation/Data/ValueFactory.h>
#include <Foundation/Data/Helper/TypeHelper.h>
#include <Foundation/Data/Helper/ValueHelper.h>
#include "MySqlSourceDriver.h"

namespace Cloude {
    namespace Drivers {
        namespace MySql {

            // COMMAND
            struct Command {

                Command() = default;

                ~Command() {

                    if (PtrResultLength != nullptr) {
                        free(PtrResultLength);
                    }

                    if (PtrResultIsNull != nullptr) {
                        free(PtrResultIsNull);
                    }

                    if (PtrResultError != nullptr) {
                        free(PtrResultError);
                    }

                    if (PtrParamsBind != nullptr) {
                        free(PtrParamsBind);
                    }

                    if (PtrResultBind != nullptr) {
                        free(PtrResultBind);
                    }

                    if (PtrStmt != nullptr) {
                        mysql_stmt_close(PtrStmt);
                    }
                }

                MYSQL_STMT *PtrStmt = nullptr;
                MYSQL_BIND *PtrParamsBind = nullptr;
                MYSQL_BIND *PtrResultBind = nullptr;
                unsigned long *PtrParamsLength = nullptr;
                unsigned long *PtrResultLength = nullptr;
                my_bool *PtrResultIsNull = nullptr;
                my_bool *PtrResultError = nullptr;
            };

            using SPtrCommand = std::shared_ptr<Command>;

            // MYSQLAPIIMPL
            struct MySqlSourceDriver::MySqlApiImpl {
            
                MYSQL *PtrMySql = nullptr;

                MySqlApiImpl() {
                    mysql_library_init;
                    PtrMySql = mysql_init(PtrMySql);
                }

                ~MySqlApiImpl() {
                    if (PtrMySql != nullptr) { mysql_close(PtrMySql); }
                    mysql_library_end;
                }

                std::shared_ptr<Command> createCommand(const std::string &query) {

                    auto command = std::make_shared<Command>();
                    command->PtrStmt = mysql_stmt_init(PtrMySql);

                    if (!command->PtrStmt) {
                        assertSqlError();
                    }

                    if (mysql_stmt_prepare(command->PtrStmt, query.c_str(), query.length())) {
                        assertStmtError(command->PtrStmt);
                    }

                    return command;
                }

                void assertSqlError() {
                    if (mysql_errno(PtrMySql)) {
                        std::string msg{mysql_error(PtrMySql)};
                        throw MySqlSourceException{msg};
                    }
                }

                void assertStmtError(MYSQL_STMT *ptrMySqlStmt) {
                    if (mysql_stmt_errno(ptrMySqlStmt)) {
                        std::string msg{mysql_stmt_error(ptrMySqlStmt)};
                        throw MySqlSourceException{msg};
                    }
                }

                void initParamBinds(const Foundation::SPtrColumnVector &columnsList,
                                    const Foundation::SPtrEntity &entity,
                                    SPtrCommand &command) {

                    auto columnsListSize = columnsList.size();

                    command->PtrParamsBind = (MYSQL_BIND *) calloc(columnsListSize, sizeof(MYSQL_BIND));
                    command->PtrParamsLength = (unsigned long *) calloc(columnsListSize, sizeof(unsigned long));

                    int index = 0;

                    std::for_each(columnsList.cbegin(), columnsList.cend(),
                                  [&](const Foundation::SPtrColumn &column) -> void {

                                      auto &cell = entity->operator[](column->getName());
                                      auto &value = cell->getValue();

                                      command->PtrParamsBind[index].is_null = 0;
                                      command->PtrParamsBind[index].error = 0;

                                      if (!value) {
                                          command->PtrParamsBind[index].buffer_type = MYSQL_TYPE_NULL;
                                          ++index;
                                          return;
                                      }

                                      auto ptrLength = value->RawPointerToValueLength();
                                      auto ptrBuffer = value->RawPointerToValueBuffer();

                                      command->PtrParamsBind[index].length = static_cast<unsigned long *>(ptrLength);
                                      command->PtrParamsBind[index].buffer = ptrBuffer;

                                      setupBindTypeAndLength(cell, &command->PtrParamsBind[index]);

                                      ++index;
                                  });
                }

                void initResultBinds(const Foundation::SPtrColumnVector &columnsList,
                                     const Foundation::SPtrEntity &entity,
                                     SPtrCommand &command) {

                    using ValueFactory = Foundation::Data::ValueFactory;

                    auto columnsListSize = columnsList.size();

                    command->PtrResultBind = (MYSQL_BIND *) calloc(columnsListSize, sizeof(MYSQL_BIND));
                    command->PtrResultError = (my_bool *) calloc(columnsListSize, sizeof(my_bool));
                    command->PtrResultIsNull = (my_bool *) calloc(columnsListSize, sizeof(my_bool));
                    command->PtrResultLength = (unsigned long *) calloc(columnsListSize, sizeof(unsigned long));

                    int index = 0;

                    std::for_each(columnsList.cbegin(), columnsList.cend(),
                                  [&](const Foundation::SPtrColumn &column) -> void {

                                      auto &cell = entity->operator[](column->getName());
                                      auto &dataType = column->getDataType();
                                      auto length = column->getLength();

                                      switch (dataType) {
                                          case Foundation::Data::ValueType::Int16:
                                              cell->setValue(ValueFactory::CreateInt64(0));
                                              break;
                                          case Foundation::Data::ValueType::Int32:
                                              cell->setValue(ValueFactory::CreateInt32(0));
                                              break;
                                          case Foundation::Data::ValueType::Int64:
                                              cell->setValue(ValueFactory::CreateInt64(0));
                                              break;
                                          case Foundation::Data::ValueType::UInt16:
                                              cell->setValue(ValueFactory::CreateUInt16(0));
                                              break;
                                          case Foundation::Data::ValueType::UInt32:
                                              cell->setValue(ValueFactory::CreateUInt32(0));
                                              break;
                                          case Foundation::Data::ValueType::UInt64:
                                              cell->setValue(ValueFactory::CreateUInt64(0));
                                              break;
                                          case Foundation::Data::ValueType::Float:
                                              cell->setValue(ValueFactory::CreateFloat(0));
                                              break;
                                          case Foundation::Data::ValueType::Double:
                                              cell->setValue(ValueFactory::CreateDouble(0));
                                              break;
                                          case Foundation::Data::ValueType::VarChar:
                                              cell->setValue(ValueFactory::CreateVarChar(column->getLength()));
                                              break;
                                          case Foundation::Data::ValueType::Text:
                                              cell->setValue(ValueFactory::CreateText(""));
                                              break;
                                          default: {
                                              using TypeHelper = Foundation::Data::Helper::TypeHelper;
                                              std::string typeName{TypeHelper::CopyValueTypeToString(dataType)};
                                              std::string msg{"MySqlSourceDriver does not support " + typeName+ " yet"};
                                              throw MySqlSourceException{msg};
                                          }
                                      }

                                      auto &value = cell->getValue();
                                      auto ptrValue = value->RawPointerToValueBuffer();

                                      command->PtrResultBind[index].is_null = &command->PtrResultIsNull[index];
                                      command->PtrResultBind[index].error = &command->PtrResultError[index];
                                      command->PtrResultBind[index].length = &command->PtrResultLength[index];
                                      command->PtrResultBind[index].buffer = ptrValue;

                                      setupBindTypeAndLength(cell, &command->PtrResultBind[index]);

                                      ++index;
                                  });
                }

                void setupBindTypeAndLength(const Foundation::SPtrCell &cell,
                                            MYSQL_BIND *ptrBind) {

                    auto &dataType = cell->getColumn()->getDataType();

                    switch (dataType) {
                        case Foundation::Data::ValueType::Int32: {
                            ptrBind->buffer_type = MYSQL_TYPE_LONG;
                            ptrBind->buffer_length = sizeof(int32_t);
                            break;
                        }
                        case Foundation::Data::ValueType::Int64: {
                            ptrBind->buffer_type = MYSQL_TYPE_LONGLONG;
                            ptrBind->buffer_length = sizeof(int64_t);
                            break;
                        }
                        case Foundation::Data::ValueType::Double: {
                            ptrBind->buffer_type = MYSQL_TYPE_DOUBLE;
                            ptrBind->buffer_length = sizeof(double);
                            break;
                        }
                        case Foundation::Data::ValueType::VarChar: {
                            ptrBind->buffer_type = MYSQL_TYPE_STRING;
                            ptrBind->buffer_length = cell->getColumn()->getLength();
                            break;
                        }
                        default: {
                            using TypeHelper = Foundation::Data::Helper::TypeHelper;
                            std::string typeName{TypeHelper::CopyValueTypeToString(dataType)};
                            std::string msg{"MySqlSourceDriver does not support " + typeName+ " yet"};
                            throw MySqlSourceException{msg};
                        }
                    }
                }
            }; // END - MySqlApiImpl


            // MYSQLSOURCEDRIVER
            MySqlSourceDriver::MySqlSourceDriver(const Foundation::EntityMap &entityMap)
                    : EntitySourceDriver(entityMap),
                      _mySqlApiImpl(new MySqlApiImpl()) {
                Init();
            }

            void MySqlSourceDriver::Init() {

                using SqlHelper = Foundation::Query::Helper::SqlHelper;

                auto fptrValueProcessor = [](const Foundation::SPtrColumn &column, const int &index) -> std::string {
                    return std::string("?");
                };

                auto fptrProcessor = [](const Foundation::SPtrColumn &column, const int &index) -> std::string {
                    return std::string(column->getDatasourceName() + " = ?");
                };

                auto &sourceName = getEntityMap().getTableName();
                auto &columnsForKey = getEntityMap().getColumnsForKey();
                auto &columnsForGet = getEntityMap().getColumnsForGet();
                auto &columnsForUpdate = getEntityMap().getColumnsForUpdate();

                _getStatement = SqlHelper::CreateGetPreparedQuery(sourceName, columnsForGet, columnsForKey, fptrProcessor);
                _insertStatement = SqlHelper::CreateInsertPreparedQuery(sourceName, columnsForKey, fptrValueProcessor);
                _updateStatement = SqlHelper::CreateUpdatePreparedQuery(sourceName, columnsForUpdate, columnsForKey, fptrProcessor);
                _deleteStatement = SqlHelper::CreateDeletePreparedQuery(sourceName, columnsForKey, fptrProcessor);
            }

            void MySqlSourceDriver::Connect() {

                if (_mySqlApiImpl->PtrMySql == nullptr) {
                    _mySqlApiImpl->assertSqlError();
                }

                if (!mysql_real_connect(_mySqlApiImpl->PtrMySql,
                                        _optionArgs.Host.c_str(),
                                        _optionArgs.User.c_str(),
                                        _optionArgs.Pass.c_str(),
                                        _optionArgs.Base.c_str(),
                                        _optionArgs.Port,
                                        NULL, 0)) {

                    _mySqlApiImpl->assertSqlError();
                }
            }

            void MySqlSourceDriver::Disconnect() {
                //
            }

            int MySqlSourceDriver::Load(Foundation::SPtrEntity &entity) const {

                auto command = _mySqlApiImpl->createCommand(_getStatement);

                _mySqlApiImpl->initParamBinds(getEntityMap().getColumnsForKey(), entity, command);
                _mySqlApiImpl->initResultBinds(getEntityMap().getColumnsForGet(), entity, command);

                if (mysql_stmt_bind_param(command->PtrStmt, command->PtrParamsBind)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                if (mysql_stmt_bind_result(command->PtrStmt, command->PtrResultBind)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                if (mysql_stmt_execute(command->PtrStmt)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                auto rowStatus = mysql_stmt_fetch(command->PtrStmt);

                switch (rowStatus) {
                    case 0:
                        return 1;
                    case 1:
                        _mySqlApiImpl->assertSqlError();
                        _mySqlApiImpl->assertStmtError(command->PtrStmt);
                        break;
                    case MYSQL_NO_DATA:
                        return 0;
                    case MYSQL_DATA_TRUNCATED:
                        throw MySqlSourceException("fetch error: MYSQL_DATA_TRUNCATED");
                    default:
                        throw MySqlSourceException("fetch error: unknown return status code");
                }

                return 0;
            }

            int MySqlSourceDriver::Insert(Foundation::SPtrEntity &entity) const {

                std::shared_ptr<Command> command = _mySqlApiImpl->createCommand(_insertStatement);

                _mySqlApiImpl->initParamBinds(getEntityMap().getColumnsForKey(), entity, command);

                if (mysql_stmt_bind_param(command->PtrStmt, command->PtrParamsBind)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                if (mysql_stmt_execute(command->PtrStmt)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                return 1;
            }

            int MySqlSourceDriver::Save(Foundation::SPtrEntity &entity) const {

                auto command = _mySqlApiImpl->createCommand(_updateStatement);
                auto &columnsForKey = getEntityMap().getColumnsForKey();
                auto &columnsForUpdate = getEntityMap().getColumnsForUpdate();

                Foundation::SPtrColumnVector joinedColumnsList;
                joinedColumnsList.reserve(columnsForUpdate.size() + columnsForKey.size());
                joinedColumnsList.insert(joinedColumnsList.end(), columnsForUpdate.begin(), columnsForUpdate.end());
                joinedColumnsList.insert(joinedColumnsList.end(), columnsForKey.begin(), columnsForKey.end());

                _mySqlApiImpl->initParamBinds(joinedColumnsList, entity, command);

                if (mysql_stmt_bind_param(command->PtrStmt, command->PtrParamsBind)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                if (mysql_stmt_execute(command->PtrStmt)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                return 1;
            }

            int MySqlSourceDriver::Delete(Foundation::SPtrEntity &entity) const {

                auto command = _mySqlApiImpl->createCommand(_deleteStatement);

                _mySqlApiImpl->initParamBinds(getEntityMap().getColumnsForKey(), entity, command);

                if (mysql_stmt_bind_param(command->PtrStmt, command->PtrParamsBind)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                if (mysql_stmt_execute(command->PtrStmt)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                return 1;
            }

            Foundation::SPtrEntityProxyVector MySqlSourceDriver::Select(
                    const Foundation::Query::SPtrCriteria &sptrCriteria,
                    const Foundation::SPtrColumnVector &columnsForProjection) const {


                Foundation::SPtrEntityProxyVector proxies{};
                return proxies;
            }
        }
    }
}