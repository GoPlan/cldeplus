//
// Created by LE, Duc Anh on 6/9/15.
//

#include "EntityQuery.h"

namespace Cloude {
    namespace Foundation {

        EntityQuery::EntityQuery(const EntityMap &entityMap, const EntitySourceDriver &entitySourceDriver)
                : _entityMap{entityMap}, _entitySourceDriver{entitySourceDriver} {
            //
        }

        SPtrEntityProxy EntityQuery::SelectFirst(const Query::SPtrCriteria &sptrCriteria) {
            return Select(sptrCriteria).front();
        }

        SPtrEntityProxyVector EntityQuery::Select(const Query::SPtrCriteria &sptrCriteria) {

            auto &columnsForKey = _entityMap.getColumnsForKey();
            auto &columnsForSelect = _entityMap.getColumnsForSelect();
            auto size = columnsForKey.size() + columnsForSelect.size();

            SPtrColumnVector columnsForProjection;
            columnsForProjection.reserve(size);
            columnsForProjection.insert(columnsForProjection.end(), columnsForKey.begin(), columnsForKey.end());
            columnsForProjection.insert(columnsForProjection.cend(), columnsForSelect.begin(), columnsForSelect.end());

            return Select(sptrCriteria, columnsForProjection);
        }

        SPtrEntityProxyVector EntityQuery::Select(const Query::SPtrCriteria &sptrCriteria,
                                                  const SPtrColumnVector &columnsForProjection) {
            return _entitySourceDriver.Select(sptrCriteria, columnsForProjection);
        }

        SPtrEntityQuery CreateEntityQuery(const EntityMap &entityMap, const EntitySourceDriver &entitySourceDriver) {
            return std::make_shared<EntityQuery>(entityMap, entitySourceDriver);
        }
    }
}


