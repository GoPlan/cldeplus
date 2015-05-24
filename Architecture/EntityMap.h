//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITYMAP_H
#define CLOUD_E_CPLUS_ENTITYMAP_H

#include <vector>
#include <string>
#include <unordered_map>
#include "Column.h"

namespace Cloude {
    namespace Architecture {
        class EntityMap {
        public:
            EntityMap() { };

            virtual ~EntityMap() { };

            std::string TableName() {
                return TableNameCore();
            }

            const std::vector<std::shared_ptr<Column>> &getColumnsForKey() const {
                return _columnsForKey;
            }

            const std::vector<std::shared_ptr<Column>> &getColumnsForSelect() const {
                return _columnsForSelect;
            }

            const std::vector<std::shared_ptr<Column>> &getColumnsForUpdate() const {
                return _columnsForUpdate;
            }

            const std::unordered_map<std::string, std::shared_ptr<Column>> &getColumnsMap() const {
                return _columnsMap;
            }

        protected:
            std::vector<std::shared_ptr<Column>> _columnsForKey;
            std::vector<std::shared_ptr<Column>> _columnsForSelect;
            std::vector<std::shared_ptr<Column>> _columnsForUpdate;
            std::unordered_map<std::string, std::shared_ptr<Column>> _columnsMap;

            virtual std::string TableNameCore() = 0;
        };
    }
}


#endif //CLOUD_E_CPLUS_ENTITYMAP_H
