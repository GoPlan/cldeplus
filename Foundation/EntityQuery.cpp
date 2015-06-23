//
// Created by LE, Duc Anh on 6/9/15.
//

#include "EntityQuery.h"
#include "EntitySourceDriver.h"

namespace Cloude {
    namespace Foundation {

        EntityQuery::EntityQuery(const SPtrEntityStore &entityStore)
                : _entityStore(entityStore) {
            //
        }

        SPtrEntityProxy EntityQuery::ComposeGetFirst(const Query::SPtrCriteria &sptrCriteria) {
            return ComposeVector(sptrCriteria).front();
        }

        SPtrEntityProxyVector EntityQuery::ComposeVector(const Query::SPtrCriteria &sptrCriteria) {

            auto &columnsForKey = _entityStore->getEntityMap().getColumnsForKey();
            auto &columnsForSelect = _entityStore->getEntityMap().getColumnsForSelect();
            auto size = columnsForKey.size() + columnsForSelect.size();

            SPtrColumnVector columnsForProjection;
            columnsForProjection.reserve(size);
            columnsForProjection.insert(columnsForProjection.end(), columnsForKey.begin(), columnsForKey.end());
            columnsForProjection.insert(columnsForProjection.cend(), columnsForSelect.begin(), columnsForSelect.end());

            return ComposeVector(sptrCriteria, columnsForProjection);
        }

        SPtrEntityProxyVector EntityQuery::ComposeVector(const Query::SPtrCriteria &sptrCriteria,
                                                         const SPtrColumnVector &columnsForProjection) {
            return _entityStore->getEntitySourceDriver().SelectVector(sptrCriteria, columnsForProjection);
        }

        SPtrEntityProxySet EntityQuery::ComposeSet(const Query::SPtrCriteria &sptrCriteria) {

            auto &columnsForKey = _entityStore->getEntityMap().getColumnsForKey();
            auto &columnsForSelect = _entityStore->getEntityMap().getColumnsForSelect();
            auto size = columnsForKey.size() + columnsForSelect.size();

            SPtrColumnVector columnsForProjection;
            columnsForProjection.reserve(size);
            columnsForProjection.insert(columnsForProjection.end(), columnsForKey.begin(), columnsForKey.end());
            columnsForProjection.insert(columnsForProjection.cend(), columnsForSelect.begin(), columnsForSelect.end());

            return ComposeSet(sptrCriteria, columnsForProjection);
        }

        SPtrEntityProxySet EntityQuery::ComposeSet(const Query::SPtrCriteria &sptrCriteria,
                                                   const SPtrColumnVector &columnsForProjection) {
            return _entityStore->getEntitySourceDriver().SelectSet(sptrCriteria, columnsForProjection);
        }
    }
}


