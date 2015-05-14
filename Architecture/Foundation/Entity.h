//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITY_H
#define CLOUD_E_CPLUS_ENTITY_H

#include "Column.h"
#include "Identity.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            template<class TEntity>
            class EntityStore;

            template<class T>
            class Entity {

            public:
                template<class TEntity>
                Entity(EntityStore<TEntity> &entityStore, Identity &identity);
                virtual ~Entity();

                Identity &getIdentity() const {
                    return identity;
                }
                EntityStore<T> &getEntity_store() const {
                    return entityStore;
                }

                void Save() {
                    entityStore.Save(*this);
                };
                void Delete() {
                    entityStore.Delete(*this);
                };
                void RegisterChanged() {
                    entityStore.RegisterChanged(*this);
                };
                void RegisterDeleted() {
                    entityStore.RegisterDeleted(*this);
                };

            private:
                Identity &identity;
                EntityStore<T> &entityStore;

            };

        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITY_H
