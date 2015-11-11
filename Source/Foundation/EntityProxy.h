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

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYPROXY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYPROXY_H

#include "EntityStore.h"

namespace CLDEPlus {
    namespace Foundation {

        class EntityProxy : public Store::AbstractEntity,
                            public std::enable_shared_from_this<EntityProxy> {

        public:
            enum class EntityProxySummonState {
                Undefined,
                Yes,
                No
            };

        public:
            EntityProxy() = default;
            EntityProxy(EntityProxy const &) = default;
            EntityProxy(EntityProxy &&) = default;
            EntityProxy &operator=(EntityProxy const &) = default;
            EntityProxy &operator=(EntityProxy &&) = default;
            ~EntityProxy() = default;

            // Locals
            SPtrEntity Summon(SPtrEntityStore &entityStore);
            EntityProxySummonState getSummonState() const { return _summonState; }
            bool IsIdentifiableInStore(SPtrEntityStore &entityStore);
            void setSummonState(EntityProxySummonState const &summonState) { _summonState = summonState; }

            // Factory methods
            static unique_ptr<EntityProxy> CreateUnique() { return cldeplus_make_unique<EntityProxy>(); }
            static shared_ptr<EntityProxy> CreateShared() { return cldeplus_make_shared<EntityProxy>(); }

        private:
            EntityProxySummonState _summonState{EntityProxySummonState::Undefined};

        };

        using UPtrEntityProxy = unique_ptr<EntityProxy>;
        using SPtrEntityProxy = shared_ptr<EntityProxy>;
        using SPtrEntityProxyVector = vector<SPtrEntityProxy>;
        using SPtrEntityProxySet = set<SPtrEntityProxy>;


    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYPROXY_H
