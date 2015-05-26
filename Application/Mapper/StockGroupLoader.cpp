//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupLoader.h"
#include "../../Architecture/Exception/NonSupportedDataTypeException.h"

using namespace std;
using namespace Cloude::Architecture;

namespace Cloude {
    namespace Application {
        namespace Mapper {

            StockGroupLoader::StockGroupLoader() {

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

                // Execute

                // Load Entity
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

                _ptrMySqlBind = (MYSQL_BIND *) calloc(columnsMap.size(), sizeof(MYSQL_BIND));
                _ptrIsNull = (my_bool *) calloc(columnsMap.size(), sizeof(my_bool));
                _ptrError = (my_bool *) calloc(columnsMap.size(), sizeof(my_bool));
                _ptrLength = (unsigned long *) calloc(columnsMap.size(), sizeof(unsigned long));

                int i = 0;

                for (auto item : columnsMap) {

                    auto column = item.second;
                    auto field = entity->operator[](column.getName());

                    setup_field(field, &_ptrMySqlBind[i]);

                    i++;
                }
            }

            void StockGroupLoader::setup_field(std::shared_ptr<Field> &field, MYSQL_BIND *ptrBind) {

                switch (field->getColumn()->getDbType()) {

                    case Enumeration::DbType::Boolean:
                        ptrBind->buffer_type = MYSQL_TYPE_BIT;
                        break;
                    case Enumeration::DbType::Byte:
                        ptrBind->buffer_type = MYSQL_TYPE_BIT;
                        break;
                    case Enumeration::DbType::Int16:
                        ptrBind->buffer_type = MYSQL_TYPE_SHORT;
                        break;
                    case Enumeration::DbType::Int32:
                        ptrBind->buffer_type = MYSQL_TYPE_INT24;
                        break;
                    case Enumeration::DbType::Int64:
                        ptrBind->buffer_type = MYSQL_TYPE_LONG;
                        break;
                    case Enumeration::DbType::Double:
                        ptrBind->buffer_type = MYSQL_TYPE_DOUBLE;
                        break;
                    case Enumeration::DbType::Float:
                        ptrBind->buffer_type = MYSQL_TYPE_FLOAT;
                        break;
                    case Enumeration::DbType::String:
                        ptrBind->buffer_type = MYSQL_TYPE_STRING;
                        ptrBind->buffer_length = field->getColumn()->getLength();
                        break;
                    default:
                        throw Exception::NonSupportedDataTypeException();
                }
            }
        }
    }
}
