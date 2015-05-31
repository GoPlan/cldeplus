//
// Created by GoPlan on 18/05/2015.
//

#include <iostream>
#include <mysql.h>
#include <Architecture/Exception/NonSupportedDataTypeException.h>
#include <Architecture/Helper/SqlGenerator.h>
#include "Exception/MySqlDriverException.h"
#include "MySqlSourceDriver.h"

using namespace std;
using namespace Cloude;

namespace Cloude {
    namespace Infrastructure {

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
            MYSQL *_ptrMySql = nullptr;
            MySqlDriverOptions &_driverOptions;

            MySqlApiImpl(MySqlDriverOptions &driverOptions) : _driverOptions(driverOptions) {
                mysql_library_init;
                _ptrMySql = mysql_init(_ptrMySql);
            }

            ~MySqlApiImpl() {

                if (_ptrMySql != nullptr) {
                    mysql_close(_ptrMySql);
                }

                mysql_library_end;
            }

            shared_ptr<Command> createCommand(const string &query) {

                auto command = make_shared<Command>();
                command->PtrStmt = mysql_stmt_init(_ptrMySql);

                if (!command->PtrStmt) {
                    implAssertSqlError();
                }

                if (mysql_stmt_prepare(command->PtrStmt, query.c_str(), query.length())) {
                    implAssertStmtError(command->PtrStmt);
                }

                return command;
            }

            void implAssertSqlError() {
                if (mysql_errno(_ptrMySql)) {
                    auto errorCharPtr = mysql_error(_ptrMySql);
                    throw Exception::MySqlDriverException(errorCharPtr);
                }
            }

            void implAssertStmtError(MYSQL_STMT *ptrMySqlStmt) {
                if (mysql_stmt_errno(ptrMySqlStmt)) {
                    auto errorCharPtr = mysql_stmt_error(ptrMySqlStmt);
                    throw Exception::MySqlDriverException(errorCharPtr);
                }

            }

            void implBindParamsBuffer(std::shared_ptr<Entity> &entity,
                                      const ColumnsList &columnsList,
                                      std::shared_ptr<Command> &command) {

                auto columnsListSize = columnsList.size();

                command->PtrParamsBind = (MYSQL_BIND *) calloc(columnsListSize, sizeof(MYSQL_BIND));
                command->PtrParamsLength = (unsigned long *) calloc(columnsListSize, sizeof(unsigned long));

                int i = 0;

                std::for_each(columnsList.cbegin(), columnsList.cend(),
                              [&](const std::shared_ptr<Column> &column) -> void {

                                  auto field = entity->operator[](column->getName());
                                  auto ptrLength = static_cast<unsigned long *>(field->getColumn()
                                                                                     ->PointerToLengthVariable());

                                  command->PtrParamsBind[i].is_null = 0;
                                  command->PtrParamsBind[i].error = 0;
                                  command->PtrParamsBind[i].length = ptrLength;
                                  command->PtrParamsBind[i].buffer = field->PointerToFieldValue();

                                  implSetupBindBuffers(field, &command->PtrParamsBind[i]);

                                  i++;
                              });
            }

            void implBindResultBuffer(std::shared_ptr<Entity> &entity,
                                      const ColumnsList &columnsList,
                                      std::shared_ptr<Command> &command) {

                auto columnsListSize = columnsList.size();

                command->PtrResultBind = (MYSQL_BIND *) calloc(columnsListSize, sizeof(MYSQL_BIND));
                command->PtrResultError = (my_bool *) calloc(columnsListSize, sizeof(my_bool));
                command->PtrResultIsNull = (my_bool *) calloc(columnsListSize, sizeof(my_bool));
                command->PtrResultLength = (unsigned long *) calloc(columnsListSize, sizeof(unsigned long));

                int i = 0;

                std::for_each(columnsList.cbegin(), columnsList.cend(),
                              [&](const std::shared_ptr<Column> &column) -> void {

                                  auto field = entity->operator[](column->getName());

                                  command->PtrResultBind[i].is_null = &command->PtrResultIsNull[i];
                                  command->PtrResultBind[i].error = &command->PtrResultError[i];
                                  command->PtrResultBind[i].length = &command->PtrResultLength[i];
                                  command->PtrResultBind[i].buffer = field->PointerToFieldValue();

                                  implSetupBindBuffers(field, &command->PtrResultBind[i]);

                                  i++;
                              });
            }

