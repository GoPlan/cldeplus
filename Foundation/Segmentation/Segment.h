//
// Created by LE, Duc Anh on 6/18/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_SEGMENT_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_SEGMENT_H

#include <memory>
#include <Foundation/Common/IPrintable.h>
#include <Foundation/EntityProxy.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {

            class Segment {

            public:
                enum class SegmentType {
                    Join,
                    Target
                };

                // TODO: Review Copy/Assignment ctors
                // TODO: Consider container to be either Vector or Set
                Segment(const Segment &) = default;
                Segment(Segment &&) = default;
                Segment &operator=(const Segment &) = default;
                Segment &operator=(Segment &&) = default;
                virtual ~Segment() = default;

                virtual void Evaluate() = 0;
                virtual SegmentType getSegmentType() = 0;
                virtual const SPtrEntityProxyVector &ResultSet() const = 0;

            protected:
                Segment() = default;
                SPtrEntityProxyVector _resultStorage;
            };

            using SPtrSegment = std::shared_ptr<Segment>;
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_SEGMENT_H
