//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Data/Helper/ValueHelper.h>
#include "CellHelper.h"

namespace Cloude {
    namespace Foundation {

        SPtrCell Store::Helper::CellHelper::CopySPtrCell(const SPtrCell &sptrCell) {

            Data::SPtrValue sptrValue = Data::Helper::ValueHelper::CopySPtrValue(sptrCell->getValue());
            SPtrColumn sptrColumn{new Column{*(sptrCell->getColumn())}};

            SPtrCell sptrNewCell{new Cell{sptrColumn}};
            sptrNewCell->setValue(sptrValue);

            return sptrNewCell;
        }
    }
}

