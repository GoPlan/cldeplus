//
// Created by LE, Duc Anh on 6/9/15.
//

#include "EntityProxy.h"
#include "Exception/CLDEEntityException.h"
#include "Query/Helper/ProxyHelper.h"

namespace CLDEPlus {
    namespace Foundation {

        SPtrEntity EntityProxy::Summon(SPtrEntityStore &entityStore) {
            auto shared = shared_from_this();
            return Query::Helper::ProxyHelper::Summon(shared, entityStore);
        }

        bool EntityProxy::IsIdentifiableInStore(SPtrEntityStore &entityStore) {
            return Query::Helper::ProxyHelper::IsIdentifiableInStore(shared_from_this(), entityStore);
        }
    }
}


