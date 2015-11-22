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

#include "EntityCell.h"
#include "EntityException.h"
#include "Data/Helper/ValueEnumsHelper.h"

namespace CLDEPlus {

    EntityCell::EntityCell(SPtrColumn const &column) : _column(column) {
        //
    }

    EntityCell::EntityCell(SPtrColumn const &column, SPtrValue const &value) : EntityCell{column} {
        setValue(value);
    }

    string EntityCell::CopyToString() const {
        string result{_value->CopyToString() + "(" + Data::Helper::ValueEnumsHelper::CopyValueTypeToString(_value->getDataType()) + ")"};
        return result;
    }

    void EntityCell::setValue(SPtrValue const &value) {

        if (value->getDataType() != _column->getDataType()) {
            string msg{"Value has type "
                       + Data::Helper::ValueEnumsHelper::CopyValueTypeToString(value->getDataType())
                       + " that is different with column " + _column->CopyToString()
                       + "(" + Data::Helper::ValueEnumsHelper::CopyValueTypeToString(_column->getDataType()) + ")"};
            throw EntityException{msg};
        }

        _value = value;
    }

    void EntityCell::setValue(IPrimitive const &value) {
        setValue(value.ToValue());
    }
}