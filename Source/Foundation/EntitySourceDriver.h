//
// Created by LE, Duc Anh on 5/31/15.
//

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
            explicit EntitySourceDriver(const SPtrEntityMap &entityMap);
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
