//
// Created by LE, Duc Anh on 6/30/15.
//

#include "CellTransformer.h"

namespace Cloude {
    namespace Segmentation {

        Foundation::SPtrCell Transformation::CellTransformer::Transform(const Foundation::SPtrCell &srcSPtrCell) const {
            if (_sptrTargetColumn) {

                Foundation::SPtrCell dstSPtrCell = std::make_shared<Foundation::Cell>(_sptrTargetColumn);

                if (_sptrTypeConverter) {
                    dstSPtrCell->setValue(_sptrTypeConverter->Convert(_sptrTargetColumn, srcSPtrCell->getValue()));
                } else {
                    dstSPtrCell->setValue(srcSPtrCell->getValue());
                }

                return dstSPtrCell;

            } else {

                return srcSPtrCell;

            }
        }
    }
}


