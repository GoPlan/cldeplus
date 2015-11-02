//
// Created by LE, Duc-Anh on 5/23/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYSTORE_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYSTORE_H

#include "cldeplus_default"
#include "Identity.h"
#include "Entity.h"
#include "EntityMap.h"

namespace CLDEPlus {
    namespace Foundation {

        class EntitySourceDriver;

        using SPtrIdentityMap = unordered_map<SPtrIdentity, SPtrEntity>;
        using SPtrEntitySourceDriver = shared_ptr<EntitySourceDriver>;

        class EntityStore {

            SPtrEntityMap _sptrEntityMap;
            SPtrEntitySourceDriver _sptrEntitySourceDriver;
            SPtrIdentityMap _identityMap;

        public:
            EntityStore(const SPtrEntityMap &sptrEntityMap, const SPtrEntitySourceDriver &sptrEntitySourceDriver);
            EntityStore(const EntityStore &) = default;
            EntityStore(EntityStore &&) = default;
            EntityStore &operator=(const EntityStore &) = default;
            EntityStore &operator=(EntityStore &&) = default;
            ~EntityStore() = default;

            // Locals
            bool HasIdentityInMap(const SPtrIdentity &identity) const;
            SPtrEntity Create(const SPtrIdentity &identity);
            SPtrEntity Get(const SPtrIdentity &identity);

            void Insert(SPtrEntity &entity);
            void Save(SPtrEntity &entity);
            void Delete(SPtrEntity &entity);

            void Clear();
            unsigned long Size() const;

            SPtrEntityMap const &getEntityMap() const { return _sptrEntityMap; }
            SPtrEntitySourceDriver const &getEntitySourceDriver() const { return _sptrEntitySourceDriver; }

            // Factory methods
            static unique_ptr<EntityStore> Create(SPtrEntityMap const &sptrEntityMap,
                                                       SPtrEntitySourceDriver const &sptrEntitySourceDriver) {
                return unique_ptr<EntityStore>(new EntityStore(sptrEntityMap, sptrEntitySourceDriver));
            }
        };

        using UPtrEntityStore = unique_ptr<EntityStore>;
        using SPtrEntityStore = shared_ptr<EntityStore>;
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYSTORE_H
