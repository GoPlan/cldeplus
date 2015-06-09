//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_ENTITYQUERY_H
#define CLOUD_E_CPLUS_ENTITYQUERY_H

#include <memory>
#include <vector>
#include "EntityProxy.h"
#include "EntityStore.h"
#include "Query/Predication.h"

namespace Cloude {
    namespace Foundation {
        class EntityQuery {
        public:
            explicit EntityQuery(const EntityStore &entityStore);
            virtual ~EntityQuery() = default;
            EntityQuery(const EntityQuery &srcEntityQuery) = default;
            EntityQuery &operator=(const EntityQuery &srcEntityQuery) = default;

            std::vector<std::shared_ptr<EntityProxy>>
                    Compose(const std::shared_ptr<Query::Predication> &predicate);
            std::vector<std::shared_ptr<EntityProxy>>
                    ComposeGetFirst(const std::shared_ptr<Query::Predication> &predicate);

        private:
            const EntityMap &_entityMap;
            const EntityStore &_entityStore;
            const EntitySourceDriver &_entitySoureDriver;

        };
    }
}

#endif //CLOUD_E_CPLUS_ENTITYQUERY_H
