//
// Created by LE, Duc-Anh on 5/22/15.
//

#ifndef CLOUD_E_CPLUS_MYSQL_C_EXAMPLE_H
#define CLOUD_E_CPLUS_MYSQL_C_EXAMPLE_H

#include <string>
#include "mysql.h"

namespace Cloude {
    namespace Examples {

        class MySqlExample {
        public:
            MySqlExample();
            ~MySqlExample();

            void Run();

        private:
            MYSQL *mysql_ptr;
            MYSQL_STMT *mysql_stmt_ptr;
            MYSQL_BIND result_bind[4];

            bool is_printing;
            unsigned long id_length, uniquename_length, accounttype_length, email_length;
            long id_buffer;
            char uniquename_buffer[255];
            char accounttype_buffer[255];
            char email_buffer[255];
            my_bool id_isnull, accounttype_isnull, uniquename_isnull, email_isnull;
            my_bool id_error, accounttype_error, uniquename_error, email_error;

            // Connection Details
            unsigned int port;
            std::string host;
            std::string user;
            std::string pass;
            std::string schema;
            std::string query;

            void assert_error();
            void assert_stmt_error();
            void setup_bind();
        };
    }
}


#endif //CLOUD_E_CPLUS_MYSQL_C_EXAMPLE_H
