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
#include "EntitySourceDriver.h"

namespace Cloude {
    namespace Foundation {

        class EntityQuery {

            const EntityMap &_entityMap;
            const EntitySourceDriver &_entitySourceDriver;

        public:
            explicit EntityQuery(const EntityMap &entityMap, const EntitySourceDriver &entitySourceDriver);
            EntityQuery(const EntityQuery &) = default;
            EntityQuery(EntityQuery &&) = default;
            EntityQuery &operator=(const EntityQuery &) = default;
            EntityQuery &operator=(EntityQuery &&) = default;
            ~EntityQuery() = default;

            // Locals
            virtual SPtrEntityProxy SelectFirst(const Query::SPtrCriteria &sptrCriteria);
            virtual SPtrEntityProxyVector Select(const Query::SPtrCriteria &sptrCriteria);
            virtual SPtrEntityProxyVector Select(const Query::SPtrCriteria &sptrCriteria,
                                                 const SPtrColumnVector &columnsForProjection);
        };

        using SPtrEntityQuery = std::shared_ptr<EntityQuery>;

        SPtrEntityQuery CreateEntityQuery(const EntityMap &entityMap, const EntitySourceDriver &entitySourceDriver);
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
