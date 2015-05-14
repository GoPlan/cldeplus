//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITY_H
#define CLOUD_E_CPLUS_ENTITY_H

#include "Column.h"
#include "Identity.h"
#include "EntityStore.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            template<class T>
            class Entity {

            public:

                Entity(EntityStore<T> &entityStore, Identity &identity);

                virtual ~Entity();

                void Save();

                void Delete();

                void RegisterChanged();

                void RegisterDeleted();

            private:
                Identity &identity;
                EntityStore<T> &entityStore;

            };

        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITY_H
