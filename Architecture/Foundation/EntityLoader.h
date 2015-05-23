//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITYLOADER_H
#define CLOUD_E_CPLUS_ENTITYLOADER_H

#include "Identity.h"
#include "Entity.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            class EntityLoader {
            public:
                virtual shared_ptr<Identity> NextPrimaryKey() = 0;
                virtual shared_ptr<Entity> CreateEntityInstance(shared_ptr<Identity> ident) = 0;
                virtual void LoadEntity(Entity &entity) = 0;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITYLOADER_H
