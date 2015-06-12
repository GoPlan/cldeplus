//
// Created by LE, Duc Anh on 6/9/15.
//

#include "EntityQuery.h"

namespace Cloude {
    namespace Foundation {

        EntityQuery::EntityQuery(const EntityStore &entityStore)
                : _entityStore(entityStore),
                  _entityMap(entityStore.getEntityMap()),
                  _entitySourceDriver(entityStore.getEntitySourceDriver()) {
            //
        }

        EntityQuery::spProxyVector EntityQuery::Compose(const std::shared_ptr<Query::Predicate> &predicate) {

            spProxyVector proxies;

            return proxies;
        }

        EntityQuery::spProxy EntityQuery::ComposeGetFirst(const std::shared_ptr<Query::Predicate> &predicate) {

            std::shared_ptr<EntityProxy> proxy;

            return proxy;
        }
    }
}


