//
// Created by LE, Duc-Anh on 5/23/15.
//

#ifndef CLOUD_E_CPLUS_ENTITYSTORE_H
#define CLOUD_E_CPLUS_ENTITYSTORE_H

#include "Identity.h"
#include "Entity.h"
#include "EntityMap.h"
#include "EntityLoader.h"

namespace Cloude {
    namespace Architecture {

        class EntityStore {
        public:
            EntityStore(EntityMap &entityMap, EntityLoader &entityLoader);
            EntityStore(const EntityStore& srcEntityStore) = default;
            EntityStore& operator = (const EntityStore& srcEntityStore) = default;
            virtual ~EntityStore() = default;

            std::shared_ptr<Entity> Get(std::shared_ptr <Identity> &identity);
            std::shared_ptr<Entity> Create();
            std::shared_ptr<Entity> Create(std::shared_ptr <Identity> identity);

            void Insert(std::shared_ptr<Entity> &entity);
            void Delete(std::shared_ptr<Entity> &entity);
            void Save(std::shared_ptr<Entity> &entity) const;
            void Clear();

        protected:
            EntityMap &_entityMap;
            EntityLoader &_entityLoader;

            void LoadEntity(std::shared_ptr<Entity> &entity) const;

        private:
            std::unordered_map<std::shared_ptr<Identity>, std::shared_ptr<Entity>> _identityMap;

        };
    }
}

#endif //CLOUD_E_CPLUS_ENTITYSTORE_H
