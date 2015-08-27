//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_CELLHELPER_H
#define CLOUD_E_PLUS_CELLHELPER_H

#include "../../Cell.h"

namespace Cloude {
    namespace Foundation {
        namespace Store {
            namespace Helper {
                struct CellHelper {
                    static SPtrCell CopySPtrCell(const SPtrCell &sptrCell);
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_CELLHELPER_H
