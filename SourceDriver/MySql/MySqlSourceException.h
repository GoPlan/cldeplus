//
// Created by LE, Duc Anh on 5/29/15.
//

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_MYSQL_MYSQLSOURCEDEXCEPTION_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_MYSQL_MYSQLSOURCEDEXCEPTION_H

#include <exception>
#include <string>

namespace Cloude {
    namespace SourceDriver {
        namespace MySql {
            class MySqlSourceException : public std::exception {
            public:
                MySqlSourceException() = default;
                virtual ~MySqlSourceException() = default;
                MySqlSourceException(const MySqlSourceException &srcMySqlDriverException) = default;
                MySqlSourceException &operator=(const MySqlSourceException &srcMySqlDriverException) = default;

                explicit MySqlSourceException(const std::string &sstrMessage);
                explicit MySqlSourceException(const char *cstrMessage);
                virtual const char *what() const noexcept override;

            private:
                std::string _message;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_SOURCEDRIVER_MYSQL_MYSQLSOURCEDEXCEPTION_H
