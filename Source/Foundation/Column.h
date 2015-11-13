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

#ifndef CLOUD_E_CPLUS_FOUNDATION_COLUMN_H
#define CLOUD_E_CPLUS_FOUNDATION_COLUMN_H

#include "../Portable/CommonTypes.h"
#include "Common/IPrintable.h"
#include "Data/TypeEnums.h"

namespace CLDEPlus {
    namespace Foundation {

        class Column : public Common::IPrintable {

            string _name;
            string _datasourceName;
            Data::ValueType _dataType;
            size_t _length;

        public:
            Column() = default;
            Column(string name, Data::ValueType dataType);
            Column(string name, Data::ValueType dataType, string datasourceName, size_t length);
            Column(Column const &) = default;
            Column(Column &&) = default;
            Column &operator=(Column const &) = default;
            Column &operator=(Column &&) = default;
            ~Column() = default;

            // IPrintable
            string ToString() const override;

            // Locals - Mutators
            void setDatasourceName(string const &datasourceName) { _datasourceName = datasourceName; }
            void setName(string const &name) { _name = name; }
            void setDataType(Data::ValueType const &dataType) { _dataType = dataType; }
            void setLength(size_t length) { _length = length; }

            // Locals - Accessors
            string const &getDatasourceName() const { return _datasourceName; }
            string const &getName() const { return _name; }
            Foundation::Data::ValueType const &getDataType() const { return _dataType; }
            size_t getLength() const { return _length; }
        };

        using SPtrColumn = shared_ptr<Column>;
        using SPtrColumnVector = vector<SPtrColumn>;
        using SPtrColumnMap = unordered_map<string, SPtrColumn>;

        SPtrColumn CreateColumn(string const &name, Data::ValueType dataType);
        SPtrColumn CreateColumn(string const &name, Data::ValueType dataType, string const &datasourceName, size_t length = 0);
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_COLUMN_H
