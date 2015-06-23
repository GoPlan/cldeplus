//
// Created by LE, Duc Anh on 6/22/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_SEGMENTATIONHELPER_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_SEGMENTATIONHELPER_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Segmentation/Segment.h>
#include <Foundation/Segmentation/JoinPhrase.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {
            namespace Helper {

                class SegmentationHelper {
                    SegmentationHelper() = delete;
                    SegmentationHelper(const SegmentationHelper &) = delete;
                    SegmentationHelper(SegmentationHelper &&) = delete;
                    SegmentationHelper &operator=(const SegmentationHelper &) = delete;
                    SegmentationHelper &operator=(SegmentationHelper &&) = delete;
                    virtual ~SegmentationHelper() = delete;

                public:
                    using FPtrProxyProjection = std::function<SPtrEntityProxy(const SPtrEntityProxy &)>;
                    using FPtrProxyPredicate = std::function<bool(const SPtrEntityProxy &)>;
                    using DisplaySPtrColumn = std::pair<std::string, SPtrColumn>;
                    using DisplaySptrColumnVector = std::vector<DisplaySPtrColumn>;

                    static SPtrEntityProxySet VectorToSet(const SPtrEntityProxyVector &sptrProxyVector,
                                                          FPtrProxyProjection projection,
                                                          FPtrProxyPredicate predicate);

                    static SPtrEntityProxySet Join(const SPtrEntityProxySet &lhs,
                                                   const SPtrEntityProxySet &rhs,
                                                   SPtrEntityProxySet (*joinfunctor)(const JoinPhrase &lhs,
                                                                                     const JoinPhrase &rhs));
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_SEGMENTATIONHELPER_H
