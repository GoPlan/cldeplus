//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_CLDEENTITYSTOREROUTINEEXCEPTION_H
#define CLOUD_E_CPLUS_CLDEENTITYSTOREROUTINEEXCEPTION_H

#include "exception"
#include "string"

#include "../EntityStore.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            class cldeEntityStoreRoutineException : public std::exception {
            public:
                virtual ~cldeEntityStoreRoutineException() = default;

                explicit cldeEntityStoreRoutineException(const EntityStore &store, const std::string &sstrMessage);
                explicit cldeEntityStoreRoutineException(const EntityStore &store, const char *cstrMessage);
                virtual const char *what() const noexcept override;

            private:
                std::string _message;
                const EntityStore &_store;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_CLDEENTITYSTOREROUTINEEXCEPTION_H
