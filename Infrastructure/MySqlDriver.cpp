//
// Created by GoPlan on 18/05/2015.
//

#include <Architecture/Exception/NonSupportedDataTypeException.h>
#include <ostream>
#include <iostream>
#include <Infrastructure/Exception/MySqlDriverException.h>
#include "MySqlDriver.h"

using namespace std;
using namespace Cloude;

namespace Cloude {
    namespace Infrastructure {

        MySqlDriver::~MySqlDriver() {

            if (_ptrResultLength != nullptr) {
                free(_ptrResultLength);
            }

            if (_ptrResultIsNull != nullptr) {
                free(_ptrResultIsNull);
            }

            if (_ptrResultError != nullptr) {
                free(_ptrResultError);
            }

            if (_ptrMySqlParamsBind != nullptr) {
                free(_ptrMySqlParamsBind);
            }

            if (_ptrMySqlResultBind != nullptr) {
                free(_ptrMySqlResultBind);
            }

            if (_ptrMySqlStmt != nullptr) {
                mysql_stmt_close(_ptrMySqlStmt);
            }

            if (_ptrMySql != nullptr) {
                mysql_close(_ptrMySql);
            }

            mysql_library_end;
        }

        int MySqlDriver::LoadEntity(shared_ptr<Architecture::Entity> &entity, const EntityMap &entityMap) {

            if (_ptrMySql == nullptr) {

                mysql_library_init;

                _ptrMySql = mysql_init(_ptrMySql);

                if (!_ptrMySql) {
                    assertSqlError();
                }

                // TODO: To research the use of mysql_options();
                if (!mysql_real_connect(_ptrMySql,
                                        _host.c_str(),
                                        _user.c_str(),
                                        _pass.c_str(),
                                        _dbase.c_str(),
                                        _port,
                                        NULL, 0)) {
                    assertSqlError();
                }
            }

            if (_ptrMySqlStmt == nullptr && (_ptrMySqlStmt = mysql_stmt_init(_ptrMySql))) {
                assertSqlStmtError();
            }

            if (mysql_stmt_prepare(_ptrMySqlStmt, _query.c_str(), _query.length())) {
                assertSqlStmtError();
            }

            assignBindParamsBuffer(entity, (ColumnsList) entityMap.getColumnsForKey());
            assignBindresultBuffer(entity, (ColumnsList) entityMap.getColumnsForGet());

            if (mysql_stmt_bind_param(_ptrMySqlStmt, _ptrMySqlParamsBind)) {
                assertSqlStmtError();
            }

            if (mysql_stmt_bind_result(_ptrMySqlStmt, _ptrMySqlResultBind)) {
                assertSqlStmtError();
            }

            if (mysql_stmt_execute(_ptrMySqlStmt)) {
                assertSqlStmtError();
            }

            auto rowStatus = mysql_stmt_fetch(_ptrMySqlStmt);

            switch (rowStatus) {
                case 0:
                    return 1;
                case 1:
                    assertSqlError();
                    assertSqlStmtError();
                    break;
                case MYSQL_NO_DATA:
                    return 0;
                case MYSQL_DATA_TRUNCATED:
                    // TODO: To research MYSQL_DATA_TRUNCATED condition
                    throw Exception::MySqlDriverException("fetch error: MYSQL_DATA_TRUNCATED");
                default:
                    throw Exception::MySqlDriverException("fetch error: unknown return status code");
            }

            return 0;
        }

        int MySqlDriver::InsertEntity(shared_ptr<Architecture::Entity> &entity, const EntityMap &entityMap) {
            return 0;
        }

        void MySqlDriver::assertSqlError() {
            if (mysql_errno(_ptrMySql)) {
                auto errorCharPtr = mysql_error(_ptrMySql);
                throw Exception::MySqlDriverException(errorCharPtr);
            }
        }

        void MySqlDriver::assertSqlStmtError() {
            if (mysql_stmt_errno(_ptrMySqlStmt)) {
                auto errorCharPtr = mysql_stmt_error(_ptrMySqlStmt);
                throw Exception::MySqlDriverException(errorCharPtr);
            }
        }

        void MySqlDriver::assignBindParamsBuffer(std::shared_ptr<Entity> &entity, const ColumnsList &columnsList) {

            auto columnsListSize = columnsList.size();

            _ptrMySqlParamsBind = (MYSQL_BIND *) calloc(columnsListSize, sizeof(MYSQL_BIND));
            _ptrParamsLength = (unsigned long *) calloc(columnsListSize, sizeof(unsigned long));

            int i = 0;

            std::for_each(columnsList.cbegin(), columnsList.cend(),
                          [&](const std::shared_ptr<Column> &column) -> void {

                              auto field = entity->operator[](column->getName());
                              auto ptrLength = static_cast<unsigned long *>(field->getColumn()
                                                                                 ->PointerToLengthVariable());

                              _ptrMySqlParamsBind[i].is_null = 0;
                              _ptrMySqlParamsBind[i].error = 0;
                              _ptrMySqlParamsBind[i].length = ptrLength;
                              _ptrMySqlParamsBind[i].buffer = field->PointerToFieldValue();

                              setupBindBufferDataTypeAndLength(field, &_ptrMySqlParamsBind[i]);

                              i++;
                          });
        }

        void MySqlDriver::assignBindresultBuffer(std::shared_ptr<Entity> &entity, const ColumnsList &columnsList) {

            auto columnsListSize = columnsList.size();

            _ptrMySqlResultBind = (MYSQL_BIND *) calloc(columnsListSize, sizeof(MYSQL_BIND));
            _ptrResultIsNull = (my_bool *) calloc(columnsListSize, sizeof(my_bool));
            _ptrResultError = (my_bool *) calloc(columnsListSize, sizeof(my_bool));
            _ptrResultLength = (unsigned long *) calloc(columnsListSize, sizeof(unsigned long));

            int i = 0;

            std::for_each(columnsList.cbegin(), columnsList.cend(),
                          [&](const std::shared_ptr<Column> &column) -> void {

                              auto field = entity->operator[](column->getName());

                              _ptrMySqlResultBind[i].is_null = &_ptrResultIsNull[i];
                              _ptrMySqlResultBind[i].error = &_ptrResultIsNull[i];
                              _ptrMySqlResultBind[i].length = &_ptrResultLength[i];
                              _ptrMySqlResultBind[i].buffer = field->PointerToFieldValue();

                              setupBindBufferDataTypeAndLength(field, &_ptrMySqlResultBind[i]);

                              i++;
                          });
        }

        void MySqlDriver::setupBindBufferDataTypeAndLength(std::shared_ptr<Field> &field, MYSQL_BIND *ptrBind) {

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
    }
}