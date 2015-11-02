//
// Created by LE, Duc Anh on 6/2/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_STORE_HELPER_ENTITYSTOREHELPER_H
#define CLOUD_E_CPLUS_FOUNDATION_STORE_HELPER_ENTITYSTOREHELPER_H

#include "cldeplus_default"
#include "../../EntityProxy.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {
            namespace Helper {
                struct EntityStoreHelper {
                    static SPtrEntityProxy CopySPtrProxy(const SPtrEntityProxy &proxy);
                    static void GenerateCellsFromColumns(const SPtrColumnVector &columnVector,
                                                         const Store::SPtrDataRecord &dataRecord,
                                                         bool checkCellExists = true);
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_STORE_HELPER_ENTITYSTOREHELPER_H