            void implSetupBindBuffers(std::shared_ptr<Field> &field, MYSQL_BIND *ptrBind) {

                switch (field->getColumn()->getDbType()) {
                    case Architecture::Enumeration::DbType::Boolean:
                        ptrBind->buffer_type = MYSQL_TYPE_TINY;
                        ptrBind->buffer_length = sizeof(bool);
                        break;
                    case Architecture::Enumeration::DbType::Byte:
                        ptrBind->buffer_type = MYSQL_TYPE_TINY;
                        ptrBind->buffer_length = sizeof(char);
                        break;
                    case Architecture::Enumeration::DbType::Int16:
                        ptrBind->buffer_type = MYSQL_TYPE_SHORT;
                        ptrBind->buffer_length = sizeof(int16_t);
                        break;
                    case Architecture::Enumeration::DbType::Int32:
                        ptrBind->buffer_type = MYSQL_TYPE_LONG;
                        ptrBind->buffer_length = sizeof(int32_t);
                        break;
                    case Architecture::Enumeration::DbType::Int64:
                        ptrBind->buffer_type = MYSQL_TYPE_LONGLONG;
                        ptrBind->buffer_length = sizeof(int64_t);
                        break;
                    case Architecture::Enumeration::DbType::UInt16:
                        ptrBind->buffer_type = MYSQL_TYPE_SHORT;
                        ptrBind->buffer_length = sizeof(int16_t);
                        break;
                    case Architecture::Enumeration::DbType::UInt32:
                        ptrBind->buffer_type = MYSQL_TYPE_LONG;
                        ptrBind->buffer_length = sizeof(int16_t);
                        break;
                    case Architecture::Enumeration::DbType::UInt64:
                        ptrBind->buffer_type = MYSQL_TYPE_LONGLONG;
                        ptrBind->buffer_length = sizeof(int16_t);
                        break;
                    case Architecture::Enumeration::DbType::Double:
                        ptrBind->buffer_type = MYSQL_TYPE_DOUBLE;
                        ptrBind->buffer_length = sizeof(double);
                        break;
                    case Architecture::Enumeration::DbType::Float:
                        ptrBind->buffer_type = MYSQL_TYPE_FLOAT;
                        ptrBind->buffer_length = sizeof(float);
                        break;
                    case Architecture::Enumeration::DbType::String:
                        ptrBind->buffer_type = MYSQL_TYPE_STRING;
                        ptrBind->buffer_length = field->getColumn()->getLength();
                        break;
                    default:
                        throw Architecture::Exception::NonSupportedDataTypeException();
                }
            }

        }; // END - MySqlApiImpl

        MySqlSourceDriver::MySqlSourceDriver() : _ptrMySqlApiImpl(new MySqlApiImpl(OptionArgs)) {
            //
        }

        MySqlSourceDriver::~MySqlSourceDriver() {
            delete _ptrMySqlApiImpl;
        }

        void MySqlSourceDriver::Connect() {

            if (_ptrMySqlApiImpl->_ptrMySql == nullptr) {
                _ptrMySqlApiImpl->implAssertSqlError();
            }

            // TODO: To research the use of mysql_options();
            if (!mysql_real_connect(_ptrMySqlApiImpl->_ptrMySql,
                                    _ptrMySqlApiImpl->_driverOptions.Host.c_str(),
                                    _ptrMySqlApiImpl->_driverOptions.User.c_str(),
                                    _ptrMySqlApiImpl->_driverOptions.Pass.c_str(),
                                    _ptrMySqlApiImpl->_driverOptions.Base.c_str(),
                                    _ptrMySqlApiImpl->_driverOptions.Port,
                                    NULL, 0)) {

                _ptrMySqlApiImpl->implAssertSqlError();
            }
        }

        void MySqlSourceDriver::Disconnect() {
            //
        }

        void MySqlSourceDriver::LoadEntity(shared_ptr<Architecture::Entity> &entity, const EntityMap &entityMap) {

            auto command = _ptrMySqlApiImpl->createCommand(_getStatement);

            _ptrMySqlApiImpl->implBindParamsBuffer(entity, entityMap.getColumnsForKey(), command);
            _ptrMySqlApiImpl->implBindResultBuffer(entity, entityMap.getColumnsForGet(), command);

            if (mysql_stmt_bind_param(command->PtrStmt, command->PtrParamsBind)) {
                _ptrMySqlApiImpl->implAssertStmtError(command->PtrStmt);
            }

            if (mysql_stmt_bind_result(command->PtrStmt, command->PtrResultBind)) {
                _ptrMySqlApiImpl->implAssertStmtError(command->PtrStmt);
            }

            if (mysql_stmt_execute(command->PtrStmt)) {
                _ptrMySqlApiImpl->implAssertStmtError(command->PtrStmt);
            }

            auto rowStatus = mysql_stmt_fetch(command->PtrStmt);

            switch (rowStatus) {
                case 0:
                    break;
                case 1:
                    _ptrMySqlApiImpl->implAssertSqlError();
                    _ptrMySqlApiImpl->implAssertStmtError(command->PtrStmt);
                    break;
                case MYSQL_NO_DATA:
                    break;
                case MYSQL_DATA_TRUNCATED:
                    // TODO: To research MYSQL_DATA_TRUNCATED condition
                    _ptrMySqlApiImpl->implAssertSqlError();
                    _ptrMySqlApiImpl->implAssertStmtError(command->PtrStmt);
                    throw Exception::MySqlDriverException("fetch error: MYSQL_DATA_TRUNCATED");
                default:
                    throw Exception::MySqlDriverException("fetch error: unknown return status code");
            }
        }

        void MySqlSourceDriver::CreateEntity(shared_ptr<Architecture::Entity> &entity, const EntityMap &entityMap) {

            auto command = _ptrMySqlApiImpl->createCommand(_insertStatement);

            _ptrMySqlApiImpl->implBindParamsBuffer(entity, entityMap.getColumnsForKey(), command);

            if (mysql_stmt_bind_param(command->PtrStmt, command->PtrParamsBind)) {
                _ptrMySqlApiImpl->implAssertStmtError(command->PtrStmt);
            }

            if (mysql_stmt_execute(command->PtrStmt)) {
                _ptrMySqlApiImpl->implAssertStmtError(command->PtrStmt);
            }
        }
    }
}