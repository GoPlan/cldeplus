/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#ifndef CLEPLUS_ENTITYMAP_H
#define CLEPLUS_ENTITYMAP_H

#include "CldePlus-Portable.h"
#include "EntityColumn.h"

namespace CLDEPlus {

    class EntityMap {

    public:
        EntityMap(string const &tableName) : _tableName{tableName} { };
        EntityMap(EntityMap const &) = default;
        EntityMap(EntityMap &&) = default;
        EntityMap &operator=(EntityMap const &) = default;
        EntityMap &operator=(EntityMap &&) = default;
        virtual ~EntityMap() = default;

        string const &getTableName() const { return _tableName; }
        SPtrColumnMap const &getColumnsMap() const { return _columnsMap; }
        SPtrColumnVector const &getColumnsForKey() const { return _columnsForKey; }
        SPtrColumnVector const &getColumnsForGet() const { return _columnsForGet; }
        SPtrColumnVector const &getColumnsForUpdate() const { return _columnsForUpdate; }
        SPtrColumnVector const &getColumnsForSelect() const { return _columnsForSelect; }

        bool HasColumn(string const &name) const;
        void SetColumn(string const &name, SPtrColumn const &sptrColumn);
        SPtrColumn const &GetColumn(string const &name) const;

        void AddGetColumn(SPtrColumn const &sptrColumn) { _columnsForGet.push_back(sptrColumn); }
        void AddKeyColumn(SPtrColumn const &sptrColumn) { _columnsForKey.push_back(sptrColumn); }
        void AddUpdateColumn(SPtrColumn const &sptrColumn) { _columnsForUpdate.push_back(sptrColumn); }
        void AddSelectColumn(SPtrColumn const &sptrColumn) { _columnsForSelect.push_back(sptrColumn); }

    protected:

        SPtrColumnMap _columnsMap;
        SPtrColumnVector _columnsForKey;
        SPtrColumnVector _columnsForGet;
        SPtrColumnVector _columnsForUpdate;
        SPtrColumnVector _columnsForSelect;

        string _tableName;
    };

    using UPtrEntityMap = unique_ptr<EntityMap>;
    using SPtrEntityMap = shared_ptr<EntityMap>;
}


#endif //CLEPLUS_ENTITYMAP_H
