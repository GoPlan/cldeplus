//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLDEPLUS_CELLHELPER_H
#define CLDEPLUS_CELLHELPER_H

#include "../../Cell.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {
            namespace Helper {
                struct CellHelper {
                    static SPtrCell CopySPtrCell(SPtrCell const &sptrCell);
                };
            }
        }
    }
}


#endif //CLDEPLUS_CELLHELPER_H
