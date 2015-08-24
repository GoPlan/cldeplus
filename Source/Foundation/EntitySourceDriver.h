//
// Created by LE, Duc Anh on 5/31/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYSOURCEDRIVER_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYSOURCEDRIVER_H

#include "Entity.h"
#include "EntityMap.h"
#include "EntityProxy.h"
#include "Query/Criteria.h"

namespace Cloude {
    namespace Foundation {

        class EntitySourceDriver {
        
            const EntityMap &_entityMap;

        public:
            explicit EntitySourceDriver(const EntityMap &entityMap);
            EntitySourceDriver(const EntitySourceDriver &) = delete;
            EntitySourceDriver(EntitySourceDriver &&) = delete;
            EntitySourceDriver &operator=(const EntitySourceDriver &) = delete;
            EntitySourceDriver &operator=(EntitySourceDriver &&) = delete;
            virtual ~EntitySourceDriver() = default;

            virtual int Load(SPtrEntity &entity) const = 0;
            virtual int Insert(SPtrEntity &entity) const = 0;
            virtual int Save(SPtrEntity &entity) const = 0;
            virtual int Delete(SPtrEntity &entity) const = 0;

            virtual SPtrEntityProxyVector Select(
                    const Foundation::Query::SPtrCriteria &sptrCriteria,
                    const Foundation::SPtrColumnVector &columnsForProjection) const = 0;

            const EntityMap &getEntityMap() const { return _entityMap; }
        };

        using SPtrEntitySourceDriver = std::shared_ptr<EntitySourceDriver>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYSOURCEDRIVER_H