//
// Created by LE, Duc-Anh on 5/23/15.
//

#ifndef CLOUD_E_CPLUS_ENTITYSTORE_H
#define CLOUD_E_CPLUS_ENTITYSTORE_H

#include <unordered_map>

#include "EntityMap.h"
#include "EntityLoader.h"
#include "EntitySourceDriver.h"

namespace Cloude {
    namespace Foundation {

        class EntityStore {
        public:
            EntityStore(EntityMap &entityMap, EntityLoader &entityLoader, EntitySourceDriver &entitySourceDriver);
            ~EntityStore() = default;
            EntityStore(const EntityStore &srcEntityStore) = default;
            EntityStore &operator=(const EntityStore &srcEntityStore) = default;

            bool HasIdentityInMap(const std::shared_ptr<Identity> &identity) const;

            std::shared_ptr<Entity> Create();
            std::shared_ptr<Entity> Create(const std::shared_ptr<Identity> &identity);
            std::shared_ptr<Entity> Get(const std::shared_ptr<Identity> &identity);

            void Insert(std::shared_ptr<Entity> &entity);
            void Save(std::shared_ptr<Entity> &entity);
            void Delete(std::shared_ptr<Entity> &entity);

            void Clear();
            unsigned long Size();

            const EntityMap &getEntityMap() const {
                return _entityMap;
            }

        protected:
            const EntityMap &_entityMap;
            const EntityLoader &_entityLoader;
            const EntitySourceDriver &_entitySourceDriver;

        private:
            std::unordered_map<std::shared_ptr<Identity>, std::shared_ptr<Entity>> _identityMap;

        };
    }
}

#endif //CLOUD_E_CPLUS_ENTITYSTORE_H
