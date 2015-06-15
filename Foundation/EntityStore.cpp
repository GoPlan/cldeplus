//
// Created by LE, Duc-Anh on 5/23/15.
//

#include <memory>
#include <string>
#include "Exception/cldeEntityStoreRoutineException.h"
#include "EntityLoader.h"
#include "EntitySourceDriver.h"
#include "Query/Helper/SqlHelper.h"
#include "Store/EntityStoreHelper.h"

using namespace std;

namespace Cloude {
    namespace Foundation {

        EntityStore::EntityStore(const EntityMap &entityMap,
                                 const EntityLoader &entityLoader,
                                 const EntitySourceDriver &entitySourceDriver)
                : _entityMap(entityMap),
                  _entityLoader(entityLoader),
                  _entitySourceDriver(entitySourceDriver) {
            //
        }

        bool EntityStore::HasIdentityInMap(const shared_ptr<Identity> &identity) const {
            return !(_identityMap.find(identity) == _identityMap.end());
        }

        shared_ptr<Entity> EntityStore::Create() {

            auto identity = _entityLoader.NextPrimaryKey();
            auto entity = Create(identity);

            return entity;
        }

        shared_ptr<Entity> EntityStore::Create(const shared_ptr<Identity> &identity) {

            if (!identity) {
                const char *msg = "Identity is a nullptr or invalid";
                throw Foundation::Exception::cldeEntityStoreRoutineException(msg);
            }

            auto &columnsForGet = _entityMap.getColumnsForGet();

            std::shared_ptr<Entity> entity(new Entity(identity));

            Foundation::Query::GenerateFieldsFromColumns(columnsForGet, entity, false);

            Insert(entity);

            return entity;
        }

        shared_ptr<Entity> EntityStore::Get(const shared_ptr<Identity> &identity) {

            auto search = _identityMap.find(identity);

            if (search != _identityMap.end()) {
                return search->second;
            }

            auto &columnsForGet = _entityMap.getColumnsForGet();

            std::shared_ptr<Entity> entity(new Entity(identity));

            Foundation::Query::GenerateFieldsFromColumns(columnsForGet, entity, false);

            if (!_entitySourceDriver.Load(entity)) {
                return std::shared_ptr<Entity>(nullptr);
            }

            // Entity makes a copy of std::shared_ptr<Identity>,
            // Therefore, Identity must be taken from Entity
            _identityMap.insert(make_pair(entity->getIdentity(), entity));

            return entity;
        }

        void EntityStore::Insert(std::shared_ptr<Entity> &entity) {
            auto identity = entity->getIdentity();
            auto pairItem = make_pair(identity, entity);

            if (_entitySourceDriver.Insert(entity)) {
                _identityMap.insert(pairItem);
            }
        }

        void EntityStore::Save(std::shared_ptr<Entity> &entity) {
            _entitySourceDriver.Save(entity);
        }

        void EntityStore::Delete(std::shared_ptr<Entity> &entity) {
            if (_entitySourceDriver.Delete(entity)) {
                auto identity = entity->getIdentity();
                _identityMap.erase(identity);
            }
        }

        void EntityStore::Clear() {
            _identityMap.clear();
        }

        unsigned long EntityStore::Size() const {
            return _identityMap.size();
        }
    }
}


