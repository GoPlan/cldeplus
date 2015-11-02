//
// Created by LE, Duc Anh on 7/9/15.
//

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
            NamedEntityStore(const Foundation::SPtrEntityMap &sptrEntityMap,
                             const Foundation::SPtrEntitySourceDriver &sptrEntitySourceDriver)
                    : Foundation::EntityStore{sptrEntityMap, sptrEntitySourceDriver} { };

            NamedEntityStore(const NamedEntityStore &) = default;
            NamedEntityStore(NamedEntityStore &&) = default;
            NamedEntityStore &operator=(const NamedEntityStore &) = default;
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

            Foundation::SPtrEntity Summon(const Foundation::SPtrEntityProxy &proxy) {
                auto sptrNamedStore = std::enable_shared_from_this<NamedEntityStore<TEntity>>::shared_from_this();
                auto sptrEntityStore = std::dynamic_pointer_cast<Foundation::EntityStore>(sptrNamedStore);
                return Foundation::Query::Helper::ProxyHelper::Summon(proxy, sptrEntityStore);
            };

            TEntity NamedEntity(const Foundation::SPtrEntity &entity) {

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
        SPtrNamedStore<TEntity> CreateNamedStore(const Foundation::SPtrEntityMap &entityMap,
                                                 const Foundation::SPtrEntitySourceDriver &entitySourceDriver) {
            return std::make_shared<NamedEntityStore<TEntity>>(entityMap, entitySourceDriver);
        }
    }
}


#endif //CLDEPLUS_RELATION_NAMEDENTITYSTORE_H
