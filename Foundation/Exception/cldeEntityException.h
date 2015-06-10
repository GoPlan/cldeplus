//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_CLDEENTITYEXCEPTION_H
#define CLOUD_E_CPLUS_CLDEENTITYEXCEPTION_H


#include <exception>
#include <string>

namespace Cloude {
    namespace Foundation {
        namespace Exception {
            class cldeEntityException : public std::exception {
            public:
                virtual ~cldeEntityException() = default;
                cldeEntityException(const cldeEntityException &srcEntityException) = default;
                cldeEntityException &operator=(const cldeEntityException &srcEntityException) = default;

                explicit cldeEntityException(const std::string &message);
                virtual const char *what() const noexcept override;

            private:
                std::string _message;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDEENTITYEXCEPTION_H
