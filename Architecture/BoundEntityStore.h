//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_BOUNDENTITYSTORE_H
#define CLOUD_E_CPLUS_BOUNDENTITYSTORE_H

#include "Identity.h"
#include "Entity.h"
#include "EntityMap.h"
#include "EntityLoader.h"

namespace Cloude {
    namespace Architecture {

        template<class TEntity>
        class BoundEntityStore {

        public:
            BoundEntityStore(EntityMap &entityMap, EntityLoader &entityLoader) : _entityMap(entityMap),
                                                                                 _entityLoader(entityLoader) { };

            virtual ~BoundEntityStore() { };

            const TEntity *Get(Identity &identity) {
                return nullptr;
            }

            const TEntity *Create() {
                auto identity = NextPrimaryKey();
                auto entity = Create(*identity);
                return entity;
            }

            const TEntity *Create(Identity &identity) {
                return nullptr;
            }

            bool HasIdentityInMap(Identity &identity) {
                auto iterator = _identity_map.find(&identity);
                return !(iterator == _identity_map.end());
            };

        protected:
            EntityMap &_entityMap;
            EntityLoader &_entityLoader;
            std::unordered_map<const Identity *, TEntity *> _identity_map;

            virtual void LoadEntity(TEntity &entity) {
                _entityLoader.LoadEntity((Entity &) (entity));
            }

            virtual std::shared_ptr<Identity> NextPrimaryKey() {
                return _entityLoader.NextPrimaryKey();
            }

            virtual std::shared_ptr<Entity> CreateEntityInstance(std::shared_ptr<Identity> ident) {
                return _entityLoader.CreateEntityInstance(ident);
            }
        };
    }
}

#endif //CLOUD_E_CPLUS_BOUNDENTITYSTORE_H
