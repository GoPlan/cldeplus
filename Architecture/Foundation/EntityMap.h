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
                const std::vector<Column *> &columns_for_key() const {
                    return _columns_for_key;
                }
                const std::vector<Column *> &columns_for_select() const {
                    return _columns_for_select;
                }
                const std::vector<Column *> &columns_for_update() const {
                    return _columns_for_update;
                }
                const std::unordered_map<std::string, Column *> &columns_map() const {
                    return _columns_map;
                }
                
            protected:
                std::vector<Column *> _columns_for_key;
                std::vector<Column *> _columns_for_select;
                std::vector<Column *> _columns_for_update;
                std::unordered_map<std::string, Column *> _columns_map;

                virtual std::string TableNameCore() = 0;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITYMAP_H
