//
// Created by LE, Duc Anh on 6/18/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_SEGMENT_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_SEGMENT_H

#include <memory>
#include <Foundation/Common/IPrintable.h>
#include <Foundation/EntityProxy.h>
#include <Foundation/Segmentation/Helper/SegmentHelper.h>
#include <Foundation/Segmentation/JoinPhrase.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {

            class Segment;

            using SPtrSegment = std::shared_ptr<Segment>;

            class Segment {
                using SegmentHelper = Foundation::Segmentation::Helper::SegmentHelper;

            public:
                explicit Segment(const SPtrEntityProxySet &proxySet);
                Segment() = default;
                Segment(const Segment &) = default;
                Segment(Segment &&) = default;
                Segment &operator=(const Segment &) = default;
                Segment &operator=(Segment &&) = default;
                ~Segment() = default;

                // Locals - Accessors
                virtual const SPtrEntityProxySet &ResultSet();
                virtual SPtrSegment Join(const SPtrSegment &rhsSegment,
                                         const JoinPhrase &lhsJoinPhrase,
                                         const JoinPhrase &rhsJoinPhrase,
                                         SPtrEntityProxySet (*fptrJoin)(const JoinPhrase &lhs, const JoinPhrase &rhs));

            protected:
                SPtrEntityProxySet _resultSet;
            };


        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_SEGMENT_H
