//
// Created by LE, Duc Anh on 6/30/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_ENTITYTRANSFORMER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_ENTITYTRANSFORMER_H

#include <Foundation/EntityProxy.h>
#include "CellTransformer.h"

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {

            class EntityTransformer {

                CellTransformerMap _mapCellTransformers;

            public:
                EntityTransformer() = default;
                EntityTransformer(const EntityTransformer &) = default;
                EntityTransformer(EntityTransformer &&) = default;
                EntityTransformer &operator=(const EntityTransformer &) = default;
                EntityTransformer &operator=(EntityTransformer &&) = default;
                virtual ~EntityTransformer() = default;

                // Accessors
                virtual CellTransformerMap &CellTransformerMap() { return _mapCellTransformers; };

                // Locals
                virtual void Transform(const Foundation::SPtrEntityProxy &srcProxy,
                                       Foundation::SPtrEntityProxy &dstProxy) const;
            };

            using SPtrEntityTransformer = std::shared_ptr<EntityTransformer>;
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_ENTITYTRANSFORMER_H
