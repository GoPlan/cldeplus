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

        public:
            explicit EntityQuery(EntityStore &entityStore);
            EntityQuery(const EntityQuery &) = default;
            EntityQuery(EntityQuery &&) = default;
            EntityQuery &operator=(const EntityQuery &) = default;
            EntityQuery &operator=(EntityQuery &&) = default;
            virtual ~EntityQuery() = default;

            virtual SPtrProxyVector Compose(const Query::SPtrCriteria &sptrCriteria);
            virtual SPtrProxy ComposeGetFirst(const Query::SPtrCriteria &sptrCriteria);

        private:
            EntityStore &_entityStore;
        };
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
