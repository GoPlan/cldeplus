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

#include "Column.h"
#include "Data/Helper/ValueEnumsHelper.h"

namespace CLDEPlus {
    namespace Foundation {


        Column::Column(string name, Data::ValueType dataType)
                : _name{name}, _dataType{dataType} {
            //
        }

        Column::Column(string name, Data::ValueType dataType, string datasourceName, size_t length)
                : _name{name}, _datasourceName{datasourceName}, _length{length}, _dataType{dataType} {
            //
        }

        string Column::ToString() const {
            string result{_name + "(" + Data::Helper::ValueEnumsHelper::CopyValueTypeToString(_dataType) +
                          "[" + std::to_string(_length) + "]" + ")"};
            return result;
        }

        SPtrColumn CreateColumn(string const &name, Data::ValueType dataType) {
            return cldeplus_make_shared<Column>(name, dataType);
        }

        SPtrColumn CreateColumn(string const &name, Data::ValueType dataType, string const &datasourceName, size_t length) {
            return cldeplus_make_shared<Column>(name, dataType, datasourceName, length);
        }
    }
}
