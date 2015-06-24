//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_CELLHELPER_H
#define CLOUD_E_PLUS_CELLHELPER_H

#include <Foundation/Cell.h>

namespace Cloude {
    namespace Foundation {
        namespace Store {

            class CellHelper {

                CellHelper() = delete;
                CellHelper(const CellHelper &) = delete;
                CellHelper(CellHelper &&) = delete;
                CellHelper &operator=(const CellHelper &) = delete;
                CellHelper &operator=(CellHelper &&) = delete;
                virtual ~CellHelper() = delete;

            public:
                static SPtrCell CopySptrCell(const SPtrCell &sptrCell);

            };
        }
    }
}


#endif //CLOUD_E_PLUS_CELLHELPER_H
