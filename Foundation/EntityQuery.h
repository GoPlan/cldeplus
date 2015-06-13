//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H

#include <memory>
#include <vector>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            class Predicate;
        }

        class EntityProxy;
        class EntityMap;
        class EntityStore;
        class EntitySourceDriver;

        class EntityQuery {

        public:
            using SPtrProxy = std::shared_ptr<EntityProxy>;
            using SPtrProxyVector = std::shared_ptr<std::vector<SPtrProxy>>;

        public:
            explicit EntityQuery(EntityStore &entityStore);
            virtual ~EntityQuery() = default;
            EntityQuery(const EntityQuery &srcEntityQuery) = default;
            EntityQuery &operator=(const EntityQuery &srcEntityQuery) = default;

            SPtrProxyVector Compose(const std::shared_ptr<Query::Predicate> &predicate);
            SPtrProxy ComposeGetFirst(const std::shared_ptr<Query::Predicate> &predicate);

        private:
            EntityStore &_entityStore;

        };
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
