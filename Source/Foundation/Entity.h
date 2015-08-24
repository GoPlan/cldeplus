//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITY_H

#include <memory>
#include <list>
#include <set>
#include "Cell.h"
#include "Identity.h"
#include "Exception/CLDEEntityException.h"
#include "Store/AbstractEntity.h"

namespace Cloude {
    namespace Foundation {

        class Entity : public Store::AbstractEntity {

            SPtrIdentity _identity;

        public:
            explicit Entity(const SPtrIdentity &identity);
            Entity(const Entity &) = default;
            Entity(Entity &&) = default;
            Entity &operator=(const Entity &) = default;
            Entity &operator=(Entity &&) = default;
            ~Entity() = default;

            // Locals
            const SPtrIdentity &getIdentity() { return _identity; }

            template<class TEntity>
            TEntity NamedEntity(std::function<TEntity(const Entity &)> converter) { return converter(*this); };
        };

        using SPtrEntity = std::shared_ptr<Entity>;
        using SPtrEntityVector = std::vector<SPtrEntity>;
        using SPtrEntityList = std::list<SPtrEntity>;
        using SPtrEntitySet = std::set<SPtrEntity>;

        SPtrEntity CreateEntity(const SPtrIdentity &identity);
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITY_H
