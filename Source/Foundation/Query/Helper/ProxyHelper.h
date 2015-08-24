//
// Created by LE, Duc Anh on 6/22/15.
//

#ifndef CLOUD_E_PLUS_PROXYHELPER_H
#define CLOUD_E_PLUS_PROXYHELPER_H

#include "../../Entity.h"
#include "../../EntityStore.h"
#include "../../EntityProxy.h"
#include "../../Exception/CLDEEntityException.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Helper {

                class ProxyHelper {

                public:
                    static SPtrEntity Summon(const SPtrEntityProxy &proxy, SPtrEntityStore &store);
                    static bool IsIdentifiableInStore(const SPtrEntityProxy &proxy, const SPtrEntityStore &store);

                public:
                    ProxyHelper() = delete;
                    ProxyHelper(const ProxyHelper &) = delete;
                    ProxyHelper(ProxyHelper &&) = delete;
                    ProxyHelper &operator=(const ProxyHelper &) = delete;
                    ProxyHelper &operator=(ProxyHelper &&) = delete;
                    virtual ~ProxyHelper() = delete;

                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_PROXYHELPER_H
