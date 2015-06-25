//
// Created by LE, Duc Anh on 6/22/15.
//

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
                const JoinPhrase &lhsJoinPhrase,
                const JoinPhrase &rhsJoinPhrase,
                SPtrEntityProxySet (*fptrJoin)(const Segmentation::JoinPhrase &lhsPhrase,
                                               const Segmentation::JoinPhrase &rhsPhrase)) {
            return fptrJoin(lhsJoinPhrase, rhsJoinPhrase);
        }
    }
}



