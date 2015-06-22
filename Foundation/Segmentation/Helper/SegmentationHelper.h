//
// Created by LE, Duc Anh on 6/22/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_SEGMENTATIONHELPER_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_SEGMENTATIONHELPER_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Segmentation/Segment.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {
            namespace Helper {

                class SegmentationHelper {

                public:
                    static SPtrEntityProxySet InnerJoin(const SPtrEntityProxySet &lhs,
                                                        const SPtrEntityProxySet &rhs,
                                                        const SPtrColumnVector &columnsForKey);

                    static SPtrEntityProxySet CrossJoin(const SPtrEntityProxySet &lhs,
                                                        const SPtrEntityProxySet &rhs,
                                                        const SPtrColumnVector &columnsForKey);

                    static SPtrEntityProxySet LeftOuterJoin(const SPtrEntityProxySet &lhs,
                                                            const SPtrEntityProxySet &rhs,
                                                            const SPtrColumnVector &columnsForKey);

                    static SPtrEntityProxySet RightOuterJoin(const SPtrEntityProxySet &lhs,
                                                             const SPtrEntityProxySet &rhs,
                                                             const SPtrColumnVector &columnsForKey);

                    static SPtrEntityProxySet Merge(const SPtrEntityProxySet &lhs,
                                                    const SPtrEntityProxySet &rhs,
                                                    const SPtrColumnVector &columnsForKey);

                    static SPtrEntityProxySet Differ(const SPtrEntityProxySet &lhs,
                                                     const SPtrEntityProxySet &rhs,
                                                     const SPtrColumnVector &columnsForKey);

                public:
                    SegmentationHelper() = delete;
                    SegmentationHelper(const SegmentationHelper &) = delete;
                    SegmentationHelper(SegmentationHelper &&) = delete;
                    SegmentationHelper &operator=(const SegmentationHelper &) = delete;
                    SegmentationHelper &operator=(SegmentationHelper &&) = delete;
                    virtual ~SegmentationHelper() = delete;

                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_SEGMENTATIONHELPER_H
