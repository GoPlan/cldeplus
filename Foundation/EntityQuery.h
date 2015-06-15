//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H

#include <memory>
#include <vector>
#include "EntityProxy.h"
#include "EntityStore.h"
#include "Query/Predicate.h"

namespace Cloude {
    namespace Foundation {

        class EntityQuery {

        public:
            explicit EntityQuery(EntityStore &entityStore);
            virtual ~EntityQuery() = default;
            EntityQuery(const EntityQuery &srcEntityQuery) = default;
            EntityQuery &operator=(const EntityQuery &srcEntityQuery) = default;

            SPtrProxyVector Compose(const Query::SPtrPredicate &predicate);
            SPtrProxy ComposeGetFirst(const Query::SPtrPredicate &predicate);

        private:
            EntityStore &_entityStore;
        };
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
