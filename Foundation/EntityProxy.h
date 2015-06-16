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

        class EntityProxy : public Entity {
            enum class EntityProxySummonState {
                Undefined,
                Yes,
                No
            };

        public:
            EntityProxy(SPtrIdentity &identity, EntityStore &entityStore);
            EntityProxy(const EntityProxy &) = default;
            EntityProxy(EntityProxy &&) = default;
            EntityProxy &operator=(const EntityProxy &) = default;
            EntityProxy &operator=(EntityProxy &&) = default;
            ~EntityProxy() = default;

            // Locals
            bool isSummonable();
            SPtrEntity Summon();
            EntityStore &getEntityStore() const;

        private:
            EntityStore &_entityStore;
            EntityProxySummonState _summonState{EntityProxySummonState::Undefined};

        };

        using SPtrProxy = std::shared_ptr<EntityProxy>;
        using SPtrProxyVector = std::vector<SPtrProxy>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYPROXY_H
