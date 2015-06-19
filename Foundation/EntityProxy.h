//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYPROXY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYPROXY_H

#include "EntityStore.h"
#include "Entity.h"
#include "Identity.h"

namespace Cloude {
    namespace Foundation {

        class EntityProxy : public Store::IDataRecord {

            enum class EntityProxySummonState {
                Undefined,
                Yes,
                No
            };

            mutable EntityProxySummonState _summonState{EntityProxySummonState::Undefined};

        public:
            EntityProxy() = default;
            EntityProxy(const EntityProxy &) = default;
            EntityProxy(EntityProxy &&) = default;
            EntityProxy &operator=(const EntityProxy &) = default;
            EntityProxy &operator=(EntityProxy &&) = default;
            ~EntityProxy() = default;

            // Locals
            SPtrEntity Summon(EntityStore &entityStore) const;
            bool isIdentifiableInStore(const EntityStore &entityStore) const;
        };

        using SPtrEntityProxy = std::shared_ptr<EntityProxy>;
        using SPtrEntityProxyVector = std::vector<SPtrEntityProxy>;
        using SPtrEntityProxySet = std::set<SPtrEntityProxy>;
        using SPtrEntityProxyList = std::list<SPtrEntityProxy>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYPROXY_H
