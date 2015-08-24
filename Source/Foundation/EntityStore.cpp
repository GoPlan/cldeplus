//
// Created by LE, Duc-Anh on 5/23/15.
//

#include <string>
#include "Exception/cldeEntityStoreRoutineException.h"
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
                throw Exception::cldeEntityStoreRoutineException{msg};
            }

            auto &columnsForGet = _entityMap.getColumnsForGet();

            SPtrEntity entity = Foundation::CreateEntity(identity);

            Foundation::Store::Helper::EntityStoreHelper::GenerateCellsFromColumns(columnsForGet, entity, false);

            Insert(entity);

            return entity;
        }

        SPtrEntity EntityStore::Get(const SPtrIdentity &identity) {

            if(!identity){
                std::string msg{"Identity is either invalid or a nullptr"};
                throw Exception::cldeEntityStoreRoutineException{msg};
            }

            auto search = _identityMap.find(identity);

            if (search != _identityMap.end()) {
                return search->second;
            }

            auto &columnsForGet = _entityMap.getColumnsForGet();

            SPtrEntity sptrEntity = Foundation::CreateEntity(identity);

            Foundation::Store::Helper::EntityStoreHelper::GenerateCellsFromColumns(columnsForGet, sptrEntity, false);

            if (!_entitySourceDriver.Load(sptrEntity)) {
                return SPtrEntity(nullptr);
            }

            // Entity makes a copy of std::shared_ptr<Identity>,
            // Therefore, Identity must be taken from Entity
            _identityMap.insert(make_pair(sptrEntity->getIdentity(), sptrEntity));

            return sptrEntity;
        }

        void EntityStore::Insert(SPtrEntity &entity) {

            if(!entity){
                std::string msg{"Entity is either invalid or a nullptr"};
                throw Exception::cldeEntityStoreRoutineException{msg};
            }

            auto identity = entity->getIdentity();
            auto pairItem = make_pair(identity, entity);

            if (_entitySourceDriver.Insert(entity)) {
                _identityMap.insert(pairItem);
            }
        }

        void EntityStore::Save(SPtrEntity &entity) {

            if(!entity){
                std::string msg{"Entity is either invalid or a nullptr"};
                throw Exception::cldeEntityStoreRoutineException{msg};
            }

            _entitySourceDriver.Save(entity);
        }

        void EntityStore::Delete(SPtrEntity &entity) {

            if(!entity){
                std::string msg{"Entity shared pointer is either invalid or a nullptr"};
                throw Exception::cldeEntityStoreRoutineException{msg};
            }

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

        SPtrEntityStore CreateEntityStore(const EntityMap &entityMap, const EntitySourceDriver &entitySourceDriver) {
            return std::make_shared<EntityStore>(entityMap, entitySourceDriver);
        }
    }
}


