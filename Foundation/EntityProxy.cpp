//
// Created by LE, Duc Anh on 6/9/15.
//

#include "EntityProxy.h"

namespace Cloude {
    namespace Foundation {

        EntityProxy::EntityProxy(SPtrIdentity &identity, EntityStore &entityStore)
                : Entity(identity), _entityStore(entityStore) {
            //
        }

        SPtrEntity EntityProxy::Summon() {
            auto entity = _entityStore.Get(_identity);
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


