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

#ifndef CLDEPLUS_ENTITYCELL_H
#define CLDEPLUS_ENTITYCELL_H

#include "CldePlus-Portable.h"
#include "EntityColumn.h"
#include "Value.h"
#include "Primitive.h"

namespace CLDEPlus {

    class EntityCell : public IPrintable {

        SPtrColumn _column;
        SPtrValue _value;

    public:
        explicit EntityCell(SPtrColumn const &column);
        explicit EntityCell(SPtrColumn const &column, SPtrValue const &value);
        EntityCell(EntityCell const &) = default;
        EntityCell(EntityCell &&) = default;
        EntityCell &operator=(EntityCell const &) = default;
        EntityCell &operator=(EntityCell &&) = default;
        ~EntityCell() = default;

        // IPrintable
        string CopyToString() const override;

        // Locals
        bool isNull() const { return _value.get() == nullptr; };
        SPtrColumn const &getColumn() const { return _column; }
        SPtrValue const &getValue() const { return _value; }
        void setValue(SPtrValue const &value);
        void setValue(IPrimitive const &value);

        // Factory methods
        static unique_ptr<EntityCell> CreateUnique(SPtrColumn const &column) { return cldeplus_make_unique<EntityCell>(column); }
        static unique_ptr<EntityCell> CreateUnique(SPtrColumn const &column, SPtrValue &value) { return cldeplus_make_unique<EntityCell>(column, value); }
        static shared_ptr<EntityCell> CreateShared(SPtrColumn const &column) { return cldeplus_make_shared<EntityCell>(column); }
        static shared_ptr<EntityCell> CreateShared(SPtrColumn const &column, SPtrValue &value) { return cldeplus_make_shared<EntityCell>(column, value); }
    };

    using Cell = EntityCell;
    using SPtrCell = shared_ptr<EntityCell>;
    using SPtrCellMap = unordered_map<string, SPtrCell>;
    using SPtrCellVector = vector<SPtrCell>;
}


#endif //CLDEPLUS_ENTITYCELL_H
