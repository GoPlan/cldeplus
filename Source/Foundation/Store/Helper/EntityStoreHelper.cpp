//
// Created by LE, Duc Anh on 6/2/15.
//

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

                        SPtrCell cell = Foundation::Cell::Create(const_cast<SPtrColumn &>(column));
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


