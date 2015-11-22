/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

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


