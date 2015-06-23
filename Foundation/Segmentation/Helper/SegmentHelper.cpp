//
// Created by LE, Duc Anh on 6/22/15.
//

#include "Foundation/Comparer/EntityProxyComparer.h"
#include "SegmentHelper.h"

namespace Cloude {
    namespace Foundation {

        SPtrEntityProxySet Segmentation::Helper::SegmentHelper::VectorToSet(
                const SPtrEntityProxyVector &sptrProxyVector,
                FPtrProxyProjection projection,
                FPtrProxyPredicate predicate) {

            SPtrEntityProxySet setProxies;

            for (auto proxy : sptrProxyVector) {
                if (predicate(proxy)) {
                    setProxies.insert(projection(proxy));
                }
            }

            return setProxies;
        }

        SPtrEntityProxySet Segmentation::Helper::SegmentHelper::Join(
                const SPtrEntityProxySet &lhs,
                const SPtrEntityProxySet &rhs,
                SPtrEntityProxySet (*joinfunctor)(const Segmentation::JoinPhrase &, const Segmentation::JoinPhrase &)) {
            return joinfunctor(lhs, rhs);
        }
    }
}



