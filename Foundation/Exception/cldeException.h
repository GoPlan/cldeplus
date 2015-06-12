//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEEXCEPTION_H

#include <string>
#include <exception>

namespace Cloude {
    namespace Foundation {
        namespace Exception {
            class cldeException : public std::exception {
            public:
                cldeException(const char *message) : _message(message) { };
                cldeException(const std::string &message) : _message(message) { };
                virtual ~cldeException() = default;
                cldeException(const cldeException &rhs) = default;
                cldeException &operator=(const cldeException &rhs) = default;

                virtual const char *what() const noexcept override { return _message.c_str(); };

            protected:
                std::string _message;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEEXCEPTION_H
