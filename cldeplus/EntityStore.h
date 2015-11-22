/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYSTORE_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYSTORE_H

#include "CldePlus-Portable.h"
#include "EntityIdentity.h"
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
            EntityStore(SPtrEntityMap const &sptrEntityMap, SPtrEntitySourceDriver const &sptrEntitySourceDriver);
            EntityStore(EntityStore const &) = default;
            EntityStore(EntityStore &&) = default;
            EntityStore &operator=(EntityStore const &) = default;
            EntityStore &operator=(EntityStore &&) = default;
            virtual ~EntityStore() = default;

            // Locals
            bool HasIdentityInMap(SPtrIdentity const &identity) const;
            SPtrEntity Create(SPtrIdentity const &identity);
            SPtrEntity Get(SPtrIdentity const &identity);

            void Insert(SPtrEntity &entity);
            void Save(SPtrEntity &entity);
            void Delete(SPtrEntity &entity);

            void Clear();
            unsigned long Size() const;

            SPtrEntityMap const &getEntityMap() const { return _sptrEntityMap; }
            SPtrEntitySourceDriver const &getEntitySourceDriver() const { return _sptrEntitySourceDriver; }

            // Initialisation & Factory methods
            static unique_ptr <EntityStore> CreateUnique(SPtrEntityMap const &sptrEntityMap, SPtrEntitySourceDriver const &sptrEntitySourceDriver) {
                return cldeplus_make_unique<EntityStore>(sptrEntityMap, sptrEntitySourceDriver);
            }
            static shared_ptr <EntityStore> CreateShared(SPtrEntityMap const &sptrEntityMap, SPtrEntitySourceDriver const &sptrEntitySourceDriver) {
                return cldeplus_make_shared<EntityStore>(sptrEntityMap, sptrEntitySourceDriver);
            }
        };

        using UPtrEntityStore = unique_ptr<EntityStore>;
        using SPtrEntityStore = shared_ptr<EntityStore>;
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYSTORE_H
