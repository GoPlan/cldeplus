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

#ifndef CLDEPLUS_SEGMENTATION_TRANSFORMATION_CELLTRANSFORMER_H
#define CLDEPLUS_SEGMENTATION_TRANSFORMATION_CELLTRANSFORMER_H

#include "../../Foundation/Column.h"
#include "../../Foundation/Cell.h"
#include "TypeCaster.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Transformation {

            /// CellTransformer:
            /// Cast (copy) a cell into new cell with possibilities of transforming cell name and data type
            ///
            /// Note:
            /// New cell will use provided column if a shared pointer of column is provided.
            /// A converter must be provided if different data type is used or Transformation exception will be thrown.
            class CellTransformer {

                Foundation::SPtrColumn _sptrTargetColumn;
                SPtrCaster _sptrTypeConverter;

            public:
                CellTransformer() = default;
                CellTransformer(Foundation::SPtrColumn const &targetColumn);
                CellTransformer(Foundation::SPtrColumn const &targetColumn, const SPtrCaster &converter);
                CellTransformer(CellTransformer const &) = default;
                CellTransformer(CellTransformer &&) = default;
                CellTransformer &operator=(CellTransformer const &) = default;
                CellTransformer &operator=(CellTransformer &&) = default;
                virtual ~CellTransformer() = default;

                // Accessor
                const Foundation::SPtrColumn &TargetColumn() const { return _sptrTargetColumn; }
                const SPtrCaster &TypeConverter() const { return _sptrTypeConverter; }

                // Mutator
                void setTargetColumn(Foundation::SPtrColumn const &sptrTargetColumn) { _sptrTargetColumn = sptrTargetColumn; }
                void setTypeConverter(SPtrCaster const &sptrTypeConverter) { _sptrTypeConverter = sptrTypeConverter; }

                // Locals
                virtual Foundation::SPtrCell Transform(Foundation::SPtrCell const &srcSPtrCell) const;
            };

            using SPtrCellTransformer = shared_ptr<CellTransformer>;
            using SPtrCellTransformerMap = unordered_map<string, Transformation::SPtrCellTransformer>;
            using CellTransformerMap = unordered_map<string, Transformation::CellTransformer>;
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_TRANSFORMATION_CELLTRANSFORMER_H
