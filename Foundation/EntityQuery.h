//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H

#include <memory>
#include <vector>
#include "EntityProxy.h"
#include "EntityStore.h"
#include "Query/Criteria.h"

namespace Cloude {
    namespace Foundation {

        class EntityQuery {
            EntityStore &_entityStore;

        public:
            explicit EntityQuery(EntityStore &entityStore);
            EntityQuery(const EntityQuery &) = default;
            EntityQuery(EntityQuery &&) = default;
            EntityQuery &operator=(const EntityQuery &) = default;
            EntityQuery &operator=(EntityQuery &&) = default;
            virtual ~EntityQuery() = default;

            // Locals
            virtual SPtrEntityProxyVector Compose(const Query::SPtrCriteria &sptrCriteria);

            virtual SPtrEntityProxyVector Compose(const SPtrColumnVector &columnsForProjection,
                                                  const SPtrColumnVector &columnsForKey,
                                                  const Query::SPtrCriteria &sptrCriteria);

            virtual SPtrEntityProxy ComposeGetFirst(const Query::SPtrCriteria &sptrCriteria);
        };
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
