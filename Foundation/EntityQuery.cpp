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

        SPtrProxyVector EntityQuery::Compose(const Query::SPtrCriteria &sptrCriteria) {
            return _entityStore.getEntitySourceDriver().Select(sptrCriteria, _entityStore);
        }

        SPtrProxy EntityQuery::ComposeGetFirst(const Query::SPtrCriteria &sptrCriteria) {
            return Compose(sptrCriteria).front();
        }
    }
}


