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

                static std::string _name;

            public:
                cldeEntityStoreRoutineException(const char *message) : cldeException(message) { };
                cldeEntityStoreRoutineException(const std::string &message) : cldeException(message) { };
                cldeEntityStoreRoutineException(const cldeEntityStoreRoutineException &) = default;
                cldeEntityStoreRoutineException(cldeEntityStoreRoutineException &&) = default;
                cldeEntityStoreRoutineException &operator=(const cldeEntityStoreRoutineException &) = default;
                cldeEntityStoreRoutineException &operator=(cldeEntityStoreRoutineException &&) = default;
                ~cldeEntityStoreRoutineException() = default;

                // cldeException
                virtual const std::string &Name() const noexcept override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYSTOREROUTINEEXCEPTION_H
