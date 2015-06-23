//
// Created by LE, Duc Anh on 6/18/15.
//

#include <Foundation/EntityProxy.h>
#include <Foundation/Segmentation/Helper/SegmentHelper.h>
#include "Segment.h"

namespace Cloude {
    namespace Foundation {

//        const std::string Segmentation::Segment::CopyToString() const {
//            return __1::basic_string < char, char_traits < char >, allocator < char >> ();
//        }
//        const std::string &Segmentation::Segment::ToString() const {
//            return <#initializer#>;
//        }
//        const char *Segmentation::Segment::ToCString() const {
//            return nullptr;
//        }

        const SPtrEntityProxySet &Segmentation::Segment::ResultSet() {
            return _resultSet;
        }

        SPtrEntityProxySet Segmentation::Segment::Join(const SPtrEntityProxySet &targetSet,
                                                       SPtrEntityProxySet (*joinfunctor)(
                                                               const Segmentation::JoinPhrase &,
                                                               const Segmentation::JoinPhrase &)) {
            return Segmentation::Helper::SegmentHelper::Join(_resultSet, targetSet, joinfunctor);
        }
    }
}
