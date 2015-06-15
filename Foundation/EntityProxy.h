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

        public:
            explicit EntityProxy(SPtrIdentity &identity, EntityStore &entityStore);
            ~EntityProxy() = default;
            EntityProxy(EntityProxy &) = default;
            EntityProxy &operator=(EntityProxy &) = default;

            // Locals
            SPtrEntity Summon();
            EntityStore &getEntityStore() const;

        private:
            EntityStore &_entityStore;
        };

        using SPtrProxy = std::shared_ptr<EntityProxy>;
        using SPtrProxyVector = std::vector<SPtrProxy>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYPROXY_H
