/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include "EntitySourceDriver.h"
#include "cldeEntityStoreRoutineException.h"
#include "Store/Helper/EntityStoreHelper.h"

namespace CLDEPlus {
    namespace Foundation {

        EntityStore::EntityStore(SPtrEntityMap const &sptrEntityMap,
                                 SPtrEntitySourceDriver const &sptrEntitySourceDriver)
                : _sptrEntityMap(sptrEntityMap), _sptrEntitySourceDriver(sptrEntitySourceDriver) {
            //
        }

        bool EntityStore::HasIdentityInMap(SPtrIdentity const &identity) const {
            return !(_identityMap.find(identity) == _identityMap.end());
        }

        SPtrEntity EntityStore::Create(SPtrIdentity const &identity) {

            if (!identity) {
                string msg{"Identity is either a nullptr or invalid"};
                throw Exception::CLDEEntityStoreRoutineException{msg};
            }

            auto &columnsForGet = _sptrEntityMap->getColumnsForGet();

            SPtrEntity entity = Foundation::Entity::CreateUnique(identity);

            Foundation::Store::Helper::EntityStoreHelper::GenerateCellsFromColumns(columnsForGet, entity, false);

            Insert(entity);

            return entity;
        }

        SPtrEntity EntityStore::Get(SPtrIdentity const &identity) {

            if (!identity) {
                string msg{"Identity is either invalid or a nullptr"};
                throw Exception::CLDEEntityStoreRoutineException{msg};
            }

            auto search = _identityMap.find(identity);

            if (search != _identityMap.end()) {
                return search->second;
            }

            auto &columnsForGet = _sptrEntityMap->getColumnsForGet();

            SPtrEntity sptrEntity = Foundation::Entity::CreateUnique(identity);

            Foundation::Store::Helper::EntityStoreHelper::GenerateCellsFromColumns(columnsForGet, sptrEntity, false);

            if (!_sptrEntitySourceDriver->Load(sptrEntity)) {
                return SPtrEntity(nullptr);
            }

            // Entity makes a copy of shared_ptr<Identity>,
            // Therefore, Identity must be taken from Entity
            _identityMap.insert(make_pair(sptrEntity->getIdentity(), sptrEntity));

            return sptrEntity;
        }

        void EntityStore::Insert(SPtrEntity &entity) {

            if (!entity) {
                string msg{"Entity is either invalid or a nullptr"};
                throw Exception::CLDEEntityStoreRoutineException{msg};
            }

            auto identity = entity->getIdentity();
            auto pairItem = make_pair(identity, entity);

            if (_sptrEntitySourceDriver->Insert(entity)) {
                _identityMap.insert(pairItem);
            }
        }

        void EntityStore::Save(SPtrEntity &entity) {

            if (!entity) {
                string msg{"Entity is either invalid or a nullptr"};
                throw Exception::CLDEEntityStoreRoutineException{msg};
            }

            _sptrEntitySourceDriver->Save(entity);
        }

        void EntityStore::Delete(SPtrEntity &entity) {

            if (!entity) {
                string msg{"Entity shared pointer is either invalid or a nullptr"};
                throw Exception::CLDEEntityStoreRoutineException{msg};
            }

            if (_sptrEntitySourceDriver->Delete(entity)) {
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


