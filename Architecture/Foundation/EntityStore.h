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
                EntityStore(EntityMap &entityMap, EntityLoader &entityLoader) : _entityMap(entityMap),
                                                                                _entityLoader(entityLoader) { };
                virtual ~EntityStore() { };

                const TEntity *Get(Identity &identity) {

                    if (HasIdentityInMap(identity)) {
                        auto iter = _identity_map.find(&identity);
                        auto pair_item = (std::pair<Identity *, TEntity *>) *iter;
                        return pair_item.second;
                    }

                    auto entity = CreateEntityInstance(identity);

                    LoadEntity(*entity);
                    EstablishEntityRelationship(*entity);

                    return entity;
                }
                const TEntity *Create() {
                    auto identity = NextPrimaryKey();
                    auto entity = Create(*identity);
                    return entity;
                }
                const TEntity *Create(Identity &identity) {
                    auto entity = (TEntity *) (_entityLoader.CreateEntityInstance(identity));
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

            protected:
                EntityMap &_entityMap;
                EntityLoader &_entityLoader;
                std::unordered_map<const Identity *, TEntity *> _identity_map;

                virtual void EstablishEntityRelationship(TEntity &entity) {
                    _entityLoader.EstablishEntityRelationship((Entity &) entity);
                }
                virtual void LoadEntity(TEntity &entity) {
                    _entityLoader.LoadEntity((Entity &) (entity));
                }
                virtual Identity *NextPrimaryKey() {
                    return _entityLoader.NextPrimaryKey();
                }
                virtual TEntity *CreateEntityInstance(Identity &ident) {
                    auto entityPtr = static_cast<TEntity *>(_entityLoader.CreateEntityInstance(ident));
                    return entityPtr;
                }
                virtual int InsertEntity(TEntity &entity) {
                    auto result = _entityLoader.InsertEntity(entity);
                    return result;
                }
                virtual int SaveEntity(TEntity &entity) {
                    auto result = _entityLoader.SaveEntity(entity);
                    return result;
                }
                virtual int DeleteEntity(TEntity &entity) {
                    auto result = _entityLoader.DeleteEntity(entity);
                    return result;
                }
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_ENTITYSTORE_H
