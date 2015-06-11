//
// Created by LE, Duc Anh on 5/31/15.
//

#ifndef CLOUD_E_CPLUS_ENTITYSOURCEDRIVER_H
#define CLOUD_E_CPLUS_ENTITYSOURCEDRIVER_H

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
            explicit EntitySourceDriver(EntityMap &entityMap) : _entityMap(entityMap) { };
            virtual ~EntitySourceDriver() = default;
            EntitySourceDriver(const EntitySourceDriver &rhs) = delete;
            EntitySourceDriver &operator=(const EntitySourceDriver &rhs) = delete;

            virtual int Load(std::shared_ptr<Entity> &entity) const = 0;
            virtual int Insert(std::shared_ptr<Entity> &entity) const = 0;
            virtual int Save(std::shared_ptr<Entity> &entity) const = 0;
            virtual int Delete(std::shared_ptr<Entity> &entity) const = 0;

            virtual std::vector<EntityProxy> Select(std::shared_ptr<Query::Predicate> &expr) const = 0;

        protected:
            const EntityMap &_entityMap;

        };
    }
}


#endif //CLOUD_E_CPLUS_ENTITYSOURCEDRIVER_H
