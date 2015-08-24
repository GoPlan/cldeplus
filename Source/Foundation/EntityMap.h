//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H

#include <memory>
#include <vector>
#include <string>
#include "Column.h"

namespace Cloude {
    namespace Foundation {

        class EntityMap {

        public:
            EntityMap(const EntityMap &) = delete;
            EntityMap(EntityMap &&) = delete;
            EntityMap &operator=(const EntityMap &) = delete;
            EntityMap &operator=(EntityMap &&) = delete;
            virtual ~EntityMap() = default;

            const std::string &getTableName() const { return TableNameCore(); }

            const SPtrColumnVector &getColumnsForKey() const { return _columnsForKey; }
            const SPtrColumnVector &getColumnsForGet() const { return _columnsForGet; }
            const SPtrColumnVector &getColumnsForUpdate() const { return _columnsForUpdate; }
            const SPtrColumnVector &getColumnsForSelect() const { return _columnsForSelect; }

        protected:
            EntityMap() = default;

            SPtrColumnVector _columnsForKey;
            SPtrColumnVector _columnsForGet;
            SPtrColumnVector _columnsForUpdate;
            SPtrColumnVector _columnsForSelect;

            virtual const std::string &TableNameCore() const = 0;
        };

        using SPtrEntityMap = std::shared_ptr<EntityMap>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H
