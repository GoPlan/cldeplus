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
                ~cldeEntityException() = default;
                cldeEntityException(const cldeEntityException &rhs) = default;
                cldeEntityException &operator=(const cldeEntityException &rhs) = default;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYEXCEPTION_H
