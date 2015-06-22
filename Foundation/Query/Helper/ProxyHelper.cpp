//
// Created by LE, Duc Anh on 6/22/15.
//

#include <Foundation/EntityProxy.h>
#include "ProxyHelper.h"

/// Summon solid entity from proxy from a store
/// If Identity can not be generated from selected columns, function throws an cldeEntityException.
/// IsSummonable() should be check prior to this function call.

Cloude::Foundation::SPtrEntity Cloude::Foundation::Query::Helper::ProxyHelper::Summon(
        SPtrEntityProxy &entityProxy,
        SPtrEntityStore &entityStore) {

    if (!isIdentifiableInStore(entityProxy, entityStore)) {
        std::string msg{"Proxy is not summonable. See if selected columns are sufficient for Identity."};
        throw Exception::cldeEntityException{msg};
    }

    Foundation::SPtrIdentity sptrIdentity{new Foundation::Identity{}};

    std::for_each(entityStore->getEntityMap().getColumnsForKey().begin(),
                  entityStore->getEntityMap().getColumnsForKey().cend(),
                  [&sptrIdentity, &entityProxy](const Foundation::SPtrColumn &sptrColumn) {
                      auto &cell = entityProxy->getCell(sptrColumn->getName());
                      sptrIdentity->setCell(cell);
                  });

    auto entity = entityStore->Get(sptrIdentity);

    return entity;
}

bool Cloude::Foundation::Query::Helper::ProxyHelper::isIdentifiableInStore(const SPtrEntityProxy &entityProxy,
                                                                           const SPtrEntityStore &entityStore) {

    switch (entityProxy->getSummonState()) {
        case EntityProxy::EntityProxySummonState::Undefined: {

            auto &columnsForKey = entityStore->getEntityMap().getColumnsForKey();

            for (auto &column : columnsForKey) {
                if (entityProxy->getCell(column->getName())->isNull())
                    entityProxy->setSummonState(EntityProxy::EntityProxySummonState::No);
            }

            entityProxy->setSummonState(EntityProxy::EntityProxySummonState::Yes);

            return isIdentifiableInStore(entityProxy, entityStore);
        };
        case EntityProxy::EntityProxySummonState::Yes:
            return true;
        case EntityProxy::EntityProxySummonState::No:
            return false;
    };
}
