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

#include "ProxyHelper.h"

/// Summon solid entity from proxy from a store
/// If Identity can not be generated from selected columns, function throws an CLDEEntityException.
/// IsSummonable() should be check prior to this function call.

CLDEPlus::Foundation::SPtrEntity CLDEPlus::Foundation::Query::Helper::ProxyHelper::Summon(
        const SPtrEntityProxy &proxy,
        SPtrEntityStore &store) {

    if (!IsIdentifiableInStore(proxy, store)) {
        string msg{"Proxy is not summonable. See if selected columns are sufficient for Identity."};
        throw Exception::CLDEEntityException{msg};
    }

    Foundation::SPtrIdentity sptrIdentity = Identity::CreateUnique();

    std::for_each(store->getEntityMap()->getColumnsForKey().begin(),
                  store->getEntityMap()->getColumnsForKey().cend(),
                  [&sptrIdentity, &proxy](const Foundation::SPtrColumn &sptrColumn) {
                      auto &cell = proxy->getCell(sptrColumn->getName());
                      sptrIdentity->setCell(cell);
                  });

    auto entity = store->Get(sptrIdentity);

    return entity;
}

bool CLDEPlus::Foundation::Query::Helper::ProxyHelper::IsIdentifiableInStore(const SPtrEntityProxy &proxy,
                                                                           const SPtrEntityStore &store) {

    switch (proxy->getSummonState()) {
        case EntityProxy::EntityProxySummonState::Undefined: {

            auto &columnsForKey = store->getEntityMap()->getColumnsForKey();

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
