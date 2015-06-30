//
// Created by LE, Duc Anh on 6/30/15.
//

#include "CellTransformer.h"

namespace Cloude {
    namespace Foundation {

        Transformation::CellTransformer::CellTransformer(const SPtrColumn &sptrTargetColumn) {
            _sptrTargetColumn = sptrTargetColumn;
        }

        SPtrCell Transformation::CellTransformer::Transform(const SPtrCell &srcSPtrCell) const {
            SPtrCell sptrCell;
            return sptrCell;
        }
    }
}


