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

#include <memory>
#include "EntityStoreHelper.h"
#include "CellHelper.h"
#include "../../Exception/CLDEEntityStoreRoutineException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {
            namespace Helper {

                void EntityStoreHelper::GenerateCellsFromColumns(
                        CLDEPlus::Foundation::SPtrColumnVector const &columnVector,
                        CLDEPlus::Foundation::Store::SPtrDataRecord const &dataRecord,
                        bool checkCellExists) {

                    if (!dataRecord) {
                        string msg{"DataRecord can not be nullptr or undefined"};
                        throw Foundation::Exception::CLDEEntityStoreRoutineException{msg};
                    }

                    for (auto column : columnVector) {

                        if (checkCellExists && dataRecord->hasCell(column->getName())) {
                            continue;
                        }

                        auto cell = Foundation::Cell::CreateShared(const_cast<SPtrColumn &>(column));
                        dataRecord->setCell(cell);
                    }
                }

                SPtrEntityProxy EntityStoreHelper::CopySPtrProxy(SPtrEntityProxy const &proxy) {

                    SPtrEntityProxy newProxy = Foundation::EntityProxy::CreateUnique();

                    for (auto &srcCellPair : proxy->getCellsMap()) {
                        auto newCell = Foundation::Store::Helper::CellHelper::CopySPtrCell(srcCellPair.second);
                        newProxy->setCell(newCell);
                    }

                    return newProxy;
                }
            }
        }
    }
}


