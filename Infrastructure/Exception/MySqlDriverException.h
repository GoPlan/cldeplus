//
// Created by LE, Duc Anh on 5/29/15.
//

#ifndef CLOUD_E_CPLUS_MYSQLDRIVEREXCEPTION_H
#define CLOUD_E_CPLUS_MYSQLDRIVEREXCEPTION_H

#include <exception>
#include <string>

namespace Cloude {
    namespace Infrastructure {
        namespace Exception {
            class MySqlDriverException : public std::exception {
            public:
                MySqlDriverException() = default;
                virtual ~MySqlDriverException() = default;
                MySqlDriverException(const MySqlDriverException &srcMySqlDriverException) = default;
                MySqlDriverException &operator=(const MySqlDriverException &srcMySqlDriverException) = default;

                explicit MySqlDriverException(const std::string &sstrMessage);
                explicit MySqlDriverException(const char *cstrMessage);
                virtual const char *what() const noexcept override;

            private:
                std::string _message;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_MYSQLDRIVEREXCEPTION_H
