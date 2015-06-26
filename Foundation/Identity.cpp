//
// Created by LE, Duc Anh on 14/05/2015.
//

#include "Identity.h"

namespace Cloude {
    namespace Foundation {

        Identity::Identity(const std::vector<SPtrCell> &fieldVector) {
            Store::AbstractionEntity::setMultiCells(fieldVector);
        }

        Identity::Identity(const std::vector<Cell *> &fieldVector) {
            Store::AbstractionEntity::setMultiCells(fieldVector);
        }
    }
}
