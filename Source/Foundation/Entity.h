//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITY_H

#include "../Port/Definitions.h"
#include "Cell.h"
#include "Identity.h"
#include "Exception/CLDEEntityException.h"
#include "Store/AbstractEntity.h"

namespace CLDEPlus {
    namespace Foundation {

        class Entity : public Store::AbstractEntity {

            SPtrIdentity _identity;

        public:
            explicit Entity(SPtrIdentity const &identity);
            Entity(const Entity &) = default;
            Entity(Entity &&) = default;
            Entity &operator=(Entity const &) = default;
            Entity &operator=(Entity &&) = default;
            ~Entity() = default;

            // Locals
            SPtrIdentity const &getIdentity() { return _identity; }

            template<class TEntity>
            TEntity NamedEntity(std::function<TEntity(Entity const &)> converter) { return converter(*this); };

            // Factory methods
            static unique_ptr<Entity> Create(SPtrIdentity const &identity) {
                return unique_ptr<Entity>(new Entity(identity));
            }
        };

        using UPtrEntity = unique_ptr<Entity>;
        using SPtrEntity = shared_ptr<Entity>;
        using SPtrEntityVector = vector<SPtrEntity>;
        using SPtrEntityList = list<SPtrEntity>;
        using SPtrEntitySet = set<SPtrEntity>;

    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITY_H
