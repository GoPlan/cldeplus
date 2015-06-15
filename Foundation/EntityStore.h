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

        public:
            EntityStore(const EntityMap &entityMap,
                        const EntityLoader &entityLoader,
                        const EntitySourceDriver &entitySourceDriver);

            ~EntityStore() = default;
            EntityStore(const EntityStore &srcEntityStore) = default;
            EntityStore &operator=(const EntityStore &srcEntityStore) = default;

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

        protected:
            const EntityMap &_entityMap;
            const EntityLoader &_entityLoader;
            const EntitySourceDriver &_entitySourceDriver;

        private:
            SPtrIdentityMap _identityMap;

        };
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYSTORE_H
