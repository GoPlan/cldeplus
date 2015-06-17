//
// Created by LE, Duc Anh on 6/16/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_ENTITYLINK_H
#define CLOUD_E_PLUS_FOUNDATION_ENTITYLINK_H

#include <unordered_map>
#include "Column.h"

namespace Cloude {
    namespace Foundation {

        enum class EntityLinkType {
            LinkToEntity,
            LinkToMany,
            LinkToOne
        };

        class EntityLink;

        using SPtrColumnToColumnMap = std::unordered_map<SPtrColumn, SPtrColumn>;
        using SPtrEntityLink = std::shared_ptr<EntityLink>;

        class EntityLink {

        public:
            EntityLink() = default;
            EntityLink(const EntityLink &) = delete;
            EntityLink(EntityLink &&) = delete;
            EntityLink &operator=(const EntityLink &) = delete;
            EntityLink &operator=(EntityLink &&) = delete;
            ~EntityLink() = default;

            // Locals
            const SPtrColumnToColumnMap &getColumnMap() const { return _columnMap; }
            const EntityLinkType &getLinkType() const { return _linkType; }

        private:
            SPtrColumnToColumnMap _columnMap;
            EntityLinkType _linkType;
        };
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_ENTITYLINK_H
