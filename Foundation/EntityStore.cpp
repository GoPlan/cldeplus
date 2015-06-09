//
// Created by LE, Duc-Anh on 5/23/15.
//

#include <memory>
#include <string>


#include "EntityLoader.h"
#include "EntitySourceDriver.h"
#include "Exception/EntityStoreRoutineException.h"
#include "Helper/SqlGenerator.h"
#include "Helper/EntityStoreHelper.h"

using namespace std;

namespace Cloude {
    namespace Foundation {

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

        shared_ptr<Entity> EntityStore::Create()  {

            auto identity = _entityLoader.NextPrimaryKey();
            auto entity = Create(identity);

            return entity;
        }

        shared_ptr<Entity> EntityStore::Create(const shared_ptr<Identity> &identity)  {

            if (!identity) {
                string message = "Identity is a nullptr or invalid";
                throw Foundation::Exception::EntityStoreRoutineException(*this, message);
            }

            auto &columnsForGet = _entityMap.getColumnsForGet();

            std::shared_ptr<Entity> entity(new Entity(identity));

            Foundation::Helper::GenerateFieldsFromColumns(entity, columnsForGet);

            Insert(entity);

            return entity;
        }

        shared_ptr<Entity> EntityStore::Get(const shared_ptr<Identity> &identity)  {

            auto search = _identityMap.find(identity);

            if (search != _identityMap.end()) {
                return search->second;
            }

            auto &columnsForGet = _entityMap.getColumnsForGet();

            std::shared_ptr<Entity> entity(new Entity(identity));

            Foundation::Helper::GenerateFieldsFromColumns(entity, columnsForGet);

            if (!_entitySourceDriver.LoadEntity(entity)) {
                return std::shared_ptr<Entity>(nullptr);
            }

            // Entity makes a copy of std::shared_ptr<Identity>,
            // Therefore, Identity must be taken from Entity
            _identityMap.insert(make_pair(entity->getIdentity(), entity));

            return entity;
        }

        void EntityStore::Insert(std::shared_ptr<Entity> &entity)  {
            auto identity = entity->getIdentity();
            auto pairItem = make_pair(identity, entity);

            if (_entitySourceDriver.CreateEntity(entity)) {
                _identityMap.insert(pairItem);
            }
        }

        void EntityStore::Save(std::shared_ptr<Entity> &entity)  {
            _entitySourceDriver.SaveEntity(entity);
        }

        void EntityStore::Delete(std::shared_ptr<Entity> &entity)  {
            if (_entitySourceDriver.DeleteEntity(entity)) {
                auto identity = entity->getIdentity();
                _identityMap.erase(identity);
            }
        }

        void EntityStore::Clear() {
            _identityMap.clear();
        }

        unsigned long EntityStore::Size() {
            return _identityMap.size();
        }
    }
}


