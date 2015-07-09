//
// Created by LE, Duc-Anh on 5/23/15.
//

#include <string>
#include "EntitySourceDriver.h"
#include "Query/Helper/SqlHelper.h"
#include "Store/Helper/EntityStoreHelper.h"

namespace Cloude {
    namespace Foundation {

        EntityStore::EntityStore(const EntityMap &entityMap, const EntitySourceDriver &entitySourceDriver)
                : _entityMap(entityMap), _entitySourceDriver(entitySourceDriver) {
            //
        }

        bool EntityStore::HasIdentityInMap(const SPtrIdentity &identity) const {
            return !(_identityMap.find(identity) == _identityMap.end());
        }

        SPtrEntity EntityStore::Create(const SPtrIdentity &identity) {

            if (!identity) {
                std::string msg{"Identity is either a nullptr or invalid"};
                throw std::invalid_argument(msg);
            }

            auto &columnsForGet = _entityMap.getColumnsForGet();

            SPtrEntity entity = Foundation::CreateEntitySharedPtr(identity);

            Foundation::Store::Helper::EntityStoreHelper::GenerateFieldsFromColumns(columnsForGet, entity, false);

            Insert(entity);

            return entity;
        }

        SPtrEntity EntityStore::Get(const SPtrIdentity &identity) {

            auto search = _identityMap.find(identity);

            if (search != _identityMap.end()) {
                return search->second;
            }

            auto &columnsForGet = _entityMap.getColumnsForGet();

            SPtrEntity sptrEntity = Foundation::CreateEntitySharedPtr(identity);

            Foundation::Store::Helper::EntityStoreHelper::GenerateFieldsFromColumns(columnsForGet, sptrEntity, false);

            if (!_entitySourceDriver.Load(sptrEntity)) {
                return SPtrEntity(nullptr);
            }

            // Entity makes a copy of std::shared_ptr<Identity>,
            // Therefore, Identity must be taken from Entity
            _identityMap.insert(make_pair(sptrEntity->getIdentity(), sptrEntity));

            return sptrEntity;
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

        SPtrEntityStore CreateStoreSharedPtr(const EntityMap &entityMap, const EntitySourceDriver &entitySourceDriver) {
            return std::make_shared<EntityStore>(entityMap, entitySourceDriver);
        }
    }
}


