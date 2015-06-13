//
// Created by LE, Duc Anh on 6/9/15.
//

#include "EntityQuery.h"
#include "EntityProxy.h"
#include "EntitySourceDriver.h"

namespace Cloude {
    namespace Foundation {

        EntityQuery::EntityQuery(EntityStore &entityStore)
                : _entityStore(entityStore) {
            //
        }

        EntityQuery::SPtrProxyVector EntityQuery::Compose(const std::shared_ptr<Query::Predicate> &predicate) {
            return _entityStore.getEntitySourceDriver().Select(predicate, _entityStore);
        }

        EntityQuery::SPtrProxy EntityQuery::ComposeGetFirst(const std::shared_ptr<Query::Predicate> &predicate) {
            return Compose(predicate)->front();
        }
    }
}


