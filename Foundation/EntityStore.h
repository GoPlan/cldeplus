//
// Created by LE, Duc-Anh on 5/23/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYSTORE_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYSTORE_H

#include <unordered_map>
#include "Identity.h"
#include "Entity.h"
#include "EntityMap.h"
#include "EntityLoader.h"

namespace Cloude {
    namespace Foundation {

        using SPtrIdentityMap = std::unordered_map<SPtrIdentity, SPtrEntity>;

        class EntitySourceDriver;

        class EntityStore {

            const EntityMap &_entityMap;
            const EntityLoader &_entityLoader;
            const EntitySourceDriver &_entitySourceDriver;
            SPtrIdentityMap _identityMap;

        public:
            EntityStore(const EntityMap &entityMap,
                        const EntityLoader &entityLoader,
                        const EntitySourceDriver &entitySourceDriver);

            EntityStore(const EntityStore &) = default;
            EntityStore(EntityStore &&) = default;
            EntityStore &operator=(const EntityStore &) = default;
            EntityStore &operator=(EntityStore &&) = default;
            ~EntityStore() = default;

            bool HasIdentityInMap(const SPtrIdentity &identity) const;

            SPtrEntity Create();
            SPtrEntity Create(const SPtrIdentity &identity);
            SPtrEntity Get(const SPtrIdentity &identity);

            void Insert(SPtrEntity &entity);
            void Save(SPtrEntity &entity);
            void Delete(SPtrEntity &entity);

            void Clear();
            unsigned long Size() const;

            const EntityMap &getEntityMap() const { return _entityMap; }
            const EntitySourceDriver &getEntitySourceDriver() const { return _entitySourceDriver; }
        };

        using SPtrEntityStore = std::shared_ptr<EntityStore>;

        SPtrEntityStore CreateStoreSharedPtr(const EntityMap &entityMap,
                                             const EntityLoader &entityLoader,
                                             const EntitySourceDriver &entitySourceDriver);
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYSTORE_H
