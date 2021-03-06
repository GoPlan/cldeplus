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

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITY_H

#include "../Portable/CommonTypes.h"
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
            Entity(Entity const &) = default;
            Entity(Entity &&) = default;
            Entity &operator=(Entity const &) = default;
            Entity &operator=(Entity &&) = default;
            ~Entity() = default;

            // Locals
            SPtrIdentity const &getIdentity() { return _identity; }

            template<class TEntity>
            TEntity NamedEntity(std::function<TEntity(Entity const &)> converter) { return converter(*this); };

            // Factory methods
            static unique_ptr<Entity> CreateUnique(SPtrIdentity const &identity) {
                return cldeplus_make_unique<Entity>(identity);
            }
            static shared_ptr<Entity> CreateShared(SPtrIdentity const &identity) {
                return cldeplus_make_shared<Entity>(identity);
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
