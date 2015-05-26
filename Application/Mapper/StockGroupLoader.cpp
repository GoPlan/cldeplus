//
// Created by GoPlan on 15/05/2015.
//

#include <random>
#include "StockGroupLoader.h"
#include "../../Architecture/Exception/NonSupportedDataTypeException.h"

using namespace std;
using namespace Cloude::Architecture;

namespace Cloude {
    namespace Application {
        namespace Mapper {

            StockGroupLoader::StockGroupLoader(const unordered_map<string, shared_ptr<Column>> &columnsMap) :
                    _columnsMap(columnsMap) {
                //
            }

            StockGroupLoader::~StockGroupLoader() {

                if (_ptrMySqlBind != nullptr) {
                    free(_ptrMySqlBind);
                }

                if (_ptrMySqlStmt != nullptr) {
                    mysql_stmt_close(_ptrMySqlStmt);
                }

                if (_ptrMySql != nullptr) {
                    mysql_close(_ptrMySql);
                }

            }

            std::unique_ptr<Identity> StockGroupLoader::NextPrimaryKey() {
                return std::unique_ptr<Identity>(nullptr);
            }

            void StockGroupLoader::LoadEntity(std::shared_ptr<Identity> &identity) {

                if (_ptrMySql == nullptr) {
                    // TODO: Validate MySQL initialization errors
                    mysql_library_init;
                    mysql_init(_ptrMySql);
                    mysql_real_connect(_ptrMySql,
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

                auto spEntity = identity->getEntity();

                // Bind Params
                setup_bind(spEntity);

                // Bind Result
                if (mysql_stmt_bind_result(_ptrMySqlStmt, _ptrMySqlBind)) {
                    assert_sql_error();
                    assert_sql_stmt_error();
                }

                // Fetch result & Load entity
                auto rowStatus = mysql_stmt_fetch(_ptrMySqlStmt);

                switch (rowStatus) {
                    case 0:
                        break;
                    case 1:
                        break;
                    case MYSQL_NO_DATA:
                        break;
                    case MYSQL_DATA_TRUNCATED:
                        break;
                    default:
                        break;
                }
            }

            void StockGroupLoader::assert_sql_error() {
                if (mysql_errno(_ptrMySql)) {
                    auto errorCharPtr = mysql_error(_ptrMySql);
                    fprintf(stdout, "%s", errorCharPtr);
                    exit(EXIT_FAILURE);
                }
            }

            void StockGroupLoader::assert_sql_stmt_error() {
                if (mysql_stmt_errno(_ptrMySqlStmt)) {
                    auto errorCharPtr = mysql_stmt_error(_ptrMySqlStmt);
                    fprintf(stdout, "%s", errorCharPtr);
                    exit(EXIT_FAILURE);
                }
            }

            void StockGroupLoader::setup_bind(shared_ptr<Entity> &entity) {

                _ptrMySqlBind = (MYSQL_BIND *) calloc(_columnsMap.size(), sizeof(MYSQL_BIND));
                _ptrIsNull = (my_bool *) calloc(_columnsMap.size(), sizeof(my_bool));
                _ptrError = (my_bool *) calloc(_columnsMap.size(), sizeof(my_bool));
                _ptrLength = (unsigned long *) calloc(_columnsMap.size(), sizeof(unsigned long));

                int i = 0;

                for (auto item : _columnsMap) {

                    auto column = item.second;
                    auto field = entity->operator[](column->getName());

                    setup_field(field, &_ptrMySqlBind[i]);

                    i++;
                }
            }

            void StockGroupLoader::setup_field(std::shared_ptr<Field> &field, MYSQL_BIND *ptrBind) {

                field->AssignDataPointer(ptrBind->buffer);

                switch (field->getColumn()->getDbType()) {
                    case Enumeration::DbType::Boolean:
                        ptrBind->buffer_type = MYSQL_TYPE_TINY;
                        ptrBind->buffer_length = sizeof(bool);
                        break;
                    case Enumeration::DbType::Byte:
                        ptrBind->buffer_type = MYSQL_TYPE_TINY;
                        ptrBind->buffer_length = sizeof(char);
                        break;
                    case Enumeration::DbType::Int16:
                        ptrBind->buffer_type = MYSQL_TYPE_SHORT;
                        ptrBind->buffer_length = sizeof(int16_t);
                        break;
                    case Enumeration::DbType::Int32:
                        ptrBind->buffer_type = MYSQL_TYPE_LONG;
                        ptrBind->buffer_length = sizeof(int32_t);
                        break;
                    case Enumeration::DbType::Int64:
                        ptrBind->buffer_type = MYSQL_TYPE_LONGLONG;
                        ptrBind->buffer_length = sizeof(int64_t);
                        break;
                    case Enumeration::DbType::UInt16:
                        ptrBind->buffer_type = MYSQL_TYPE_SHORT;
                        ptrBind->buffer_length = sizeof(int16_t);
                        break;
                    case Enumeration::DbType::UInt32:
                        ptrBind->buffer_type = MYSQL_TYPE_LONG;
                        ptrBind->buffer_length = sizeof(int16_t);
                        break;
                    case Enumeration::DbType::UInt64:
                        ptrBind->buffer_type = MYSQL_TYPE_LONGLONG;
                        ptrBind->buffer_length = sizeof(int16_t);
                        break;
                    case Enumeration::DbType::Double:
                        ptrBind->buffer_type = MYSQL_TYPE_DOUBLE;
                        ptrBind->buffer_length = sizeof(double);
                        break;
                    case Enumeration::DbType::Float:
                        ptrBind->buffer_type = MYSQL_TYPE_FLOAT;
                        ptrBind->buffer_length = sizeof(float);
                        break;
                    case Enumeration::DbType::String:
                        ptrBind->buffer_type = MYSQL_TYPE_VARCHAR;
                        ptrBind->buffer_length = field->getColumn()->getLength();
                        break;
                    default:
                        throw Exception::NonSupportedDataTypeException();
                }
            }

            void StockGroupLoader::setup_query() {
                string strColumns;
                string strCondition;
                string strTableName;

                _query.clear();

                _query += " SELECT " + strColumns;
                _query += " FROM " + strTableName;
                _query += " WHERE " + strCondition;
            }
        }
    }
}
