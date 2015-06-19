//
// Created by LE, Duc Anh on 6/9/15.
//

#include <Foundation/Exception/cldeEntityException.h>
#include "EntityProxy.h"

namespace Cloude {
    namespace Foundation {

        /// Summon solid entity from proxy from a store
        /// If Identity can not be generated from selected columns, function throws an cldeEntityException.
        /// IsSummonable() should be check prior to this function call.
        SPtrEntity EntityProxy::Summon(EntityStore &entityStore) const {

            if (!isIdentifiableInStore(entityStore)) {
                std::string msg{"Proxy is not summonable. See if selected columns are sufficient for Identity."};
                throw Exception::cldeEntityException{msg};
            }

            Foundation::SPtrIdentity sptrIdentity{new Foundation::Identity{}};

            std::for_each(entityStore.getEntityMap().getColumnsForKey().begin(),
                          entityStore.getEntityMap().getColumnsForKey().cend(),
                          [&sptrIdentity, this](const Foundation::SPtrColumn &sptrColumn) {
                              auto &field = getField(sptrColumn->getName());
                              sptrIdentity->setField(field);
                          });

            auto entity = entityStore.Get(sptrIdentity);

            return entity;
        }

        bool EntityProxy::isIdentifiableInStore(const EntityStore &entityStore) const {

            switch (_summonState) {
                case EntityProxySummonState::Undefined: {

                    auto &columnsForKey = entityStore.getEntityMap().getColumnsForKey();

                    for (auto &column : columnsForKey) {
                        if (getField(column->getName())->isNull())
                            _summonState = EntityProxySummonState::No;
                    }

                    _summonState = EntityProxySummonState::Yes;

                    return isIdentifiableInStore(entityStore);
                };
                case EntityProxySummonState::Yes:
                    return true;
                case EntityProxySummonState::No:
                    return false;
            };
        }
    }
}


