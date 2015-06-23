//
// Created by LE, Duc Anh on 6/18/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_SEGMENT_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_SEGMENT_H

#include <memory>
#include <Foundation/Common/IPrintable.h>
#include <Foundation/EntityProxy.h>
#include "JoinPhrase.h"

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {

            class Segment : public Common::IPrintable {

            public:
                Segment() = default;
                Segment(const Segment &) = default;
                Segment(Segment &&) = default;
                Segment &operator=(const Segment &) = default;
                Segment &operator=(Segment &&) = default;
                virtual ~Segment() = default;

                // IPrintable
//                virtual const std::string CopyToString() const override;
//                virtual const std::string &ToString() const override;
//                virtual const char *ToCString() const override;

                // Locals - Accessors
                virtual const SPtrEntityProxySet &ResultSet();
                virtual SPtrEntityProxySet Join(const SPtrEntityProxySet &targetSet,
                                                SPtrEntityProxySet (*joinfunctor)(const JoinPhrase &lhs,
                                                                                  const JoinPhrase &rhs));

            protected:
                SPtrEntityProxySet _resultSet;
            };

            using SPtrSegment = std::shared_ptr<Segment>;
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_SEGMENT_H
