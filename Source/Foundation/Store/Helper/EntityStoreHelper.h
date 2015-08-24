//
// Created by LE, Duc Anh on 6/2/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_STORE_HELPER_ENTITYSTOREHELPER_H
#define CLOUD_E_CPLUS_FOUNDATION_STORE_HELPER_ENTITYSTOREHELPER_H

#include <memory>
#include <vector>
#include "../../EntityProxy.h"

namespace Cloude {
    namespace Foundation {
        namespace Store {
            namespace Helper {

                class EntityStoreHelper {

                    EntityStoreHelper() = delete;
                    EntityStoreHelper(const EntityStoreHelper &) = delete;
                    EntityStoreHelper(EntityStoreHelper &&) = delete;
                    EntityStoreHelper &operator=(const EntityStoreHelper &) = delete;
                    EntityStoreHelper &operator=(EntityStoreHelper &&) = delete;
                    ~EntityStoreHelper() = delete;

                public:
                    static void GenerateCellsFromColumns(const SPtrColumnVector &columnVector,
                                                         const Store::SPtrDataRecord &dataRecord,
                                                         bool checkCellExists = true);

                    static SPtrEntityProxy CopySPtrProxy(const SPtrEntityProxy &proxy);
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_STORE_HELPER_ENTITYSTOREHELPER_H
