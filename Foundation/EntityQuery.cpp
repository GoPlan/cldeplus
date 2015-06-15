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

        SPtrProxyVector EntityQuery::Compose(const Query::SPtrPredicate &predicate) {
            return _entityStore.getEntitySourceDriver().Select(predicate, _entityStore);
        }

        SPtrProxy EntityQuery::ComposeGetFirst(const Query::SPtrPredicate &predicate) {
            return Compose(predicate).front();
        }
    }
}


