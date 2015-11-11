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

#include "Cell.h"
#include "Data/Helper/TypeHelper.h"
#include "Exception/CLDEEntityException.h"

namespace CLDEPlus {
    namespace Foundation {

        Cell::Cell(SPtrColumn const &column) : _column(column) {
            //
        }

        Cell::Cell(SPtrColumn const &column, Data::SPtrValue const &value) : Cell{column} {
            setValue(value);
        }

        string Cell::ToString() const {
            string result{_value->ToString() + "(" + Data::Helper::TypeHelper::CopyValueTypeToString(_value->getDataType()) + ")"};
            return result;
        }

        void Cell::setValue(Data::SPtrValue const &value) {

            if (value->getDataType() != _column->getDataType()) {
                string msg{"Value has type "
                           + Data::Helper::TypeHelper::CopyValueTypeToString(value->getDataType())
                           + " that is different with column " + _column->ToString()
                           + "(" + Data::Helper::TypeHelper::CopyValueTypeToString(_column->getDataType()) + ")"};
                throw Exception::CLDEEntityException{msg};
            }

            _value = value;
        }

        void Cell::setValue(Data::IPrimitive const &value) {
            setValue(value.ToValue());
        }
    }
}