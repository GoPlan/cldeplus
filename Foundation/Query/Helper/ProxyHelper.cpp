//
// Created by LE, Duc Anh on 6/22/15.
//

#include <Foundation/EntityProxy.h>
#include "ProxyHelper.h"

/// Summon solid entity from proxy from a store
/// If Identity can not be generated from selected columns, function throws an cldeEntityException.
/// IsSummonable() should be check prior to this function call.

Cloude::Foundation::SPtrEntity Cloude::Foundation::Query::Helper::ProxyHelper::Summon(
        SPtrEntityProxy &proxy,
        SPtrEntityStore &store) {

    if (!IsIdentifiableInStore(proxy, store)) {
        std::string msg{"Proxy is not summonable. See if selected columns are sufficient for Identity."};
        throw Exception::cldeEntityException{msg};
    }

    Foundation::SPtrIdentity sptrIdentity{new Foundation::Identity{}};

    std::for_each(store->getEntityMap().getColumnsForKey().begin(),
                  store->getEntityMap().getColumnsForKey().cend(),
                  [&sptrIdentity, &proxy](const Foundation::SPtrColumn &sptrColumn) {
                      auto &cell = proxy->getCell(sptrColumn->getName());
                      sptrIdentity->setCell(cell);
                  });

    auto entity = store->Get(sptrIdentity);

    return entity;
}

bool Cloude::Foundation::Query::Helper::ProxyHelper::IsIdentifiableInStore(const SPtrEntityProxy &proxy,
                                                                           const SPtrEntityStore &store) {

    switch (proxy->getSummonState()) {
        case EntityProxy::EntityProxySummonState::Undefined: {

            auto &columnsForKey = store->getEntityMap().getColumnsForKey();

            for (auto &column : columnsForKey) {
                if (proxy->getCell(column->getName())->isNull())
                    proxy->setSummonState(EntityProxy::EntityProxySummonState::No);
            }

            proxy->setSummonState(EntityProxy::EntityProxySummonState::Yes);

            return IsIdentifiableInStore(proxy, store);
        };
        case EntityProxy::EntityProxySummonState::Yes:
            return true;
        case EntityProxy::EntityProxySummonState::No:
            return false;
    };
}
