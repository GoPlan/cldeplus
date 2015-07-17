//
// Created by GoPlan on 18/05/2015.
//

#include <string>
#include <iostream>
#include <mysql.h>
#include <Foundation/Query/Helper/SqlHelper.h>
#include <Foundation/Data/ValueFactory.h>
#include <Foundation/Data/Helper/TypeHelper.h>
#include <Foundation/Data/Helper/ValueHelper.h>
#include <Foundation/Store/Helper/EntityStoreHelper.h>
#include <Foundation/Enum/CommonBufferSize.h>
#include "MySqlSourceDriver.h"
#include "Helper/MySqlSourceHelper.h"

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

                    if (PtrResultIsUnsigned != nullptr) {
                        free(PtrResultIsUnsigned);
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
                my_bool *PtrResultIsUnsigned = nullptr;
                my_bool *PtrResultError = nullptr;
                std::vector<int> LargeCellIndices;
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

                                      auto &cell = entity->getCell(column->getName());
                                      auto &value = cell->getValue();

                                      command->PtrParamsBind[index].is_null = 0;
                                      command->PtrParamsBind[index].error = 0;

                                      if (!value) {
                                          command->PtrParamsBind[index].buffer_type = MYSQL_TYPE_NULL;
                                          ++index;
                                          return;
                                      }

                                      auto ptrLength = value->PointerToActualSizeVar();
                                      auto ptrBuffer = value->PointerToBuffer();

                                      command->PtrParamsBind[index].length = static_cast<unsigned long *>(ptrLength);
                                      command->PtrParamsBind[index].buffer = ptrBuffer;

                                      setupBindTypeAndLength(cell->getColumn(), &command->PtrParamsBind[index]);

                                      ++index;
                                  });
                }

                void initParamBinds(const Foundation::Query::SPtrCriteriaVector &criteriaList,
                                    SPtrCommand &command) {

                    command->PtrParamsBind = (MYSQL_BIND *) calloc(criteriaList.size(), sizeof(MYSQL_BIND));
                    command->PtrParamsLength = (unsigned long *) calloc(criteriaList.size(), sizeof(unsigned long));

                    int index = 0;

                    std::for_each(criteriaList.cbegin(), criteriaList.cend(),
                                  [&](const Foundation::Query::SPtrCriteria &sptrCriteria) -> void {

                                      auto &value = sptrCriteria->getValue();

                                      command->PtrParamsBind[index].is_null = 0;
                                      command->PtrParamsBind[index].error = 0;

                                      if (!value) {
                                          command->PtrParamsBind[index].buffer_type = MYSQL_TYPE_NULL;
                                          ++index;
                                          return;
                                      }

                                      auto ptrLength = value->PointerToActualSizeVar();
                                      auto ptrBuffer = value->PointerToBuffer();

                                      command->PtrParamsBind[index].length = static_cast<unsigned long *>(ptrLength);
                                      command->PtrParamsBind[index].buffer = ptrBuffer;

                                      setupBindTypeAndLength(sptrCriteria->getColumn(), &command->PtrParamsBind[index]);

                                      ++index;
                                  });
                }

                void initResultBinds(const Foundation::SPtrColumnVector &columnsList,
                                     const Foundation::Store::SPtrDataRecord &record,
                                     SPtrCommand &command) {

                    using CldeValueFactory = Foundation::Data::ValueFactory;

                    auto columnsListSize = columnsList.size();

                    command->PtrResultBind = (MYSQL_BIND *) calloc(columnsListSize, sizeof(MYSQL_BIND));
                    command->PtrResultError = (my_bool *) calloc(columnsListSize, sizeof(my_bool));
                    command->PtrResultIsNull = (my_bool *) calloc(columnsListSize, sizeof(my_bool));
                    command->PtrResultIsUnsigned = (my_bool *) calloc(columnsListSize, sizeof(my_bool));
                    command->PtrResultLength = (unsigned long *) calloc(columnsListSize, sizeof(unsigned long));

                    int index = 0;

                    std::for_each(columnsList.cbegin(), columnsList.cend(),
                                  [&](const Foundation::SPtrColumn &column) -> void {

                                      auto &sptrCell = record->getCell(column->getName());
                                      auto &dataType = column->getDataType();
                                      auto ptrBind = &command->PtrResultBind[index];

                                      setupBindTypeAndLength(sptrCell->getColumn(), ptrBind);

                                      ptrBind->length = &command->PtrResultLength[index];
                                      ptrBind->is_null = &command->PtrResultIsNull[index];
                                      ptrBind->error = &command->PtrResultError[index];

                                      switch (dataType) {
                                          case Foundation::Data::ValueType::Int16: {
                                              sptrCell->setValue(CldeValueFactory::CreateInt16(0));
                                              ptrBind->buffer = sptrCell->getValue()->PointerToBuffer();
                                              break;
                                          }
                                          case Foundation::Data::ValueType::Int32: {
                                              sptrCell->setValue(CldeValueFactory::CreateInt32(0));
                                              ptrBind->buffer = sptrCell->getValue()->PointerToBuffer();
                                              break;
                                          }
                                          case Foundation::Data::ValueType::Int64: {
                                              sptrCell->setValue(CldeValueFactory::CreateInt64(0));
                                              ptrBind->buffer = sptrCell->getValue()->PointerToBuffer();
                                              break;
                                          }
                                          case Foundation::Data::ValueType::UInt16: {
                                              sptrCell->setValue(CldeValueFactory::CreateUInt16(0));
                                              ptrBind->buffer = sptrCell->getValue()->PointerToBuffer();
                                              break;
                                          }
                                          case Foundation::Data::ValueType::UInt32: {
                                              sptrCell->setValue(CldeValueFactory::CreateUInt32(0));
                                              ptrBind->buffer = sptrCell->getValue()->PointerToBuffer();
                                              break;
                                          }
                                          case Foundation::Data::ValueType::UInt64: {
                                              sptrCell->setValue(CldeValueFactory::CreateUInt64(0));
                                              ptrBind->buffer = sptrCell->getValue()->PointerToBuffer();
                                              break;
                                          }
                                          case Foundation::Data::ValueType::Double: {
                                              sptrCell->setValue(CldeValueFactory::CreateDouble(0));
                                              ptrBind->buffer = sptrCell->getValue()->PointerToBuffer();
                                              break;
                                          }
                                          case Foundation::Data::ValueType::Float: {
                                              sptrCell->setValue(CldeValueFactory::CreateFloat(0));
                                              ptrBind->buffer = sptrCell->getValue()->PointerToBuffer();
                                              break;
                                          }
                                          case Foundation::Data::ValueType::VarChar: {
                                              sptrCell->setValue(CldeValueFactory::CreateVarChar(column->getLength()));
                                              ptrBind->buffer = sptrCell->getValue()->PointerToBuffer();
                                              break;
                                          }
                                          case Foundation::Data::ValueType::Text: {
                                              ptrBind->buffer = 0;
                                              ptrBind->buffer_length = 0;
                                              command->LargeCellIndices.push_back(index);
                                              break;
                                          }
                                          case Foundation::Data::ValueType::DateTime: {
                                              sptrCell->setValue(CldeValueFactory::CreateDateTime());
                                              ptrBind->buffer = sptrCell->getValue()->PointerToBuffer();
                                              break;
                                          }
                                          case Foundation::Data::ValueType::Date: {
                                              sptrCell->setValue(CldeValueFactory::CreateDate());
                                              ptrBind->buffer = sptrCell->getValue()->PointerToBuffer();
                                              break;
                                          }
                                          case Foundation::Data::ValueType::Time: {
                                              sptrCell->setValue(CldeValueFactory::CreateTime());
                                              ptrBind->buffer = sptrCell->getValue()->PointerToBuffer();
                                              break;
                                          }
                                          default: {
                                              using TypeHelper = Foundation::Data::Helper::TypeHelper;
                                              std::string typeName{TypeHelper::CopyValueTypeToString(dataType)};
                                              std::string msg{"MySql driver does not support " + typeName + " yet"};
                                              throw MySqlSourceException{msg};
                                          }
                                      }

                                      ++index;
                                  });
                }

                void setupBindTypeAndLength(const Foundation::SPtrColumn &sptrColumn, MYSQL_BIND *ptrBind) {

                    auto &dataType = sptrColumn->getDataType();

                    switch (dataType) {
                        case Foundation::Data::ValueType::Int16: {
                            ptrBind->buffer_type = MYSQL_TYPE_SHORT;
                            ptrBind->buffer_length = sizeof(int16_t);
                            ptrBind->is_unsigned = false;
                            break;
                        }
                        case Foundation::Data::ValueType::Int32: {
                            ptrBind->buffer_type = MYSQL_TYPE_LONG;
                            ptrBind->buffer_length = sizeof(int32_t);
                            ptrBind->is_unsigned = false;
                            break;
                        }
                        case Foundation::Data::ValueType::Int64: {
                            ptrBind->buffer_type = MYSQL_TYPE_LONGLONG;
                            ptrBind->buffer_length = sizeof(int64_t);
                            ptrBind->is_unsigned = false;
                            break;
                        }
                        case Foundation::Data::ValueType::UInt16: {
                            ptrBind->buffer_type = MYSQL_TYPE_SHORT;
                            ptrBind->buffer_length = sizeof(uint16_t);
                            ptrBind->is_unsigned = true;
                            break;
                        }
                        case Foundation::Data::ValueType::UInt32: {
                            ptrBind->buffer_type = MYSQL_TYPE_LONG;
                            ptrBind->buffer_length = sizeof(uint32_t);
                            ptrBind->is_unsigned = true;
                            break;
                        }
                        case Foundation::Data::ValueType::UInt64: {
                            ptrBind->buffer_type = MYSQL_TYPE_LONGLONG;
                            ptrBind->buffer_length = sizeof(uint64_t);
                            ptrBind->is_unsigned = true;
                            break;
                        }
                        case Foundation::Data::ValueType::Double: {
                            ptrBind->buffer_type = MYSQL_TYPE_DOUBLE;
                            ptrBind->buffer_length = sizeof(double);
                            break;
                        }
                        case Foundation::Data::ValueType::Float: {
                            ptrBind->buffer_type = MYSQL_TYPE_FLOAT;
                            ptrBind->buffer_length = sizeof(float);
                            break;
                        }
                        case Foundation::Data::ValueType::VarChar: {
                            ptrBind->buffer_type = MYSQL_TYPE_STRING;
                            ptrBind->buffer_length = sptrColumn->getLength();
                            break;
                        }
                        case Foundation::Data::ValueType::Text: {
                            ptrBind->buffer_type = MYSQL_TYPE_MEDIUM_BLOB;
                            ptrBind->buffer_length = sptrColumn->getLength();
                            break;
                        }
                        case Foundation::Data::ValueType::DateTime: {
                            ptrBind->buffer_type = MYSQL_TYPE_DATETIME;
                            ptrBind->buffer_length = sizeof(MYSQL_TIME);
                            break;
                        }
                        case Foundation::Data::ValueType::Date: {
                            ptrBind->buffer_type = MYSQL_TYPE_DATE;
                            ptrBind->buffer_length = sizeof(MYSQL_TIME);
                            break;
                        }
                        case Foundation::Data::ValueType::Time: {
                            ptrBind->buffer_type = MYSQL_TYPE_TIME;
                            ptrBind->buffer_length = sizeof(MYSQL_TIME);
                            break;
                        }
                        default: {
                            using TypeHelper = Foundation::Data::Helper::TypeHelper;
                            std::string typeName{TypeHelper::CopyValueTypeToString(dataType)};
                            std::string msg{"MySqlSourceDriver(SetupBind) does not support " + typeName + " yet"};
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

                auto fptrInsertParamProcessor =
                        [](const Foundation::SPtrColumn &column, const int &index) -> std::string {
                            return std::string("?");
                        };

                auto fptrSelectParamProcessor =
                        [](const Foundation::SPtrColumn &column, const int &index) -> std::string {
                            return std::string(column->getDatasourceName() + " = ?");
                        };

                auto &sourceName = getEntityMap().getTableName();
                auto &columnsForKey = getEntityMap().getColumnsForKey();
                auto &columnsForGet = getEntityMap().getColumnsForGet();
                auto &columnsForUpdate = getEntityMap().getColumnsForUpdate();

                _getStatement = SqlHelper::CreateGetPreparedQuery(sourceName,
                                                                  columnsForGet,
                                                                  columnsForKey,
                                                                  fptrSelectParamProcessor);

                _insertStatement = SqlHelper::CreateInsertPreparedQuery(sourceName,
                                                                        columnsForKey,
                                                                        fptrInsertParamProcessor);

                _updateStatement = SqlHelper::CreateUpdatePreparedQuery(sourceName,
                                                                        columnsForUpdate,
                                                                        columnsForKey,
                                                                        fptrSelectParamProcessor);

                _deleteStatement = SqlHelper::CreateDeletePreparedQuery(sourceName,
                                                                        columnsForKey,
                                                                        fptrSelectParamProcessor);
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

                SPtrCommand command = _mySqlApiImpl->createCommand(_getStatement);

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

                // Fetch cells
                if (!rowStatus || rowStatus == MYSQL_DATA_TRUNCATED) {

                    for (auto &index : command->LargeCellIndices) {

                        auto ptrLength = command->PtrResultBind[index].length;
                        auto &isNull = command->PtrResultIsNull[index];
                        auto &isError = command->PtrResultError[index];

                        if (isError) {
                            _mySqlApiImpl->assertStmtError(command->PtrStmt);
                        }

                        auto &sptrColumn = getEntityMap().getColumnsForGet().at(index);
                        auto &sptrCell = entity->getCell(sptrColumn->getName());
                        auto value = Foundation::Data::ValueFactory::CreateText(*ptrLength);
                        sptrCell->setValue(value);

                        command->PtrResultBind[index].buffer = value->PointerToBuffer();
                        command->PtrResultBind[index].buffer_length = *ptrLength;

                        mysql_stmt_fetch_column(command->PtrStmt, &command->PtrResultBind[index], index, 0);
                    }
                }

                if (rowStatus != MYSQL_NO_DATA && rowStatus != MYSQL_DATA_TRUNCATED) {
                    _mySqlApiImpl->assertSqlError();
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                return 1;
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

                using SqlHelper = Foundation::Query::Helper::SqlHelper;

                auto fptrSelectParamProcessor =
                        [](const Foundation::SPtrColumn &column, const int &index) -> std::string {
                            return std::string("?");
                        };

                auto pairSelectStmt = SqlHelper::CreateSelectPreparedQuery(getEntityMap().getTableName(),
                                                                           columnsForProjection,
                                                                           sptrCriteria,
                                                                           fptrSelectParamProcessor);

                auto command = _mySqlApiImpl->createCommand(pairSelectStmt.first);
                auto sptrProxy = Foundation::CreateEntityProxy();

                using StoreHelper = Foundation::Store::Helper::EntityStoreHelper;
                StoreHelper::GenerateCellsFromColumns(columnsForProjection, sptrProxy);

                _mySqlApiImpl->initParamBinds(pairSelectStmt.second, command);
                _mySqlApiImpl->initResultBinds(columnsForProjection, sptrProxy, command);

                if (mysql_stmt_bind_param(command->PtrStmt, command->PtrParamsBind)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                if (mysql_stmt_bind_result(command->PtrStmt, command->PtrResultBind)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                if (mysql_stmt_execute(command->PtrStmt)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                Foundation::SPtrEntityProxyVector proxies{};
                proxies.reserve(Foundation::CommonBufferSize::SIXTYFOUR);

                int rowStatus = MYSQL_NO_DATA;

                while (!(rowStatus = mysql_stmt_fetch(command->PtrStmt))) {
                    auto newProxy = Foundation::Store::Helper::EntityStoreHelper::CopySPtrProxy(sptrProxy);
                    proxies.push_back(newProxy);
                }

                if (rowStatus != MYSQL_NO_DATA) {
                    _mySqlApiImpl->assertSqlError();
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);

                    if (rowStatus == MYSQL_DATA_TRUNCATED) {
                        throw MySqlSourceException("fetch error: MYSQL_DATA_TRUNCATED");
                    }
                }

                proxies.shrink_to_fit();

                return proxies;
            }
        }
    }
}