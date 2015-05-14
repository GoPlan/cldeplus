//
// Created by GoPlan on 14/05/2015.
//

#include "Entity.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            template <class T>
            Entity<T>::Entity(EntityStore<T> &entityStore, Identity &identity) :
                    entityStore(entityStore),
                    identity(identity) {
            }

            template <class T>
            Entity<T>::~Entity() {

            }

            template <class T>
            void Entity<T>::Save() {

            }

            template <class T>
            void Entity<T>::Delete() {

            }

            template <class T>
            void Entity<T>::RegisterChanged() {

            }

            template <class T>
            void Entity<T>::RegisterDeleted() {

            }
        }
    }
}