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

#include "CellHelper.h"
#include "../../Data/Helper/ValueHelper.h"

namespace CLDEPlus {
    namespace Foundation {

        SPtrCell Store::Helper::CellHelper::CopySPtrCell(SPtrCell const &sptrCell) {

            Data::SPtrValue sptrValue = Data::Helper::ValueHelper::CopySPtrValue(sptrCell->getValue());
            SPtrColumn sptrColumn{new Column{*(sptrCell->getColumn())}};

            SPtrCell sptrNewCell{new Cell{sptrColumn}};
            sptrNewCell->setValue(sptrValue);

            return sptrNewCell;
        }
    }
}
