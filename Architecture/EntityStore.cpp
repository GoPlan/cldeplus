//
// Created by LE, Duc-Anh on 5/23/15.
//

#include <memory>
#include <string>

#include <Architecture/Exception/EntityStoreRoutineException.h>

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

            if (search != _identityMap.end()) {
                return search->second;
            }

            /// As Identity only initialized its entity fields that are used for primary key,
            /// the remaining fields are not yet valid up to this point. So we use a separate method to
            /// initialize these fields.
            generateNonKeyFields(identity);

            auto entity = identity->getEntity();
            _entitySourceDriver.LoadEntity(entity, _entityMap);
            _identityMap.insert(make_pair(identity, identity->getEntity()));

            return identity->getEntity();
        }

        shared_ptr<Entity> EntityStore::Create() {
            auto identity = _entityLoader.NextPrimaryKey();
            auto entity = Create(identity);

            return entity;
        }

        shared_ptr<Entity> EntityStore::Create(shared_ptr<Identity> &identity) {

            if (!identity) {
                string message = "Identity is a nullptr or invalid";
                throw Architecture::Exception::EntityStoreRoutineException(*this, message);
            }

            auto entity = identity->getEntity();
            Insert(entity);
            _identityMap.insert(make_pair(identity, entity));

            return identity->getEntity();
        }


        void EntityStore::Insert(std::shared_ptr<Entity> &entity) {
            _entitySourceDriver.CreateEntity(entity, _entityMap);
        }

        void EntityStore::Clear() {
            _identityMap.clear();
        }

        void EntityStore::generateNonKeyFields(std::shared_ptr<Identity> &identity) {

            auto entity = identity->getEntity();

            std::for_each(_entityMap.getColumnsForUpdate().cbegin(), _entityMap.getColumnsForUpdate().cend(),
                          [&entity](const shared_ptr<Column> &item) {
                              auto ptrField = new Field(item);
                              entity->InsertField(ptrField);
                          });
        }
    }
}


