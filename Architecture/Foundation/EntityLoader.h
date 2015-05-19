//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITYLOADER_H
#define CLOUD_E_CPLUS_ENTITYLOADER_H

#include "Entity.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            class EntityLoader {
            public:
                virtual Entity *CreateEntityInstance(Identity &ident) = 0;
                virtual Identity *NextPrimaryKey() = 0;
                virtual void LoadEntity(Entity &entity) = 0;
                virtual void LoadEntityPrimaryKeyFields() = 0;
                virtual void EstablishEntityRelationship(Entity &entity) = 0;
                virtual int InsertEntity(Entity &entity) = 0;
                virtual int SaveEntity(Entity &entity) = 0;
                virtual int DeleteEntity(Entity &entity) = 0;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITYLOADER_H
