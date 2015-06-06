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

            auto entity = make_shared<Entity>(identity);
            auto columnsForGet = _entityMap.getColumnsForGet();

            Architecture::Helper::GenerateFieldsFromColumns(entity, columnsForGet);

            if(!_entitySourceDriver.LoadEntity(entity, _entityMap)){
                return shared_ptr<Entity>();
            }

            _identityMap.insert(make_pair(identity, entity));

            return entity;
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

            auto entity = make_shared<Entity>(identity);
            auto columnsForGet = _entityMap.getColumnsForGet();

            Architecture::Helper::GenerateFieldsFromColumns(entity, columnsForGet);

            Insert(entity);

            return entity;
        }

        void EntityStore::Insert(std::shared_ptr<Entity> &entity) {
            auto identity = entity->getIdentity();
            _entitySourceDriver.CreateEntity(entity, _entityMap);
            _identityMap.insert(make_pair(identity, entity));
        }

        void EntityStore::Save(std::shared_ptr<Entity> &entity) {
            _entitySourceDriver.SaveEntity(entity, _entityMap);
        }

        void EntityStore::Delete(std::shared_ptr<Entity> &entity) {
            if(_entitySourceDriver.DeleteEntity(entity, _entityMap)){
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


