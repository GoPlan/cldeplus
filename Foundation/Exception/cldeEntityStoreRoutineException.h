//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYSTOREROUTINEEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYSTOREROUTINEEXCEPTION_H

#include "cldeException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            class cldeEntityStoreRoutineException : public cldeException {

            public:
                cldeEntityStoreRoutineException(const char *message) : cldeException(message) { };
                cldeEntityStoreRoutineException(const std::string &message) : cldeException(message) { };
                ~cldeEntityStoreRoutineException() = default;
                cldeEntityStoreRoutineException(const cldeEntityStoreRoutineException &rhs) = default;
                cldeEntityStoreRoutineException &operator=(const cldeEntityStoreRoutineException &rhs) = default;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYSTOREROUTINEEXCEPTION_H
