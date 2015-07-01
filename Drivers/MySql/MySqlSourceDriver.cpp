//
// Created by GoPlan on 18/05/2015.
//

#include <string>
#include <iostream>
#include <mysql.h>
#include <Foundation/Exception/cldeNonSupportedDataTypeException.h>
#include <Foundation/Helper/SqlGenerator.h>
#include <Foundation/Type/cldeValueFactory.h>
#include "MySqlSourceDriver.h"

namespace Cloude {
    namespace SourceDriver {
        namespace MySql {

            using Field = Foundation::Field;
            using Column = Foundation::Column;
            using Entity = Foundation::Entity;
            using ColumnsList = std::vector<std::shared_ptr<Column>>;

            class Command {

            public:
                Command() {
                    //
                };

                virtual ~Command() {

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

            class MySqlSourceDriver::MySqlApiImpl {
            public:
                MYSQL *PtrMySql = nullptr;

            public:
                MySqlApiImpl() {
                    mysql_library_init;
                    PtrMySql = mysql_init(PtrMySql);
                }

                ~MySqlApiImpl() {

                    if (PtrMySql != nullptr) {
                        mysql_close(PtrMySql);
                    }

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
                        auto errorCharPtr = mysql_error(PtrMySql);
                        throw MySqlSourceException(errorCharPtr);
                    }
                }

                void assertStmtError(MYSQL_STMT *ptrMySqlStmt) {
                    if (mysql_stmt_errno(ptrMySqlStmt)) {
                        auto errorCharPtr = mysql_stmt_error(ptrMySqlStmt);
                        throw MySqlSourceException(errorCharPtr);
                    }
                }

                void initializeParamsBindBuffers(std::shared_ptr<Entity> &entity,
                                                 const ColumnsList &columnsList,
                                                 std::shared_ptr<Command> &command) {

                    auto columnsListSize = columnsList.size();

                    command->PtrParamsBind = (MYSQL_BIND *) calloc(columnsListSize, sizeof(MYSQL_BIND));
                    command->PtrParamsLength = (unsigned long *) calloc(columnsListSize, sizeof(unsigned long));

                    int index = 0;

                    std::for_each(columnsList.cbegin(), columnsList.cend(),
                                  [&](const std::shared_ptr<Column> &column) -> void {

                                      auto &field = entity->operator[](column->getName());
                                      auto &value = field->getValue();

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

                                      setupBindBufferTypeAndLength(field, &command->PtrParamsBind[index]);

                                      ++index;
                                  });
                }

                void initializeResultBindBuffers(std::shared_ptr<Entity> &entity,
                                                 const ColumnsList &columnsList,
                                                 std::shared_ptr<Command> &command) {

                    using cldeFactory = Foundation::Type::cldeValueFactory;

                    auto columnsListSize = columnsList.size();

                    command->PtrResultBind = (MYSQL_BIND *) calloc(columnsListSize, sizeof(MYSQL_BIND));
                    command->PtrResultError = (my_bool *) calloc(columnsListSize, sizeof(my_bool));
                    command->PtrResultIsNull = (my_bool *) calloc(columnsListSize, sizeof(my_bool));
                    command->PtrResultLength = (unsigned long *) calloc(columnsListSize, sizeof(unsigned long));

                    int index = 0;

                    std::for_each(columnsList.cbegin(), columnsList.cend(),
                                  [&](const std::shared_ptr<Column> &column) -> void {

                                      auto &field = entity->operator[](column->getName());

                                      switch (column->getDataType()) {
                                          case Foundation::Type::cldeValueType::Int64:
                                              field->setValue(cldeFactory::CreateInt64(0));
                                              break;
                                          case Foundation::Type::cldeValueType::Varchar:
                                              field->setValue(cldeFactory::CreateVarchar(column->getLength()));
                                              break;
                                          default:
                                              const char *msg = "MySqlSourceDriver does not support this type.";
                                              throw Foundation::Exception::cldeNonSupportedDataTypeException(msg);
                                      }

                                      auto &value = field->getValue();
                                      auto ptrValue = value->RawPointerToValueBuffer();

                                      command->PtrResultBind[index].is_null = &command->PtrResultIsNull[index];
                                      command->PtrResultBind[index].error = &command->PtrResultError[index];
                                      command->PtrResultBind[index].length = &command->PtrResultLength[index];
                                      command->PtrResultBind[index].buffer = ptrValue;

                                      setupBindBufferTypeAndLength(field, &command->PtrResultBind[index]);

                                      ++index;
                                  });
                }

                void setupBindBufferTypeAndLength(const std::shared_ptr<Field> &field,
                                                  MYSQL_BIND *ptrBind) {
                    switch (field->getColumn()->getDataType()) {
                        case Foundation::Type::cldeValueType::Int32:
                            ptrBind->buffer_type = MYSQL_TYPE_LONG;
                            ptrBind->buffer_length = sizeof(int32_t);
                            break;
                        case Foundation::Type::cldeValueType::Int64:
                            ptrBind->buffer_type = MYSQL_TYPE_LONGLONG;
                            ptrBind->buffer_length = sizeof(int64_t);
                            break;
                        case Foundation::Type::cldeValueType::Double:
                            ptrBind->buffer_type = MYSQL_TYPE_DOUBLE;
                            ptrBind->buffer_length = sizeof(double);
                            break;
                        case Foundation::Type::cldeValueType::Varchar:
                            ptrBind->buffer_type = MYSQL_TYPE_STRING;
                            ptrBind->buffer_length = field->getColumn()->getLength();
                            break;
                        default:
                            const char *msg = "MySqlSourceDriver does not support this type yet.";
                            throw Foundation::Exception::cldeNonSupportedDataTypeException(msg);
                    }
                }
            }; // END - MySqlApiImpl

