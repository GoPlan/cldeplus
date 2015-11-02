//
// Created by LE, Duc Anh on 14/05/2015.
//

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