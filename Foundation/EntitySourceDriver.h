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
            using upProxy = std::unique_ptr<EntityProxy>;
            using upProxyVector = std::unique_ptr<std::vector<upProxy>>;
            using upPredicate = std::unique_ptr<Query::Predicate>;

        public:
            explicit EntitySourceDriver(const EntityMap &entityMap) : _entityMap(entityMap) { };
            virtual ~EntitySourceDriver() = default;
            EntitySourceDriver(const EntitySourceDriver &rhs) = delete;
            EntitySourceDriver &operator=(const EntitySourceDriver &rhs) = delete;

            virtual int Load(std::shared_ptr<Entity> &entity) const = 0;
            virtual int Insert(std::shared_ptr<Entity> &entity) const = 0;
            virtual int Save(std::shared_ptr<Entity> &entity) const = 0;
            virtual int Delete(std::shared_ptr<Entity> &entity) const = 0;

            virtual upProxyVector Select(const upPredicate &predicate) const = 0;

        protected:
            const EntityMap &_entityMap;

        };
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYSOURCEDRIVER_H
