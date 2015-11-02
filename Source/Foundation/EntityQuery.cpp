//
// Created by LE, Duc Anh on 6/9/15.
//

#include "EntityQuery.h"

namespace CLDEPlus {
    namespace Foundation {

        EntityQuery::EntityQuery(SPtrEntityMap const &sptrEntityMap,
                                 SPtrEntitySourceDriver const &sptrEntitySourceDriver)
                : _sptrEntityMap{sptrEntityMap}, _sptrEntitySourceDriver{sptrEntitySourceDriver} {
            //
        }

        SPtrEntityProxy EntityQuery::SelectFirst(Query::SPtrCriteria const &sptrCriteria) {
            return Select(sptrCriteria).front();
        }

        SPtrEntityProxyVector EntityQuery::Select(Query::SPtrCriteria const &sptrCriteria) {

            auto &columnsForKey = _sptrEntityMap->getColumnsForKey();
            auto &columnsForSelect = _sptrEntityMap->getColumnsForSelect();
            auto size = columnsForKey.size() + columnsForSelect.size();

            SPtrColumnVector columnsForProjection;
            columnsForProjection.reserve(size);
            columnsForProjection.insert(columnsForProjection.end(), columnsForKey.begin(), columnsForKey.end());
            columnsForProjection.insert(columnsForProjection.cend(), columnsForSelect.begin(), columnsForSelect.end());

            return Select(sptrCriteria, columnsForProjection);
        }

        SPtrEntityProxyVector EntityQuery::Select(Query::SPtrCriteria const &sptrCriteria,
                                                  SPtrColumnVector const &columnsForProjection) {
            return _sptrEntitySourceDriver->Select(sptrCriteria, columnsForProjection);
        }
    }
}


