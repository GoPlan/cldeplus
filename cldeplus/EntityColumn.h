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

#ifndef CLDEPLUS_ENTITYCOLUMN_H
#define CLDEPLUS_ENTITYCOLUMN_H

#include "CldePlus-Portable.h"
#include "CldePlus-Commons.h"
#include "Value.h"

namespace CLDEPlus {

    class EntityColumn : public IPrintable {

        string _name;
        string _datasourceName;
        ValueType _dataType;
        size_t _length;

    public:
        EntityColumn() = default;
        EntityColumn(string name, ValueType dataType);
        EntityColumn(string name, ValueType dataType, string datasourceName, size_t length);
        ~EntityColumn() = default;

        // IPrintable
        string CopyToString() const override;

        // Locals - Mutators
        void setDatasourceName(string const &datasourceName) { _datasourceName = datasourceName; }
        void setName(string const &name) { _name = name; }
        void setDataType(ValueType const &dataType) { _dataType = dataType; }
        void setLength(size_t length) { _length = length; }

        // Locals - Accessors
        string const &getDatasourceName() const { return _datasourceName; }
        string const &getName() const { return _name; }
        ValueType const &getDataType() const { return _dataType; }
        size_t getLength() const { return _length; }
    };

    using Column = EntityColumn;
    using SPtrColumn = shared_ptr<EntityColumn>;
    using SPtrColumnVector = vector<SPtrColumn>;
    using SPtrColumnMap = unordered_map<string, SPtrColumn>;

    SPtrColumn CreateColumn(string const &name, ValueType dataType);
    SPtrColumn CreateColumn(string const &name, ValueType dataType, string const &datasourceName, size_t length = 0);
}


#endif //CLDEPLUS_ENTITYCOLUMN_H
