//
// Created by LE, Duc Anh on 6/30/15.
//

#include "../Exception/TransformationException.h"
#include "CellTransformer.h"

namespace Cloude {
    namespace Segmentation {


        Transformation::CellTransformer::CellTransformer(const Foundation::SPtrColumn &targetColumn)
                : _sptrTargetColumn{targetColumn} {
            //
        }

        Transformation::CellTransformer::CellTransformer(const Foundation::SPtrColumn &targetColumn,
                                                         const Transformation::SPtrTypeConverter &converter)
                : _sptrTargetColumn{targetColumn}, _sptrTypeConverter{converter} {
            //
        }

        Foundation::SPtrCell Transformation::CellTransformer::Transform(const Foundation::SPtrCell &srcSPtrCell) const {

            if (_sptrTargetColumn && _sptrTargetColumn->getDataType() != srcSPtrCell->getColumn()->getDataType()) {

                if (!_sptrTypeConverter) {
                    std::string msg{"Cell can not be transformed if source and destination types are different" \
                    "but converter is not provided"};
                    throw Exception::TransformationException{msg};
                }

                Foundation::SPtrCell dstSPtrCell = std::make_shared<Foundation::Cell>(_sptrTargetColumn);
                dstSPtrCell->setValue(_sptrTypeConverter->Cast(_sptrTargetColumn->getDataType(),
                                                               srcSPtrCell->getValue()));
                return dstSPtrCell;

            } else if (_sptrTargetColumn) {

                Foundation::SPtrCell dstSPtrCell = std::make_shared<Foundation::Cell>(_sptrTargetColumn);
                dstSPtrCell->setValue(srcSPtrCell->getValue());
                return dstSPtrCell;

            }
            else {

                return srcSPtrCell;

            }
        }
    }
}


