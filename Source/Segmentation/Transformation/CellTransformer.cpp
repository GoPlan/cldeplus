//
// Created by LE, Duc Anh on 6/30/15.
//

#include "../Exception/TransformationException.h"
#include "CellTransformer.h"

namespace CLDEPlus {
    namespace Segmentation {


        Transformation::CellTransformer::CellTransformer(Foundation::SPtrColumn const &targetColumn)
                : _sptrTargetColumn{targetColumn} {
            //
        }

        Transformation::CellTransformer::CellTransformer(Foundation::SPtrColumn const &targetColumn,
                                                         Transformation::SPtrCaster const &converter)
                : _sptrTargetColumn{targetColumn}, _sptrTypeConverter{converter} {
            //
        }

        Foundation::SPtrCell Transformation::CellTransformer::Transform(Foundation::SPtrCell const &srcSPtrCell) const {

            if (_sptrTargetColumn && _sptrTargetColumn->getDataType() != srcSPtrCell->getColumn()->getDataType()) {

                if (!_sptrTypeConverter) {
                    string msg{"Cell can not be transformed if source and destination types are different" \
                    "but converter is not provided"};
                    throw Exception::TransformationException{msg};
                }

                Foundation::SPtrCell dstSPtrCell = cldeplus_make_shared<Foundation::Cell>(_sptrTargetColumn);
                dstSPtrCell->setValue(_sptrTypeConverter->Cast(_sptrTargetColumn->getDataType(),
                                                               srcSPtrCell->getValue()));
                return dstSPtrCell;

            }
            else if (_sptrTargetColumn) {

                Foundation::SPtrCell dstSPtrCell = cldeplus_make_shared<Foundation::Cell>(_sptrTargetColumn);
                dstSPtrCell->setValue(srcSPtrCell->getValue());
                return dstSPtrCell;

            }
            else {

                return srcSPtrCell;

            }
        }
    }
}


