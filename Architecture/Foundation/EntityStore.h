//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITYSTORE_H
#define CLOUD_E_CPLUS_ENTITYSTORE_H

#include "Identity.h"
#include "Entity.h"
#include "EntityMap.h"
#include "EntityLoader.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            template<class TEntity>
            class EntityStore {

            public:

                EntityStore(EntityMap &entityMap, EntityLoader &entityGenerator) :
                        entityMap(entityMap),
                        entityGenerator(entityGenerator) { };

                virtual ~EntityStore() { };

                virtual const TEntity *Get(Identity &identity) = 0;
                virtual const TEntity *Create() = 0;
                virtual const TEntity *Create(Identity &identity) = 0;
                virtual int Insert(TEntity &entity) = 0;
                virtual int Save(TEntity &entity) = 0;
                virtual int Delete(TEntity &entity) = 0;

                bool HasIdentityInMap(Identity &identity) {
                    auto iterator = identityMap.find(&identity);
                    return !(iterator == identityMap.end());
                };

                void RegisterClean(TEntity &entity) {
                    UnRegister(entity);
                    Identity &ident = ((Entity&)(entity)).getIdentity();
                    identityMap[&ident] = &entity;
                };

                void RegisterChanged(TEntity &entity) {
                    UnRegister(entity);
                    Identity &ident = ((Entity&)(entity)).getIdentity();
                    changedMap[&ident] = &entity;
                };

                void RegisterDeleted(TEntity &entity) {
                    UnRegister(entity);
                    Identity &ident = ((Entity&)(entity)).getIdentity();
                    deletedMap[&ident] = &entity;
                };

                void UnRegister(TEntity &entity) {
                    Identity &identity = ((Entity&)(entity)).getIdentity();
                    identityMap.erase(&identity);
                    changedMap.erase(&identity);
                    deletedMap.erase(&identity);
                };

                void Commit() {
                    CommitChanged();
                    CommitChanged();
                };

            protected:
                EntityMap &entityMap;
                EntityLoader &entityGenerator;
                unordered_map<Identity *, TEntity *> identityMap;
                unordered_map<Identity *, TEntity *> changedMap;
                unordered_map<Identity *, TEntity *> deletedMap;

                Identity *NextPrimaryKey() {
                    return entityGenerator.NextPrimaryKey();
                }

                TEntity *CreateEntityInstance(Identity &ident) {
                    auto entity = entityGenerator.CreateEntityInstance(ident);
                    return (TEntity *) entity;
                }

                void EstablishEntityRelationShip(TEntity &entity) {
                    entityGenerator.EstablishEntityRelationship((Entity &) entity);
                }

                void LoadEntity(TEntity &entity) {

                }

            private:
                void CommitChanged() {
                    for (auto item : changedMap) {
                        auto entity = item.second;
                        Save(*entity);
                    }
                };

                void CommitDeleted() {
                    for (auto item : deletedMap) {
                        auto entity = item.second;
                        Delete(*entity);
                    }
                };
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_ENTITYSTORE_H
