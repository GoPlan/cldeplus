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
            EntityLink() = delete;
            ~EntityLink() = default;
            EntityLink(const EntityLink &) = default;
            EntityLink(EntityLink &&) = default;
            EntityLink &operator=(const EntityLink &) = default;
            EntityLink &operator=(EntityLink &&) = default;

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
