//
// Created by LE, Duc Anh on 6/23/15.
//

#ifndef CLOUD_E_PLUS_CELLCOMPARER_H
#define CLOUD_E_PLUS_CELLCOMPARER_H

#include <Foundation/Cell.h>

namespace Cloude {
    namespace Foundation {
        namespace Comparer {

            struct CellEqual : std::binary_function<SPtrCell, SPtrCell, bool> {
                bool operator()(const SPtrCell lhs, const SPtrCell &rhs) const {
                    return true;
                };
            };
        }
    }
}


#endif //CLOUD_E_PLUS_CELLCOMPARER_H
