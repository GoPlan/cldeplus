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
            EntityProxy(const EntityProxy &) = default;
            EntityProxy(EntityProxy &&) = default;
            EntityProxy &operator=(const EntityProxy &) = default;
            EntityProxy &operator=(EntityProxy &&) = default;
            ~EntityProxy() = default;

            // Locals
            SPtrEntity Summon(SPtrEntityStore &entityStore);
            EntityProxySummonState getSummonState() const { return _summonState; }
            bool IsIdentifiableInStore(SPtrEntityStore &entityStore);
            void setSummonState(const EntityProxySummonState &summonState) { _summonState = summonState; }

            // Factory methods
            static std::unique_ptr<EntityProxy> Create() {
                return std::unique_ptr<EntityProxy>(new EntityProxy());
            }

        private:
            EntityProxySummonState _summonState{EntityProxySummonState::Undefined};

        };

        using UPtrEntityProxy = std::unique_ptr<EntityProxy>;
        using SPtrEntityProxy = std::shared_ptr<EntityProxy>;
        using SPtrEntityProxyVector = std::vector<SPtrEntityProxy>;
        using SPtrEntityProxySet = std::set<SPtrEntityProxy>;


    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYPROXY_H
