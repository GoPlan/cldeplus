//
// Created by LE, Duc Anh on 6/18/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_SEGMENT_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_SEGMENT_H

#include <memory>
#include <Foundation/Common/IPrintable.h>
#include <Foundation/Entity.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {

            class Segment : public Common::IPrintable {

            public:
                Segment(const Segment &) = default;
                Segment(Segment &&) = default;
                Segment &operator=(const Segment &) = default;
                Segment &operator=(Segment &&) = default;
                virtual ~Segment() = default;

                virtual const SPtrEntitySet ResultSet() const;
                virtual void Evaluate() = 0;

            protected:
                Segment() = default;
                SPtrEntitySet _resultSet;

            };

            using SPtrSegment = std::shared_ptr<Segment>;
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_SEGMENT_H
