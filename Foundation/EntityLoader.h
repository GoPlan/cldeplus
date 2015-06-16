//
// Created by LE, Duc Anh on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYLOADER_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYLOADER_H

#include "Identity.h"

namespace Cloude {
    namespace Foundation {

        class EntityLoader {

        public:
            EntityLoader(const EntityLoader &) = default;
            EntityLoader(EntityLoader &&) = default;
            EntityLoader &operator=(const EntityLoader &) = default;
            EntityLoader &operator=(EntityLoader &&) = default;
            virtual ~EntityLoader() = default;

            // Locals
            virtual SPtrIdentity NextPrimaryKey() const = 0;

        protected:
            EntityLoader() = default;
        };
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYLOADER_H
