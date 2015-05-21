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
        namespace Foundation {

            class EntityMap {

            public:
                EntityMap() { };
                virtual ~EntityMap() { };

                std::string TableName() {
                    return TableNameCore();
                }

                const std::vector<Column *> &getColumnsForKey() const {
                    return _columnsForKey;
                }
                const std::vector<Column *> &getColumnsForSelect() const {
                    return _columnsForSelect;
                }
                const std::vector<Column *> &getColumnsForUpdate() const {
                    return _columnsForUpdate;
                }
                const std::unordered_map<std::string, Column *> &getColumnsMap() const {
                    return _columnsMap;
                }
            protected:
                std::vector<Column *> _columnsForKey;
                std::vector<Column *> _columnsForSelect;
                std::vector<Column *> _columnsForUpdate;
                std::unordered_map<std::string, Column *> _columnsMap;

                virtual std::string TableNameCore() = 0;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITYMAP_H
