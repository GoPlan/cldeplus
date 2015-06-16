//
// Created by LE, Duc Anh on 5/31/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYSOURCEDRIVER_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYSOURCEDRIVER_H

#include <memory>
#include <vector>
#include "EntityMap.h"
#include "EntityProxy.h"
#include "Entity.h"
#include "Query/Predicate.h"

namespace Cloude {
    namespace Foundation {

        class EntitySourceDriver {

        public:
            explicit EntitySourceDriver(const EntityMap &entityMap) : _entityMap(entityMap) { };
            virtual ~EntitySourceDriver() = default;
            EntitySourceDriver(const EntitySourceDriver &rhs) = delete;
            EntitySourceDriver &operator=(const EntitySourceDriver &rhs) = delete;

            virtual int Load(SPtrEntity &entity) const = 0;
            virtual int Insert(SPtrEntity &entity) const = 0;
            virtual int Save(SPtrEntity &entity) const = 0;
            virtual int Delete(SPtrEntity &entity) const = 0;

            virtual SPtrProxyVector Select(const Query::SPtrPredicate &predicate, EntityStore &entityStore) const = 0;

        protected:
            const EntityMap &_entityMap;
        };
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYSOURCEDRIVER_H
