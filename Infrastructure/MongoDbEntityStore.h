//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_MONGODBENTITYSTORE_H
#define CLOUD_E_CPLUS_MONGODBENTITYSTORE_H

#include "../Architecture/Foundation/EntityStore.h"

using namespace Cloude::Architecture::Foundation;

namespace Cloude {
    namespace Infrastructure {

        template<class TEntity>
        class MongoDbEntityStore : EntityStore<TEntity> {

        public:
            MongoDbEntityStore(EntityMap &entityMap, EntityLoader &entityGenerator) :
                    EntityStore<TEntity>(entityMap, entityGenerator) { };

            virtual ~MongoDbEntityStore() { };

        protected:
            virtual const TEntity *Get(Identity &identity) override {

                TEntity * entity_ptr = nullptr;

                if (EntityStore<TEntity>::HasIdentityInMap(identity)){
                    auto iterator = EntityStore<TEntity>::identityMap.find(&identity);

                    if(iterator == EntityStore<TEntity>::identityMap.end())
                        return nullptr;

                    entity_ptr = ((pair<Identity*, TEntity*>)(*iterator)).second;

                    return entity_ptr;
                }

                entity_ptr = EntityStore<TEntity>::CreateEntityInstance(identity);

                EntityStore<TEntity>::LoadEntity(*entity_ptr);
                EntityStore<TEntity>::EstablishEntityRelationShip(*entity_ptr);
                EntityStore<TEntity>::RegisterClean(*entity_ptr);

                return entity_ptr;
            };

            virtual const TEntity *Create() override {
                auto ident = EntityStore<TEntity>::NextPrimaryKey();
                return Create(*ident);
            };

            virtual const TEntity *Create(Identity &identity) override {
                TEntity *entity = EntityStore<TEntity>::CreateEntityInstance(identity);
                return entity;
            };

            virtual int Insert(TEntity &entity) override { return 0; };
            virtual int Save(TEntity &entity) override { return 0; };
            virtual int Delete(TEntity &entity) override { return 0; };
        };
    }
}

#endif //CLOUD_E_CPLUS_MONGODBENTITYSTORE_H
