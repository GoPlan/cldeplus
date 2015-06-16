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

        bool EntityStore::HasIdentityInMap(const SPtrIdentity &identity) const {
            return !(_identityMap.find(identity) == _identityMap.end());
        }

        SPtrEntity EntityStore::Create() {

            auto identity = _entityLoader.NextPrimaryKey();
            auto entity = Create(identity);

            return entity;
        }

        SPtrEntity EntityStore::Create(const SPtrIdentity &identity) {

            if (!identity) {
                const char *msg = "Identity is a nullptr or invalid";
                throw Foundation::Exception::cldeEntityStoreRoutineException(msg);
            }

            auto &columnsForGet = _entityMap.getColumnsForGet();

            SPtrEntity entity(new Entity(identity));

            Foundation::Store::EntityStoreHelper::GenerateFieldsFromColumns(columnsForGet, entity, false);

            Insert(entity);

            return entity;
        }

        SPtrEntity EntityStore::Get(const SPtrIdentity &identity) {

            auto search = _identityMap.find(identity);

            if (search != _identityMap.end()) {
                return search->second;
            }

            auto &columnsForGet = _entityMap.getColumnsForGet();

            SPtrEntity entity(new Entity(identity));

            Foundation::Store::EntityStoreHelper::GenerateFieldsFromColumns(columnsForGet, entity, false);

            if (!_entitySourceDriver.Load(entity)) {
                return SPtrEntity(nullptr);
            }

            // Entity makes a copy of std::shared_ptr<Identity>,
            // Therefore, Identity must be taken from Entity
            _identityMap.insert(make_pair(entity->getIdentity(), entity));

            return entity;
        }

        void EntityStore::Insert(SPtrEntity &entity) {
            auto identity = entity->getIdentity();
            auto pairItem = make_pair(identity, entity);

            if (_entitySourceDriver.Insert(entity)) {
                _identityMap.insert(pairItem);
            }
        }

        void EntityStore::Save(SPtrEntity &entity) {
            _entitySourceDriver.Save(entity);
        }

        void EntityStore::Delete(SPtrEntity &entity) {
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


