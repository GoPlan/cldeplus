//
// Created by GoPlan on 18/05/2015.
//

#include <Architecture/Exception/NonSupportedDataTypeException.h>
#include "MySqlDriver.h"

using namespace std;
using namespace Cloude;

namespace Cloude {
    namespace Infrastructure {

        MySqlDriver::~MySqlDriver() {

            if (_ptrMySqlResultBind != nullptr) {
                free(_ptrMySqlResultBind);
            }

            if (_ptrMySqlStmt != nullptr) {
                mysql_stmt_close(_ptrMySqlStmt);
            }

            if (_ptrMySql != nullptr) {
                mysql_close(_ptrMySql);
            }
        }

        int MySqlDriver::LoadEntity(shared_ptr<Architecture::Entity> &entity, const ColumnsMap &columnsMap) {

            // TODO: Validate MySQL initialization errors

            if (_ptrMySql == nullptr) {

                mysql_library_init;

                _ptrMySql = mysql_init(_ptrMySql);
                _ptrMySql = mysql_real_connect(_ptrMySql,
                                               _host.c_str(),
                                               _user.c_str(),
                                               _pass.c_str(),
                                               _dbase.c_str(),
                                               _port,
                                               NULL, 0);

                assert_sql_error();
            }

            if (_ptrMySqlStmt == nullptr) {
                _ptrMySqlStmt = mysql_stmt_init(_ptrMySql);
                assert_sql_stmt_error();
            }

            if (mysql_stmt_prepare(_ptrMySqlStmt, _query.c_str(), _query.length())) {
                assert_sql_stmt_error();
            }

            // Bind Result & Params
            bind_params(entity, columnsMap);
            bind_result(entity, columnsMap);

            // Bind Result
            if (mysql_stmt_bind_result(_ptrMySqlStmt, _ptrMySqlResultBind)) {
                assert_sql_error();
                assert_sql_stmt_error();
            }

            // Fetch result & Load entity
            auto rowStatus = mysql_stmt_fetch(_ptrMySqlStmt);

            switch (rowStatus) {
                case 0:
                    return 1;
                case 1:
                    // TODO: To throws a proper exception
                    break;
                case MYSQL_NO_DATA:
                    return 0;
                case MYSQL_DATA_TRUNCATED:
                    // TODO: To throws a proper exception
                    break;
                default:
                    // TODO: To throws a proper exception
                    break;
            }

            return 0;
        }

        int MySqlDriver::InsertEntity(shared_ptr<Architecture::Entity> &entity, const ColumnsMap &columnsMap) {
            return 0;
        }

        void MySqlDriver::assert_sql_error() {
            if (mysql_errno(_ptrMySql)) {
                auto errorCharPtr = mysql_error(_ptrMySql);
                fprintf(stdout, "%s", errorCharPtr);
                exit(EXIT_FAILURE);
            }
        }

        void MySqlDriver::assert_sql_stmt_error() {
            if (mysql_stmt_errno(_ptrMySqlStmt)) {
                auto errorCharPtr = mysql_stmt_error(_ptrMySqlStmt);
                fprintf(stdout, "%s", errorCharPtr);
                exit(EXIT_FAILURE);
            }
        }

        void MySqlDriver::bind_params(std::shared_ptr<Entity> &entity, const ColumnsMap &columnsMap) {

        }

        void MySqlDriver::bind_result(std::shared_ptr<Entity> &entity, const ColumnsMap &columnsMap) {

            auto columnsMapSize = columnsMap.size();

            _ptrMySqlResultBind = (MYSQL_BIND *) calloc(columnsMapSize, sizeof(MYSQL_BIND));
            _ptrIsNull = (my_bool *) calloc(columnsMapSize, sizeof(my_bool));
            _ptrError = (my_bool *) calloc(columnsMapSize, sizeof(my_bool));
            _ptrLength = (unsigned long *) calloc(columnsMapSize, sizeof(unsigned long));

            int i = 0;

            for (auto item : columnsMap) {

                auto column = item.second;
                auto field = entity->operator[](column->getName());
                auto mySqlBind = _ptrMySqlResultBind[i];

                setup_field(field, &mySqlBind);

                i++;
            }
        }

        void MySqlDriver::setup_field(std::shared_ptr<Field> &field, MYSQL_BIND *ptrBind) {

            field->AssignDataPointer(ptrBind->buffer);

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
                    ptrBind->buffer_type = MYSQL_TYPE_VARCHAR;
                    ptrBind->buffer_length = field->getColumn()->getLength();
                    break;
                default:
                    throw Architecture::Exception::NonSupportedDataTypeException();
            }
        }
    }
}