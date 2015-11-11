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

        SPtrEntityProxyVector EntityQuery::Select(Query::SPtrCriteria const &sptrCriteria, SPtrColumnVector const &columnsForProjection) {
            return _sptrEntitySourceDriver->Select(sptrCriteria, columnsForProjection);
        }
    }
}


