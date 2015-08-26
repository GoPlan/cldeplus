//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H

#include <memory>
#include "EntityProxy.h"
#include "Query/Criteria.h"
#include "EntitySourceDriver.h"

namespace Cloude {
    namespace Foundation {

        class EntityQuery {

            SPtrEntityMap _sptrEntityMap;
            SPtrEntitySourceDriver _sptrEntitySourceDriver;

        public:
            EntityQuery(const SPtrEntityMap &sptrEntityMap, const SPtrEntitySourceDriver &sptrEntitySourceDriver);
            EntityQuery(const EntityQuery &) = delete;
            EntityQuery(EntityQuery &&) = delete;
            EntityQuery &operator=(const EntityQuery &) = delete;
            EntityQuery &operator=(EntityQuery &&) = delete;
            virtual ~EntityQuery() = default;

            // Locals
            virtual SPtrEntityProxy SelectFirst(const Query::SPtrCriteria &sptrCriteria);
            virtual SPtrEntityProxyVector Select(const Query::SPtrCriteria &sptrCriteria);
            virtual SPtrEntityProxyVector Select(const Query::SPtrCriteria &sptrCriteria,
                                                 const SPtrColumnVector &columnsForProjection);

            static std::shared_ptr<EntityQuery> CreateSharedPtr(SPtrEntityMap const &sptrEntityMap,
                                                                SPtrEntitySourceDriver const &sptrEntitySourceDriver);

            static std::unique_ptr<EntityQuery> CreateUniquePtr(SPtrEntityMap const &sptrEntityMap,
                                                                SPtrEntitySourceDriver const &sptrEntitySourceDriver);
        };

        using UPtrEntityQuery = std::unique_ptr<EntityQuery>;
        using SPtrEntityQuery = std::shared_ptr<EntityQuery>;
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
