//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_ENTITYSOURCEDRIVER_H
#define CLOUD_E_CPLUS_ENTITYSOURCEDRIVER_H

#include "memory"

#include "Entity.h"
#include "Column.h"
#include "EntityMap.h"

namespace Cloude {
    namespace Architecture {

        class EntitySourceDriver {
        public:
            virtual ~EntitySourceDriver() = default;

            virtual void LoadEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) = 0;
            virtual void CreateEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) = 0;

//            virtual int UpdateEntity(Entity &entity, ColumnsMap &columnsMap) = 0;
//            virtual int DeleteEntity(Entity &entity, ColumnsMap &columnsMap) = 0;
//            virtual int SelectEntity(Entity &entity, ColumnsMap &columnsMap) = 0;
        };
    }
}


#endif //CLOUD_E_CPLUS_ENTITYSOURCEDRIVER_H
