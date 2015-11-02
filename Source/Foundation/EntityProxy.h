//
// Created by LE, Duc Anh on 6/9/15.
//

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
            static unique_ptr<EntityProxy> Create() {
                return cldeplus_make_unique<EntityProxy>();
            }

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
