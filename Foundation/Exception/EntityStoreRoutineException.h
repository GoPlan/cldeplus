//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_ENTITYSTOREROUTINEEXCEPTION_H
#define CLOUD_E_CPLUS_ENTITYSTOREROUTINEEXCEPTION_H

#include "exception"
#include "string"

#include "../EntityStore.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            class EntityStoreRoutineException : public std::exception {
            public:
                virtual ~EntityStoreRoutineException() = default;

                explicit EntityStoreRoutineException(const EntityStore &store, const std::string &sstrMessage);
                explicit EntityStoreRoutineException(const EntityStore &store, const char *cstrMessage);
                virtual const char *what() const noexcept override;

            private:
                std::string _message;
                const EntityStore &_store;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_ENTITYSTOREROUTINEEXCEPTION_H
