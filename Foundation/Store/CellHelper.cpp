//
// Created by LE, Duc Anh on 6/24/15.
//

#include "CellHelper.h"

namespace Cloude {
    namespace Foundation {

        SPtrCell Store::CellHelper::CopySptrCell(const SPtrCell &sptrCell) {

            SPtrColumn sptrColumn{new Column{*(sptrCell->getColumn())}};
            SPtrCell sptrNewCell{new Cell{sptrColumn}};

            return sptrNewCell;
        }
    }
}

