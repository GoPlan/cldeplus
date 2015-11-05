//
// Created by LE, Duc Anh on 14/05/2015.
//

#include "Identity.h"

namespace CLDEPlus {
    namespace Foundation {

        Identity::Identity(vector<SPtrCell> const &sptrCells) {
            Store::AbstractEntity::setMultiCells(sptrCells);
        }
    }
}
