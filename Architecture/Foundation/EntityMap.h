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
                const vector<Column *> &ColumnsForKey() const {
                    return columnsForKey;
                }
                const vector<Column *> &ColumnsForSelect() const {
                    return columnsForSelect;
                }
                const vector<Column *> &ColumnsForUpdate() const {
                    return columnsForUpdate;
                }
                const unordered_map<string, Column *> &ColumnsMap() const {
                    return columnsMap;
                }

            protected:
                vector<Column *> columnsForKey;
                vector<Column *> columnsForSelect;
                vector<Column *> columnsForUpdate;
                unordered_map<string, Column *> columnsMap;

                virtual string TableNameCore() = 0;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITYMAP_H
