//
// Created by LE, Duc Anh on 6/30/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CELLTRANSFORMER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CELLTRANSFORMER_H

#include <Foundation/Column.h>
#include <Foundation/Cell.h>
#include "TypeCaster.h"

namespace Cloude {
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
                CellTransformer(const Foundation::SPtrColumn &targetColumn);
                CellTransformer(const Foundation::SPtrColumn &targetColumn, const SPtrCaster &converter);
                CellTransformer(const CellTransformer &) = default;
                CellTransformer(CellTransformer &&) = default;
                CellTransformer &operator=(const CellTransformer &) = default;
                CellTransformer &operator=(CellTransformer &&) = default;
                virtual ~CellTransformer() = default;

                // Accessor
                const Foundation::SPtrColumn &TargetColumn() const { return _sptrTargetColumn; }
                const SPtrCaster &TypeConverter() const { return _sptrTypeConverter; }

                // Mutator
                void setTargetColumn(const Foundation::SPtrColumn &sptrTargetColumn) { _sptrTargetColumn = sptrTargetColumn; }
                void setTypeConverter(const SPtrCaster &sptrTypeConverter) { _sptrTypeConverter = sptrTypeConverter; }

                // Locals
                virtual Foundation::SPtrCell Transform(const Foundation::SPtrCell &srcSPtrCell) const;
            };

            using SPtrCellTransformer = std::shared_ptr<CellTransformer>;
            using SPtrCellTransformerMap = std::unordered_map<std::string, Transformation::SPtrCellTransformer>;
            using CellTransformerMap = std::unordered_map<std::string, Transformation::CellTransformer>;
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CELLTRANSFORMER_H
