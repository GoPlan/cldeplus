//
// Created by LE, Duc Anh on 6/2/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_STORE_HELPER_ENTITYSTOREHELPER_H
#define CLOUD_E_CPLUS_FOUNDATION_STORE_HELPER_ENTITYSTOREHELPER_H

#include "../../../Port/Definitions.h"
#include "../../EntityProxy.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {
            namespace Helper {
                struct EntityStoreHelper {
                    static SPtrEntityProxy CopySPtrProxy(SPtrEntityProxy const &proxy);
                    static void GenerateCellsFromColumns(SPtrColumnVector const &columnVector,
                                                         Store::SPtrDataRecord const &dataRecord,
                                                         bool checkCellExists = true);
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_STORE_HELPER_ENTITYSTOREHELPER_H
