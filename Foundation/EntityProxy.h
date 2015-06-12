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

        class EntityProxy {
        public:
            explicit EntityProxy(EntityStore &entityStore, std::shared_ptr<Identity> &identity);
            virtual ~EntityProxy() = default;
            EntityProxy(const EntityProxy &srcEntityProxy) = default;
            EntityProxy &operator=(const EntityProxy &srcEntityProxy) = default;

            std::shared_ptr<Entity> Summon();

        private:
            EntityStore &_entityStore;
            std::shared_ptr<Identity> &_identity;
        };
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYPROXY_H
