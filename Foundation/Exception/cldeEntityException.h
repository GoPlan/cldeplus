//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYEXCEPTION_H

#include "cldeException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            class cldeEntityException : public cldeException {

            public:
                cldeEntityException(const char *message) : cldeException(message) { };
                cldeEntityException(const std::string &message) : cldeException(message) { };
                cldeEntityException(const cldeEntityException &) = default;
                cldeEntityException(cldeEntityException &&) = default;
                cldeEntityException &operator=(const cldeEntityException &) = default;
                cldeEntityException &operator=(cldeEntityException &&) = default;
                ~cldeEntityException() = default;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYEXCEPTION_H
