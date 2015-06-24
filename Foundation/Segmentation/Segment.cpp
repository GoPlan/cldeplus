//
// Created by LE, Duc Anh on 6/18/15.
//

#include <Foundation/EntityProxy.h>
#include <Foundation/Segmentation/Helper/SegmentHelper.h>
#include "Segment.h"

namespace Cloude {
    namespace Foundation {

        Segmentation::Segment::Segment(const SPtrEntityProxySet &proxySet) : _resultSet{proxySet} {
            //
        }

        const SPtrEntityProxySet &Segmentation::Segment::ResultSet() {
            return _resultSet;
        }

        Segmentation::SPtrSegment Segmentation::Segment::Join(const SPtrSegment &rhsSegment,
                                                              const JoinPhrase &lhsJoinPhrase,
                                                              const JoinPhrase &rhsJoinPhrase,
                                                              SPtrEntityProxySet (*fptrJoin)(
                                                                      const Segmentation::JoinPhrase &,
                                                                      const Segmentation::JoinPhrase &)) {
            auto resultSet = SegmentHelper::Join(lhsJoinPhrase, rhsJoinPhrase, fptrJoin);
            return SPtrSegment{new Segment{resultSet}};
        }
    }
}
