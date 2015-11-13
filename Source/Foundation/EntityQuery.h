/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H

#include "../Portable/CommonTypes.h"
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
            static unique_ptr<EntityQuery> CreateUnique(SPtrEntityMap const &sptrEntityMap, SPtrEntitySourceDriver const &sptrEntitySourceDriver) {
                return cldeplus_make_unique<EntityQuery>(sptrEntityMap, sptrEntitySourceDriver);
            }
            static shared_ptr<EntityQuery> CreateShared(SPtrEntityMap const &sptrEntityMap, SPtrEntitySourceDriver const &sptrEntitySourceDriver) {
                return cldeplus_make_shared<EntityQuery>(sptrEntityMap, sptrEntitySourceDriver);
            }
        };

        using UPtrEntityQuery = unique_ptr<EntityQuery>;
        using SPtrEntityQuery = shared_ptr<EntityQuery>;
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYQUERY_H
