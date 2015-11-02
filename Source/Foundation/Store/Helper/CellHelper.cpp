//
// Created by LE, Duc Anh on 6/24/15.
//

#include "CellHelper.h"
#include "../../Data/Helper/ValueHelper.h"

namespace CLDEPlus {
    namespace Foundation {

        SPtrCell Store::Helper::CellHelper::CopySPtrCell(SPtrCell const &sptrCell) {

            Data::SPtrValue sptrValue = Data::Helper::ValueHelper::CopySPtrValue(sptrCell->getValue());
            SPtrColumn sptrColumn{new Column{*(sptrCell->getColumn())}};

            SPtrCell sptrNewCell{new Cell{sptrColumn}};
            sptrNewCell->setValue(sptrValue);

            return sptrNewCell;
        }
    }
}

