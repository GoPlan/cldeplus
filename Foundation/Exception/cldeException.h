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

                std::string _message;

            public:
                cldeException(const char *message) : _message(message) { };
                cldeException(const std::string &message) : _message(message) { };
                cldeException(const cldeException &) = default;
                cldeException(cldeException &&) = default;
                cldeException &operator=(const cldeException &) = default;
                cldeException &operator=(cldeException &&) = default;
                virtual ~cldeException() = default;

                // Exception
                virtual const char *what() const noexcept override { return ("[" + Name() + "] " + _message).c_str(); };

                // Locals
                virtual const std::string &Name() const noexcept = 0;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEEXCEPTION_H
