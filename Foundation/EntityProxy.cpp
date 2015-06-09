//
// Created by LE, Duc Anh on 6/9/15.
//

#include "EntityProxy.h"

namespace Cloude {
    namespace Foundation {

        EntityProxy::EntityProxy(EntityStore &entityStore, std::shared_ptr<Identity> &identity)
                : _entityStore(entityStore), _identity(identity) {
            //
        }

        std::shared_ptr<Entity> EntityProxy::Summon() {
            auto entity = _entityStore.Get(_identity);
            return entity;
        }
    }
}


