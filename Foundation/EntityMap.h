//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITYMAP_H
#define CLOUD_E_CPLUS_ENTITYMAP_H

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

            const std::string& TableName() const {
                return TableNameCore();
            }

            const std::vector<std::shared_ptr<Column>> &getColumnsForKey() const {
                return _columnsForKey;
            }

            const std::vector<std::shared_ptr<Column>> &getColumnsForGet() const {
                return _columnsForGet;
            }

            const std::vector<std::shared_ptr<Column>> &getColumnsForUpdate() const {
                return _columnsForUpdate;
            }

            const std::vector<std::shared_ptr<Column>> &getColumnsForSelect() const {
                return _columnsForSelect;
            }

        protected:
            std::vector<std::shared_ptr<Column>> _columnsForKey;
            std::vector<std::shared_ptr<Column>> _columnsForGet;
            std::vector<std::shared_ptr<Column>> _columnsForUpdate;
            std::vector<std::shared_ptr<Column>> _columnsForSelect;

            virtual const std::string& TableNameCore() const = 0;
        };
    }
}


#endif //CLOUD_E_CPLUS_ENTITYMAP_H
