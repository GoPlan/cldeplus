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

                SPtrCellTransformerMap _lhsCellTransformerMap;
                SPtrCellTransformerMap _rhsCellTransformerMap;

            public:
                EntityTransformer() = default;
                EntityTransformer(const EntityTransformer &) = default;
                EntityTransformer(EntityTransformer &&) = default;
                EntityTransformer &operator=(const EntityTransformer &) = default;
                EntityTransformer &operator=(EntityTransformer &&) = default;
                virtual ~EntityTransformer() = default;

                // Accessors
                virtual SPtrCellTransformerMap &LhsCellTransformerMap() { return _lhsCellTransformerMap; };
                virtual SPtrCellTransformerMap &RhsCellTransformerMap() { return _rhsCellTransformerMap; };

                // Locals
                virtual Foundation::SPtrEntityProxy
                        Transform(const Foundation::SPtrEntityProxy &lhsProxy,
                                  const Foundation::SPtrEntityProxy &rhsProxy) const;

                virtual Foundation::SPtrEntityProxy
                        TransformLeftOnly(const Foundation::SPtrEntityProxy &lhsProxy) const;

                virtual Foundation::SPtrEntityProxy
                        TransformRightOnly(const Foundation::SPtrEntityProxy &rhsProxy) const;
            };

            using SPtrEntityTransformer = std::shared_ptr<EntityTransformer>;
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_ENTITYTRANSFORMER_H
