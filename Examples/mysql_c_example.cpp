//
// Created by LE, Duc-Anh on 5/22/15.
//

#include "mysql_c_example.h"

namespace Cloude {
    namespace Examples {

        MySqlExample::MySqlExample() {
            port = 3306;
            host = "192.168.10.103";
            user = "cloud-e";
            pass = "cloud-e";
            schema = "cloud-e";
            query = "SELECT id, uniquename, accounttype, email FROM account";

            result_bind_ptr = new MYSQL_BIND[4];
        }

        MySqlExample::~MySqlExample() {

        }

        void MySqlExample::Run() {

            mysql_library_init;

            mysql_ptr = mysql_init(mysql_ptr);
            mysql_ptr = mysql_real_connect(mysql_ptr,
                                           host.c_str(),
                                           user.c_str(),
                                           pass.c_str(),
                                           schema.c_str(),
                                           port,
                                           NULL, 0);
            assert_error();

            mysql_stmt_ptr = mysql_stmt_init(mysql_ptr);
            assert_error();

            if (mysql_stmt_prepare(mysql_stmt_ptr, query.c_str(), query.length())) {
                assert_stmt_error();
            }

            if (mysql_stmt_execute(mysql_stmt_ptr)) {
                assert_stmt_error();
            }

            setup_bind();

            if (mysql_stmt_bind_result(mysql_stmt_ptr, result_bind_ptr)) {
                assert_error();
                assert_stmt_error();
            }

            mysql_stmt_store_result(mysql_stmt_ptr);

            auto row_count = mysql_stmt_num_rows(mysql_stmt_ptr);

            fprintf(stdout, "Row count = %llu\n", row_count);
            fprintf(stdout, "Fetching result ... \n");

            FETCH:
            auto row_status = mysql_stmt_fetch(mysql_stmt_ptr);

            switch (row_status) {
                case 0:
                    is_printing = true;
                    goto PRINT;
                case 1:
                    assert_error();
                    assert_stmt_error();
                    goto EXIT;
                case MYSQL_NO_DATA:
                    fprintf(stdout, "No data\n");
                    goto EXIT;
                case MYSQL_DATA_TRUNCATED:
                    fprintf(stdout, "Truncated data\n");
                    assert_error();
                    assert_stmt_error();
                    goto EXIT;
                default:
                    goto EXIT;
            }

            PRINT:
            if (is_printing) {

                if (id_isnull) {
                    fprintf(stdout, "NULL");
                } else {
                    fprintf(stdout, "%ld(%ld)", id_buffer, id_length);
                }

                fprintf(stdout, "\t");

                if (uniquename_isnull) {
                    fprintf(stdout, "NULL");
                } else {
                    fprintf(stdout, "%s(%ld)", uniquename_buffer, uniquename_length);
                }

                fprintf(stdout, "\t");

                if (accounttype_isnull) {
                    fprintf(stdout, "NULL");
                } else {
                    fprintf(stdout, "%s(%ld)", accounttype_buffer, accounttype_length);
                }

                fprintf(stdout, "\t");

                if (email_isnull) {
                    fprintf(stdout, "NULL");
                } else {
                    fprintf(stdout, "%s(%ld)", email_buffer, email_length);
                }

                fprintf(stdout, "\t");
                fprintf(stdout, "\n");

                is_printing = false;

                goto FETCH;
            }

            EXIT:
            mysql_stmt_close(mysql_stmt_ptr);
            mysql_close(mysql_ptr);
        }

        void MySqlExample::assert_error() {
            if (mysql_errno(mysql_ptr)) {
                auto errorCharPtr = mysql_error(mysql_ptr);
                fprintf(stdout, "%s", errorCharPtr);
                exit(EXIT_FAILURE);
            }
        }

        void MySqlExample::assert_stmt_error() {
            if (mysql_stmt_errno(mysql_stmt_ptr)) {
                auto errorCharPtr = mysql_stmt_error(mysql_stmt_ptr);
                fprintf(stdout, "%s", errorCharPtr);
                exit(EXIT_FAILURE);
            }
        }

        void MySqlExample::setup_bind() {
            memset(result_bind_ptr, 0, sizeof(MYSQL_BIND) * 4);

            result_bind_ptr[0].buffer_type = MYSQL_TYPE_LONG;
            result_bind_ptr[0].buffer = &id_buffer;
            result_bind_ptr[0].buffer_length = sizeof(long);
            result_bind_ptr[0].error = &id_error;
            result_bind_ptr[0].is_null = &id_isnull;
            result_bind_ptr[0].length = &id_length;

            result_bind_ptr[1].buffer_type = MYSQL_TYPE_STRING;
            result_bind_ptr[1].buffer = (char *) &uniquename_buffer;
            result_bind_ptr[1].buffer_length = 255;
            result_bind_ptr[1].error = &uniquename_error;
            result_bind_ptr[1].is_null = &uniquename_isnull;
            result_bind_ptr[1].length = &uniquename_length;

            result_bind_ptr[2].buffer_type = MYSQL_TYPE_STRING;
            result_bind_ptr[2].buffer = (char *) &accounttype_buffer;
            result_bind_ptr[2].buffer_length = 255;
            result_bind_ptr[2].error = &accounttype_error;
            result_bind_ptr[2].is_null = &accounttype_isnull;
            result_bind_ptr[2].length = &accounttype_length;

            result_bind_ptr[3].buffer_type = MYSQL_TYPE_STRING;
            result_bind_ptr[3].buffer = (char *) &email_buffer;
            result_bind_ptr[3].buffer_length = 255;
            result_bind_ptr[3].error = &email_error;
            result_bind_ptr[3].is_null = &email_isnull;
            result_bind_ptr[3].length = &email_length;
        }
    }
}
