//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Type/Helper/cldeValueHelper.h>
#include "CellHelper.h"

namespace Cloude {
    namespace Foundation {

        SPtrCell Store::Helper::CellHelper::CopySptrCell(const SPtrCell &sptrCell) {

            Type::SPtrValue sptrValue = Type::Helper::cldeValueHelper::CopySPtrValue(sptrCell->getValue());
            SPtrColumn sptrColumn{new Column{*(sptrCell->getColumn())}};

            SPtrCell sptrNewCell{new Cell{sptrColumn}};
            sptrNewCell->setValue(sptrValue);

            return sptrNewCell;
        }
    }
}

