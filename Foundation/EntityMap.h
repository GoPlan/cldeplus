//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

#include "Column.h"
#include "EntityLink.h"

namespace Cloude {
    namespace Foundation {

        using LinkMap = std::unordered_map<std::string, EntityLink>;

        class EntityMap {

        public:
            EntityMap(const EntityMap &) = delete;
            EntityMap(EntityMap &&) = delete;
            EntityMap &operator=(const EntityMap &) = delete;
            EntityMap &operator=(EntityMap &&) = delete;
            virtual ~EntityMap() = default;

            const std::string &TableName() const {
                return TableNameCore();
            }

            const SPtrColumnVector &getColumnsForKey() const { return _columnsForKey; }
            const SPtrColumnVector &getColumnsForGet() const { return _columnsForGet; }
            const SPtrColumnVector &getColumnsForUpdate() const { return _columnsForUpdate; }
            const SPtrColumnVector &getColumnsForSelect() const { return _columnsForSelect; }

            const LinkMap &getLinkMap() const { return _linkMap; }

        protected:
            EntityMap() = default;

            SPtrColumnVector _columnsForKey;
            SPtrColumnVector _columnsForGet;
            SPtrColumnVector _columnsForUpdate;
            SPtrColumnVector _columnsForSelect;

            LinkMap _linkMap;

            virtual const std::string &TableNameCore() const = 0;
        };
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H
