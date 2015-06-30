//
// Created by LE, Duc Anh on 6/30/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TRANSFORMATION_CELLTRANSFORMER_H
#define CLOUD_E_PLUS_FOUNDATION_TRANSFORMATION_CELLTRANSFORMER_H

#include <Foundation/Column.h>
#include <Foundation/Cell.h>
#include "TypeConverter.h"

namespace Cloude {
    namespace Foundation {
        namespace Transformation {

            class CellTransformer {

                SPtrColumn _sptrTargetColumn;
                SPtrTypeConverter _sptrConverter;

            public:
                CellTransformer() = default;
                CellTransformer(const SPtrColumn &sptrTargetColumn);
                CellTransformer(const CellTransformer &) = default;
                CellTransformer(CellTransformer &&) = default;
                CellTransformer &operator=(const CellTransformer &) = default;
                CellTransformer &operator=(CellTransformer &&) = default;
                virtual ~CellTransformer() = default;

                // Accessor
                SPtrColumn &TargetColumn() { return _sptrTargetColumn; }

                // Mutator
                void setTargetColumn(const SPtrColumn &sptrTargetColumn) { _sptrTargetColumn = sptrTargetColumn; }

                // Locals
                virtual SPtrCell Transform(const SPtrCell &srcSPtrCell) const;
            };

            using SPtrCellTransformer = std::shared_ptr<CellTransformer>;
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_TRANSFORMATION_CELLTRANSFORMER_H
