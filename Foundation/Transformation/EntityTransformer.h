//
// Created by LE, Duc Anh on 6/30/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TRANSFORMATION_ENTITYTRANSFORMER_H
#define CLOUD_E_PLUS_FOUNDATION_TRANSFORMATION_ENTITYTRANSFORMER_H

#include <Foundation/Segmentation/JoinPhrase.h>

namespace Cloude {
    namespace Foundation {
        namespace Transformation {

            class EntityTransformer {

                const Segmentation::JoinPhrase &_lhsPhrase;
                const Segmentation::JoinPhrase &_rhsPhrase;

            public:
                EntityTransformer(const Segmentation::JoinPhrase &lhsPhrase, const Segmentation::JoinPhrase &rhsPhrase);
                EntityTransformer(const EntityTransformer &) = default;
                EntityTransformer(EntityTransformer &&) = default;
                EntityTransformer &operator=(const EntityTransformer &) = default;
                EntityTransformer &operator=(EntityTransformer &&) = default;
                virtual ~EntityTransformer() = default;

                virtual SPtrEntityProxy Transform(const SPtrEntityProxy &lhsProxy, const SPtrEntityProxy &rhsProxy) const;
                virtual SPtrEntityProxy TransformLeftOnly(const SPtrEntityProxy &lhsProxy) const;
                virtual SPtrEntityProxy TransformRightOnly(const SPtrEntityProxy &rhsProxy) const;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_TRANSFORMATION_ENTITYTRANSFORMER_H
