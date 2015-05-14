//
// Created by GoPlan on 14/05/2015.
//

#include "EntityStore.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            template<class TEntity>
            EntityStore<TEntity>::EntityStore() {

            }

            template<class TEntity>
            EntityStore<TEntity>::~EntityStore() {

            }

            template<class TEntity>
            void EntityStore<TEntity>::RegisterClean(TEntity &entity) {

            }

            template<class TEntity>
            void EntityStore<TEntity>::RegisterChanged(TEntity &entity) {

            }

            template<class TEntity>
            void EntityStore<TEntity>::RegisterDeleted(TEntity &entity) {

            }

            template<class TEntity>
            void EntityStore<TEntity>::UnRegister(TEntity &entity) {

            }

            template<class TEntity>
            void EntityStore<TEntity>::Commit() {
                CommitChanged();
                CommitChanged();
            }

            template<class TEntity>
            bool EntityStore<TEntity>::HasIdentityInMap(Identity &identity) {
                auto iterator = this->identityMap.find(identity);
                return iterator == identityMap.end() ? false : true;
            }

            template<class TEntity>
            void EntityStore<TEntity>::CommitChanged() {
                for (auto item : changedMap) {
                    auto entity = item.second;
                    Save(*entity);
                }
            }

            template<class TEntity>
            void EntityStore<TEntity>::CommitDeleted() {
                for (auto item : deletedMap) {
                    auto entity = item.second;
                    Delete(*entity);
                }
            }
        }
    }
}