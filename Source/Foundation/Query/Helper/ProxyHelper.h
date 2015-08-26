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

                struct ProxyHelper {
                    static SPtrEntity Summon(const SPtrEntityProxy &proxy, SPtrEntityStore &store);
                    static bool IsIdentifiableInStore(const SPtrEntityProxy &proxy, const SPtrEntityStore &store);
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_PROXYHELPER_H
