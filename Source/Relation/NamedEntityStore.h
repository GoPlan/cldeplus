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

#ifndef CLDEPLUS_RELATION_NAMEDENTITYSTORE_H
#define CLDEPLUS_RELATION_NAMEDENTITYSTORE_H

#include "NamedEntityLoader.h"
#include "Exception/NamedEntityStoreException.h"
#include "../Foundation/EntityStore.h"
#include "../Foundation/Query/Helper/ProxyHelper.h"

namespace CLDEPlus {
    namespace Relation {

        template<class TEntity>
        class NamedEntityStore : public Foundation::EntityStore,
                                 public std::enable_shared_from_this<NamedEntityStore<TEntity>> {

            NamedEntityLoader<TEntity> _entityLoader;

        public:
            NamedEntityStore(Foundation::SPtrEntityMap const &sptrEntityMap,
                             Foundation::SPtrEntitySourceDriver const &sptrEntitySourceDriver)
                    : Foundation::EntityStore{sptrEntityMap, sptrEntitySourceDriver} { };

            NamedEntityStore(const NamedEntityStore &) = default;
            NamedEntityStore(NamedEntityStore &&) = default;
            NamedEntityStore &operator=(NamedEntityStore const &) = default;
            NamedEntityStore &operator=(NamedEntityStore &&) = default;
            virtual ~NamedEntityStore() = default;

            // Mutators
            NamedEntityLoader<TEntity> &EntityLoader() { return _entityLoader; };

            // Locals
            Foundation::SPtrEntity Create() {

                if (!_entityLoader.fptrIdentityCreator) {
                    string msg{"Identity creator is not defined"};
                    throw Exception::NamedEntityStoreException{msg};
                }

                auto identity = (Foundation::SPtrIdentity) _entityLoader.fptrIdentityCreator();
                auto entity = Foundation::EntityStore::Create(identity);

                return entity;
            };

            Foundation::SPtrEntity Summon(Foundation::SPtrEntityProxy const &proxy) {
                auto sptrNamedStore = std::enable_shared_from_this<NamedEntityStore<TEntity>>::shared_from_this();
                auto sptrEntityStore = std::dynamic_pointer_cast<Foundation::EntityStore>(sptrNamedStore);
                return Foundation::Query::Helper::ProxyHelper::Summon(proxy, sptrEntityStore);
            };

            TEntity NamedEntity(Foundation::SPtrEntity const &entity) {

                if (!_entityLoader.fptrNamedEntityCreator) {
                    string msg{"NamedEntity creator is not defined"};
                    throw Exception::NamedEntityStoreException{msg};
                }

                return _entityLoader.fptrNamedEntityCreator(*entity);
            };
        };

        template<class TEntity>
        using SPtrNamedStore = shared_ptr<NamedEntityStore<TEntity>>;

        template<class TEntity>
        SPtrNamedStore<TEntity> CreateNamedStore(Foundation::SPtrEntityMap const &entityMap,
                                                 Foundation::SPtrEntitySourceDriver const &entitySourceDriver) {
            return cldeplus_make_shared<NamedEntityStore<TEntity>>(entityMap, entitySourceDriver);
        }
    }
}


#endif //CLDEPLUS_RELATION_NAMEDENTITYSTORE_H
