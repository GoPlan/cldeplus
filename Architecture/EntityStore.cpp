//
// Created by LE, Duc-Anh on 5/23/15.
//

#include <Architecture/Exception/EntityStoreRoutineException.h>
#include "EntityStore.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        EntityStore::EntityStore(EntityMap &entityMap,
                                 EntityLoader &entityLoader,
                                 EntitySourceDriver &entitySourceDriver)
                : _entityMap(entityMap),
                  _entityLoader(entityLoader),
                  _entitySourceDriver(entitySourceDriver) {
            //
        }

        bool EntityStore::HasIdentityInMap(const shared_ptr<Identity> &identity) const {
            return !(_identityMap.find(identity) == _identityMap.end());
        }

        shared_ptr<Entity> EntityStore::Get(shared_ptr<Identity> &identity) {

            auto search = _identityMap.find(identity);

            // Return spEntity from identity map
            if (search != _identityMap.end()) {
                return search->second;
            }

            // Load entity(fields) from datasource
            _entityLoader.LoadEntity(identity);

            // Added found spEntity to identity map
            _identityMap.insert(make_pair(identity, identity->getEntity()));

            return identity->getEntity();
        }

        shared_ptr<Entity> EntityStore::Create() {
            return Create(_entityLoader.NextPrimaryKey());
        }

        shared_ptr<Entity> EntityStore::Create(shared_ptr<Identity> identity) {

            if (!identity) {
                string message = "Identity is a nullptr or invalid";
                throw Architecture::Exception::EntityStoreRoutineException(*this, message);
            }

            // Insert entity into datasource
            Insert(identity->getEntity());

            // Added found spEntity to identity map
            _identityMap.insert(make_pair(identity, identity->getEntity()));

            return identity->getEntity();
        }


        void EntityStore::Insert(std::shared_ptr<Entity> &entity) {

        }

        void EntityStore::Clear() {
            _identityMap.clear();
        }
    }
}


