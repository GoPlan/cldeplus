//
// Created by LE, Duc Anh on 6/9/15.
//

#include <Foundation/Exception/cldeEntityException.h>
#include "EntityProxy.h"

namespace Cloude {
    namespace Foundation {

        EntityProxy::EntityProxy(SPtrIdentity &identity, EntityStore &entityStore)
                : Entity(identity), _entityStore(entityStore) {
            //
        }

        /// Summon solid entity from proxy.
        /// If Identity can not be generated from selected columns, function throws an cldeEntityException.
        /// IsSummonable() should be check prior to this function call.
        SPtrEntity EntityProxy::Summon() {

            if (!isSummonable()) {
                std::string msg{"Proxy is not summonable. See if selected columns are sufficient for Identity."};
                throw Exception::cldeEntityException{msg};
            }

            auto entity = _entityStore.Get(getIdentity());

            return entity;
        }

        EntityStore &EntityProxy::getEntityStore() const {
            return _entityStore;
        }

        bool EntityProxy::isSummonable() {
            switch (_summonState) {
                case EntityProxySummonState::Undefined: {

                    auto &columnsForKey = _entityStore.getEntityMap().getColumnsForKey();

                    for (auto &column : columnsForKey) {
                        if (getField(column->getName())->isNull())
                            _summonState = EntityProxySummonState::No;
                    }

                    _summonState = EntityProxySummonState::Yes;

                    return isSummonable();
                };
                case EntityProxySummonState::Yes:
                    return true;
                case EntityProxySummonState::No:
                    return false;
            };
        }
    }
}


