//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYSTOREROUTINEEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYSTOREROUTINEEXCEPTION_H

#include "CLDEException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            class CLDEEntityStoreRoutineException : public CLDEException {

                static string _name;

            public:
                explicit CLDEEntityStoreRoutineException(char const *message) : CLDEException(message) { };
                explicit CLDEEntityStoreRoutineException(string const &message) : CLDEException(message) { };
                CLDEEntityStoreRoutineException(CLDEEntityStoreRoutineException const &) = default;
                CLDEEntityStoreRoutineException(CLDEEntityStoreRoutineException &&) = default;
                CLDEEntityStoreRoutineException &operator=(CLDEEntityStoreRoutineException const &) = default;
                CLDEEntityStoreRoutineException &operator=(CLDEEntityStoreRoutineException &&) = default;
                virtual ~CLDEEntityStoreRoutineException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYSTOREROUTINEEXCEPTION_H
