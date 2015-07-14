//
// Created by LE, Duc Anh on 14/05/2015.
//

#include "Identity.h"

namespace Cloude {
    namespace Foundation {

        Identity::Identity(const std::vector<SPtrCell> &fieldVector) {
            Store::AbstractEntity::setMultiCells(fieldVector);
        }

        Identity::Identity(const std::vector<Cell *> &fieldVector) {
            Store::AbstractEntity::setMultiCells(fieldVector);
        }

        SPtrIdentity CreateIdentity() {
            return std::make_shared<Identity>();
        }

        SPtrIdentity CreateIdentity(const std::vector<SPtrCell> &cells) {
            return std::make_shared<Identity>(cells);
        }

        SPtrIdentity CreateIdentity(const std::vector<Cell *> &cells) {
            return std::make_shared<Identity>(cells);
        }
    }
}