            MySqlSourceDriver::MySqlSourceDriver(const Foundation::EntityMap &entityMap)
                    : EntitySourceDriver(entityMap),
                      _mySqlApiImpl(new MySqlApiImpl()) {
                Init();
            }

            MySqlSourceDriver::~MySqlSourceDriver() {

            }

            void MySqlSourceDriver::Init() {

                auto fpInsert = [](const std::shared_ptr<Column> &column,
                                   int position) -> std::string {
                    std::string condition = "?";
                    return condition;
                };

                auto fpCondition = [](const std::shared_ptr<Column> &column,
                                      int position) -> std::string {
                    std::string condition = column->getDatasourceName() + " = ?";
                    return condition;
                };

                _getStatement = Foundation::Helper::CreateGetPreparedQuery(_entityMap, fpCondition);
                _insertStatement = Foundation::Helper::CreateInsertPreparedQuery(_entityMap, fpInsert);
                _updateStatement = Foundation::Helper::CreateUpdatePreparedQuery(_entityMap, fpCondition);
                _deleteStatement = Foundation::Helper::CreateDeletePreparedQuery(_entityMap, fpCondition);
            }

            void MySqlSourceDriver::Connect() {

                if (_mySqlApiImpl->PtrMySql == nullptr) {
                    _mySqlApiImpl->assertSqlError();
                }

                // TODO: To research the use of mysql_options();
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

            int MySqlSourceDriver::Load(std::shared_ptr<Entity> &entity) const {

                auto command = _mySqlApiImpl->createCommand(_getStatement);

                _mySqlApiImpl->initializeParamsBindBuffers(entity, _entityMap.getColumnsForKey(), command);
                _mySqlApiImpl->initializeResultBindBuffers(entity, _entityMap.getColumnsForGet(), command);

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
                        // TODO: To research MYSQL_DATA_TRUNCATED condition
                        _mySqlApiImpl->assertSqlError();
                        _mySqlApiImpl->assertStmtError(command->PtrStmt);
                        throw MySqlSourceException("fetch error: MYSQL_DATA_TRUNCATED");
                    default:
                        throw MySqlSourceException("fetch error: unknown return status code");
                }

                return 0;
            }

            int MySqlSourceDriver::Insert(std::shared_ptr<Entity> &entity) const {

                std::shared_ptr<Command> command = _mySqlApiImpl->createCommand(_insertStatement);

                _mySqlApiImpl->initializeParamsBindBuffers(entity, _entityMap.getColumnsForKey(), command);

                if (mysql_stmt_bind_param(command->PtrStmt, command->PtrParamsBind)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                if (mysql_stmt_execute(command->PtrStmt)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                return 1;
            }

            int MySqlSourceDriver::Save(std::shared_ptr<Entity> &entity) const {

                auto command = _mySqlApiImpl->createCommand(_updateStatement);
                auto &columnsForKey = _entityMap.getColumnsForKey();
                auto &columnsForUpdate = _entityMap.getColumnsForUpdate();

                ColumnsList joinedColumnsList;
                joinedColumnsList.insert(joinedColumnsList.end(), columnsForUpdate.begin(), columnsForUpdate.end());
                joinedColumnsList.insert(joinedColumnsList.end(), columnsForKey.begin(), columnsForKey.end());

                _mySqlApiImpl->initializeParamsBindBuffers(entity, joinedColumnsList, command);

                if (mysql_stmt_bind_param(command->PtrStmt, command->PtrParamsBind)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                if (mysql_stmt_execute(command->PtrStmt)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                return 1;
            }

            int MySqlSourceDriver::Delete(std::shared_ptr<Entity> &entity) const {

                auto command = _mySqlApiImpl->createCommand(_deleteStatement);

                _mySqlApiImpl->initializeParamsBindBuffers(entity, _entityMap.getColumnsForKey(), command);

                if (mysql_stmt_bind_param(command->PtrStmt, command->PtrParamsBind)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                if (mysql_stmt_execute(command->PtrStmt)) {
                    _mySqlApiImpl->assertStmtError(command->PtrStmt);
                }

                return 1;
            }

            MySqlSourceDriver::SPtrProxySPtrVector MySqlSourceDriver::Select(
                    const Foundation::EntitySourceDriver::SPtrPredicate &predicate,
                    Foundation::EntityStore &entityStore) const {

                SPtrProxySPtrVector proxies;

                return proxies;
            }
        }
    }
}