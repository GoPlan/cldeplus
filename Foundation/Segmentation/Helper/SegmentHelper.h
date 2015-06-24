//
// Created by LE, Duc Anh on 6/22/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_SEGMENTHELPER_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_SEGMENTHELPER_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Segmentation/JoinPhrase.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {
            namespace Helper {

                class SegmentHelper {

                    SegmentHelper() = delete;
                    SegmentHelper(const SegmentHelper &) = delete;
                    SegmentHelper(SegmentHelper &&) = delete;
                    SegmentHelper &operator=(const SegmentHelper &) = delete;
                    SegmentHelper &operator=(SegmentHelper &&) = delete;
                    virtual ~SegmentHelper() = delete;

                public:
                    using FPtrProxyProjection = std::function<SPtrEntityProxy(const SPtrEntityProxy &)>;
                    using FPtrProxyPredicate = std::function<bool(const SPtrEntityProxy &)>;
                    using DisplaySPtrColumn = std::pair<std::string, SPtrColumn>;
                    using DisplaySptrColumnVector = std::vector<DisplaySPtrColumn>;

                    static SPtrEntityProxySet VectorToSet(const SPtrEntityProxyVector &sptrProxyVector,
                                                          FPtrProxyProjection projection,
                                                          FPtrProxyPredicate predicate);

                    static SPtrEntityProxySet Join(const JoinPhrase &lhsJoinPhrase,
                                                   const JoinPhrase &rhsJoinPhrase,
                                                   SPtrEntityProxySet (*fptrJoin)(const JoinPhrase &lhs,
                                                                                  const JoinPhrase &rhs));
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_SEGMENTHELPER_H
