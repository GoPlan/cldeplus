//
// Created by LE, Duc Anh on 6/9/15.
//

#include "EntityQuery.h"
#include "EntityProxy.h"
#include "EntitySourceDriver.h"

namespace Cloude {
    namespace Foundation {

        EntityQuery::EntityQuery(const SPtrEntityStore &entityStore)
                : _entityStore(entityStore) {
            //
        }

        SPtrEntityProxyVector EntityQuery::Compose(const Query::SPtrCriteria &sptrCriteria) {

            auto &columnsForKey = _entityStore->getEntityMap().getColumnsForKey();
            auto &columnsForSelect = _entityStore->getEntityMap().getColumnsForSelect();
            auto size = columnsForKey.size() + columnsForSelect.size();

            SPtrColumnVector columnsForProjection;
            columnsForProjection.reserve(size);
            columnsForProjection.insert(columnsForProjection.end(), columnsForKey.begin(), columnsForKey.end());
            columnsForProjection.insert(columnsForProjection.cend(), columnsForSelect.begin(), columnsForSelect.end());

            return Compose(sptrCriteria, columnsForProjection);
        }

        SPtrEntityProxyVector EntityQuery::Compose(const Query::SPtrCriteria &sptrCriteria,
                                                   const SPtrColumnVector &columnsForProjection) {
            return _entityStore->getEntitySourceDriver().Select(sptrCriteria, columnsForProjection);
        }

        SPtrEntityProxy EntityQuery::ComposeGetFirst(const Query::SPtrCriteria &sptrCriteria) {
            return Compose(sptrCriteria).front();
        }
    }
}


