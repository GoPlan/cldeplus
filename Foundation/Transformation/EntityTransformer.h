//
// Created by LE, Duc Anh on 6/30/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TRANSFORMATION_ENTITYTRANSFORMER_H
#define CLOUD_E_PLUS_FOUNDATION_TRANSFORMATION_ENTITYTRANSFORMER_H

#include <Foundation/EntityProxy.h>
#include "CellTransformer.h"

namespace Cloude {
    namespace Foundation {
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

                virtual SPtrEntityProxy Transform(const SPtrEntityProxy &lhsProxy, const SPtrEntityProxy &rhsProxy) const;
                virtual SPtrEntityProxy TransformLeftOnly(const SPtrEntityProxy &lhsProxy) const;
                virtual SPtrEntityProxy TransformRightOnly(const SPtrEntityProxy &rhsProxy) const;
            };

            using SPtrEntityTransformer = std::shared_ptr<EntityTransformer>;
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_TRANSFORMATION_ENTITYTRANSFORMER_H
