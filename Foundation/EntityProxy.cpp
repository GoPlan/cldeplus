//
// Created by LE, Duc Anh on 6/9/15.
//

#include "EntityProxy.h"

namespace Cloude {
    namespace Foundation {

        EntityProxy::EntityProxy(SPtrIdentity &identity, EntityStore &entityStore)
                : Entity(identity), _entityStore(entityStore) {
            //
        }

        SPtrEntity EntityProxy::Summon() {
            auto entity = _entityStore.Get(_identity);
            return entity;
        }

        EntityStore &EntityProxy::getEntityStore() const {
            return _entityStore;
        }
    }
}


