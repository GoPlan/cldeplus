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
                        _entity_map(entityMap),
                        _entity_loader(entityGenerator) { };

                virtual ~EntityStore() { };

                const TEntity *Get(Identity &identity) {

                    if (HasIdentityInMap(identity)) {
                        auto iter = _identity_map.find(&identity);
                        auto pair_item = (pair<Identity *, TEntity *>) *iter;
                        return pair_item.second;
                    }

                    auto entity = CreateEntityInstance(identity);

                    LoadEntity(*entity);
                    EstablishEntityRelationship(*entity);
                    RegisterClean(*entity);

                    return entity;
                }

                const TEntity *Create() {
                    auto identity = NextPrimaryKey();
                    auto entity = Create(*identity);
                    return entity;
                }

                const TEntity *Create(Identity &identity) {
                    auto entity = (TEntity *) (_entity_loader.CreateEntityInstance(identity));
                    return (Insert(*entity) > 0) ? entity : nullptr;
                }

                int Insert(TEntity &entity) {
                    return InsertEntity(entity);
                };

                int Save(TEntity &entity) {
                    return SaveEntity(entity);
                };

                int Delete(TEntity &entity) {
                    return DeleteEntity(entity);
                };

                bool HasIdentityInMap(Identity &identity) {
                    auto iterator = _identity_map.find(&identity);
                    return !(iterator == _identity_map.end());
                };

                void RegisterClean(TEntity &entity) {
                    UnRegister(entity);

                    auto tmpEntity = static_cast<Entity&>(entity);
                    auto tmpIdent = tmpEntity.identity();

                    _identity_map[&tmpIdent] = &tmpEntity;
                };

                void RegisterChanged(TEntity &entity) {
                    UnRegister(entity);

                    auto tmpEntity = static_cast<Entity&>(entity);
                    auto tmpIdent = tmpEntity.identity();

                    _changed_map[&tmpIdent] = &tmpEntity;
                };

                void RegisterDeleted(TEntity &entity) {
                    UnRegister(entity);

                    auto tmpEntity = static_cast<Entity&>(entity);
                    auto tmpIdent = tmpEntity.identity();

                    _deleted_map[&tmpIdent] = &tmpEntity;
                };

                void UnRegister(TEntity &entity) {
                    auto tmpEntity = static_cast<Entity&>(entity);
                    auto tmpIdent = tmpEntity.identity();

                    _identity_map.erase(&tmpIdent);
                    _changed_map.erase(&tmpIdent);
                    _deleted_map.erase(&tmpIdent);
                };

                void Commit() {
                    CommitChanged();
                    CommitChanged();
                };

            protected:
                EntityMap &_entity_map;
                EntityLoader &_entity_loader;
                unordered_map<const Identity *, unique_ptr<TEntity>> _identity_map;
                unordered_map<const Identity *, TEntity *> _changed_map;
                unordered_map<const Identity *, TEntity *> _deleted_map;

                virtual Identity *NextPrimaryKey() {
                    return _entity_loader.NextPrimaryKey();
                }

                virtual TEntity *CreateEntityInstance(Identity &ident) {
                    auto entity = _entity_loader.CreateEntityInstance(ident);
                    return (TEntity *) entity;
                }

                virtual void EstablishEntityRelationship(TEntity &entity) {
                    _entity_loader.EstablishEntityRelationship((Entity &) entity);
                }

                virtual void LoadEntity(TEntity &entity) {
                    _entity_loader.LoadEntity((Entity &) (entity));
                }

                virtual int InsertEntity(TEntity &entity) {
                    return _entity_loader.InsertEntity((Entity &) (entity));
                }

                virtual int SaveEntity(TEntity &entity) {
                    return _entity_loader.SaveEntity((Entity &) (entity));
                }

                virtual int DeleteEntity(TEntity &entity) {
                    return _entity_loader.DeleteEntity((Entity &) (entity));
                }

            private:
                void CommitChanged() {
                    for (auto item : _changed_map) {
                        auto entity = item.second;
                        Save(*entity);
                    }
                };

                void CommitDeleted() {
                    for (auto item : _deleted_map) {
                        auto entity = item.second;
                        Delete(*entity);
                    }
                };
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_ENTITYSTORE_H
