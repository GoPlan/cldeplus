//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H

#include "../Port/Definitions.h"
#include "EntityProxy.h"
#include "Query/Criteria.h"
#include "EntitySourceDriver.h"

namespace CLDEPlus {
    namespace Foundation {

        class EntityQuery {

            SPtrEntityMap _sptrEntityMap;
            SPtrEntitySourceDriver _sptrEntitySourceDriver;

        public:
            EntityQuery(SPtrEntityMap const &sptrEntityMap, SPtrEntitySourceDriver const &sptrEntitySourceDriver);
            EntityQuery(EntityQuery const &) = default;
            EntityQuery(EntityQuery &&) = default;
            EntityQuery &operator=(EntityQuery const &) = default;
            EntityQuery &operator=(EntityQuery &&) = default;
            ~EntityQuery() = default;

            // Locals
            virtual SPtrEntityProxy SelectFirst(Query::SPtrCriteria const &sptrCriteria);
            virtual SPtrEntityProxyVector Select(Query::SPtrCriteria const &sptrCriteria);
            virtual SPtrEntityProxyVector Select(Query::SPtrCriteria const &sptrCriteria, SPtrColumnVector const &columnsForProjection);

            // Factory methods
            static unique_ptr<EntityQuery> Create(SPtrEntityMap const &sptrEntityMap, SPtrEntitySourceDriver const &sptrEntitySourceDriver) {
                return cldeplus_make_unique<EntityQuery>(sptrEntityMap, sptrEntitySourceDriver);
            }
        };

        using UPtrEntityQuery = unique_ptr<EntityQuery>;
        using SPtrEntityQuery = shared_ptr<EntityQuery>;
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
