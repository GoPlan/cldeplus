//
// Created by LE, Duc Anh on 6/2/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_STORE_ENTITYSTOREHELPER_H
#define CLOUD_E_CPLUS_FOUNDATION_STORE_ENTITYSTOREHELPER_H

#include <memory>
#include <vector>
#include <Foundation/Entity.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            void GenerateFieldsFromColumns (const SPtrColumnVector &columnVector,
                                            SPtrEntity &entity,
                                            bool checkIfFieldExists);

        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_STORE_ENTITYSTOREHELPER_H
