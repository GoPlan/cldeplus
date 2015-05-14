//
// Created by GoPlan on 14/05/2015.
//

#include "Entity.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {


            template<class T>
            template<class TEntity>
            Entity<T>::Entity(EntityStore<TEntity> &entityStore, Identity &identity) :
                    entityStore(entityStore),
                    identity(identity) {
            }

            template<class T>
            Entity<T>::~Entity() {
            }
        }
    }
}