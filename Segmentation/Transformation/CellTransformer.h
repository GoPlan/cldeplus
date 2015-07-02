//
// Created by LE, Duc Anh on 6/30/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CELLTRANSFORMER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CELLTRANSFORMER_H

#include <Foundation/Column.h>
#include <Foundation/Cell.h>
#include "TypeConverter.h"

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {

            class CellTransformer {

                Foundation::SPtrColumn _sptrTargetColumn;
                SPtrTypeConverter _sptrTypeConverter;

            public:
                CellTransformer() = default;
                CellTransformer(const Foundation::SPtrColumn &targetColumn);
                CellTransformer(const Foundation::SPtrColumn &targetColumn, const SPtrTypeConverter &converter);
                CellTransformer(const CellTransformer &) = default;
                CellTransformer(CellTransformer &&) = default;
                CellTransformer &operator=(const CellTransformer &) = default;
                CellTransformer &operator=(CellTransformer &&) = default;
                virtual ~CellTransformer() = default;

                // Accessor
                const Foundation::SPtrColumn &TargetColumn() const { return _sptrTargetColumn; }
                const SPtrTypeConverter &TypeConverter() const { return _sptrTypeConverter; }

                // Mutator
                void setTargetColumn(const Foundation::SPtrColumn &sptrTargetColumn) {
                    _sptrTargetColumn = sptrTargetColumn;
                }
                void setTypeConverter(const SPtrTypeConverter &sptrTypeConverter) {
                    _sptrTypeConverter = sptrTypeConverter;
                }

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
