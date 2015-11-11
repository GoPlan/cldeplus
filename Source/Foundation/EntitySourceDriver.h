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

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYSOURCEDRIVER_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYSOURCEDRIVER_H

#include "Entity.h"
#include "EntityMap.h"
#include "EntityProxy.h"
#include "Query/Criteria.h"

namespace CLDEPlus {
    namespace Foundation {

        class EntitySourceDriver {

            SPtrEntityMap _sptrEntityMap;

        public:
            explicit EntitySourceDriver(SPtrEntityMap const &entityMap);
            EntitySourceDriver(EntitySourceDriver const &) = delete;
            EntitySourceDriver(EntitySourceDriver &&) = delete;
            EntitySourceDriver &operator=(EntitySourceDriver const &) = delete;
            EntitySourceDriver &operator=(EntitySourceDriver &&) = delete;
            virtual ~EntitySourceDriver() = default;

            virtual int Load(SPtrEntity &entity) const = 0;
            virtual int Insert(SPtrEntity &entity) const = 0;
            virtual int Save(SPtrEntity &entity) const = 0;
            virtual int Delete(SPtrEntity &entity) const = 0;
            virtual SPtrEntityProxyVector Select(Query::SPtrCriteria const &sptrCriteria, SPtrColumnVector const &columnsForProjection) const = 0;

            SPtrEntityMap const &getEntityMap() const { return _sptrEntityMap; }
        };

        using UPtrEntitySourceDriver = unique_ptr<EntitySourceDriver>;
        using SPtrEntitySourceDriver = shared_ptr<EntitySourceDriver>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYSOURCEDRIVER_H
