//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITY_H

#include "unordered_map"
#include "Field.h"
#include "Identity.h"
#include "Exception/cldeEntityException.h"

namespace Cloude {
    namespace Foundation {

        class Entity : public Store::IDataRecord {

        public:
            Entity() = delete;
            ~Entity() = default;
            Entity(const Entity &) = default;
            Entity(Entity &&) = default;
            Entity &operator=(const Entity &) = default;
            Entity &operator=(Entity &&) = default;

            // Locals
            explicit Entity(const SPtrIdentity &identity);
            const SPtrIdentity &getIdentity() { return _identity; }

        protected:
            SPtrIdentity _identity;
        };

        using SPtrEntity = std::shared_ptr<Entity>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITY_H
