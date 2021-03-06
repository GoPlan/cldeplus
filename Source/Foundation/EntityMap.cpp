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

#include "EntityMap.h"

namespace CLDEPlus {
    namespace Foundation {

        bool EntityMap::HasColumn(string const &name) const {
            return _columnsMap.find(name) != _columnsMap.cend();
        }

        void EntityMap::SetColumn(string const &name, SPtrColumn const &sptrColumn) {
            _columnsMap[name] = sptrColumn;
        }

        SPtrColumn const &EntityMap::GetColumn(string const &name) const {

            auto pair = _columnsMap.find(name);

            if (_columnsMap.find(name) == _columnsMap.cend()) {
                string message{"Column " + name + " is not found in " + _tableName};
                throw Exception::CLDEEntityMapException{message};
            }

            return pair->second;
        }
    }
}