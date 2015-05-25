//
// Created by LE, Duc-Anh on 5/23/15.
//

#include "EntityStore.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        EntityStore::EntityStore(EntityMap &entityMap, EntityLoader &entityLoader) : _entityMap(entityMap),
                                                                                     _entityLoader(entityLoader) {
            //
        }

        bool EntityStore::HasIdentityInMap(const shared_ptr<Identity> &identity) const {
            return !(_identityMap.find(identity) == _identityMap.end());
        }

        shared_ptr<Entity> &EntityStore::Get(shared_ptr<Identity> &identity) {

            auto search = _identityMap.find(identity);

            // Return spEntity from identity map
            if (search != _identityMap.end()) {
                return search->second;
            }

            // Load spEntity fields
            // TODO: Query datasource for spEntity
            _entityLoader.LoadEntity(identity);

            // Retrieve entity instance (from Identity)
            auto spEntity = identity->getEntity();

            // Added found spEntity to identity map
            _identityMap.insert(make_pair(identity, spEntity));

            return spEntity;
        }

        shared_ptr<Entity> &EntityStore::Create() {
            return Create(_entityLoader.NextPrimaryKey());
        }

        shared_ptr<Entity> &EntityStore::Create(shared_ptr<Identity> identity) {

            if (!identity) {
                // TODO: Consider throwing an exception on nullptr Identity
                shared_ptr<Entity> spEntity;
                return spEntity;
            }

            auto spEntity = identity->getEntity();
            auto identityPair = make_pair(identity, spEntity);

            Insert(spEntity);

            _identityMap.insert(identityPair);

            return spEntity;
        }


        void EntityStore::Insert(std::shared_ptr<Entity> &entity) {

        }

        void EntityStore::Clear() {
            _identityMap.clear();
        }
    }
}


