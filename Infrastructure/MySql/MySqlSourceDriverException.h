//
// Created by LE, Duc Anh on 5/29/15.
//

#ifndef CLOUD_E_CPLUS_MYSQLSOURCEDRIVEREXCEPTION_H
#define CLOUD_E_CPLUS_MYSQLSOURCEDRIVEREXCEPTION_H

#include <exception>
#include <string>

namespace Cloude {
    namespace Infrastructure {
        namespace MySql {
            class MySqlSourceDriverException : public std::exception {
            public:
                MySqlSourceDriverException() = default;
                virtual ~MySqlSourceDriverException() = default;
                MySqlSourceDriverException(const MySqlSourceDriverException &srcMySqlDriverException) = default;
                MySqlSourceDriverException &operator=(const MySqlSourceDriverException &srcMySqlDriverException) = default;

                explicit MySqlSourceDriverException(const std::string &sstrMessage);
                explicit MySqlSourceDriverException(const char *cstrMessage);
                virtual const char *what() const noexcept override;

            private:
                std::string _message;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_MYSQLSOURCEDRIVEREXCEPTION_H
