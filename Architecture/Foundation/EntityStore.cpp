//
// Created by LE, Duc-Anh on 5/23/15.
//

#include "EntityStore.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            const shared_ptr<Entity> EntityStore::Get(shared_ptr<Identity> identity) {

                auto search = _identityMap.find(identity);

                // Return spEntity from identity map
                if (search != _identityMap.end()) {
                    return search->second;
                }

                // Query datasoure for spEntity
                // TODO: Query datasource for spEntity
                //

                // Create instance if identity is found in source
                auto spEntity = identity->getSpEntity();

                // Load spEntity fields
                _entityLoader.LoadEntity(*spEntity);

                // Added found spEntity to identity map
                _identityMap.insert(make_pair(identity, spEntity));

                return spEntity;
            }

            const shared_ptr<Entity> EntityStore::Create() {
                return Create(_entityLoader.NextPrimaryKey());
            }

            const shared_ptr<Entity> EntityStore::Create(shared_ptr<Identity> identity) {

                if (!identity) {
                    // TODO: Consider throwing an exception on nullptr Identity
                    shared_ptr<Entity> spEntity;
                    return spEntity;
                }

                auto spEntity = identity->getSpEntity();
                auto identityPair = make_pair(identity, spEntity);

                Insert(spEntity);

                _identityMap.insert(identityPair);

                return spEntity;
            }

            const shared_ptr<Entity> EntityStore::CreateEntityInstance(shared_ptr<Identity> identity) const {
                return make_shared<Entity>(identity);
            }

            void EntityStore::LoadEntity(shared_ptr<Entity> entity) const {

            }

            void EntityStore::Insert(shared_ptr<Entity> entity) {

            }

            void EntityStore::Delete(shared_ptr<Entity> entity) {

            }

            void EntityStore::Save(shared_ptr<Entity> entity) const {


            }

            void EntityStore::Clear() {
                _identityMap.clear();
            }
        }
    }
}


