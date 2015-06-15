//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

#include "Column.h"

namespace Cloude {
    namespace Foundation {

        class EntityMap {

        public:
            EntityMap() = default;
            EntityMap(const EntityMap &srcEntityMap) = default;
            EntityMap &operator=(const EntityMap &srcEntityMap) = default;
            virtual ~EntityMap() = default;

            const std::string &TableName() const {
                return TableNameCore();
            }

            const SPtrColumnVector &getColumnsForKey() const { return _columnsForKey; }
            const SPtrColumnVector &getColumnsForGet() const { return _columnsForGet; }
            const SPtrColumnVector &getColumnsForUpdate() const { return _columnsForUpdate; }
            const SPtrColumnVector &getColumnsForSelect() const { return _columnsForSelect; }

        protected:
            SPtrColumnVector _columnsForKey;
            SPtrColumnVector _columnsForGet;
            SPtrColumnVector _columnsForUpdate;
            SPtrColumnVector _columnsForSelect;

            virtual const std::string &TableNameCore() const = 0;
        };
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H
