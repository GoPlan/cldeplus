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
            using spProxy = std::shared_ptr<EntityProxy>;
            using spProxyVector = std::shared_ptr<std::vector<spProxy>>;

        public:
            explicit EntityQuery(const EntityStore &entityStore);
            virtual ~EntityQuery() = default;
            EntityQuery(const EntityQuery &srcEntityQuery) = default;
            EntityQuery &operator=(const EntityQuery &srcEntityQuery) = default;

            spProxyVector Compose(const std::shared_ptr<Query::Predicate> &predicate);
            spProxy ComposeGetFirst(const std::shared_ptr<Query::Predicate> &predicate);

        private:
            const EntityMap &_entityMap;
            const EntityStore &_entityStore;
            const EntitySourceDriver &_entitySourceDriver;

        };
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
