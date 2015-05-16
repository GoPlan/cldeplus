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

                string TableName() {
                    return TableNameCore();
                }
                const vector<Column *> &columns_for_key() const {
                    return _columns_for_key;
                }
                const vector<Column *> &columns_for_select() const {
                    return _columns_for_select;
                }
                const vector<Column *> &columns_for_update() const {
                    return _columns_for_update;
                }
                const unordered_map<string, Column *> &columns_map() const {
                    return _columns_map;
                }
                
            protected:
                vector<Column *> _columns_for_key;
                vector<Column *> _columns_for_select;
                vector<Column *> _columns_for_update;
                unordered_map<string, Column *> _columns_map;

                virtual string TableNameCore() = 0;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITYMAP_H
