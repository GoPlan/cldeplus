//
// Created by LE, Duc Anh on 7/1/15.
//

#include "SegmentationException.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Exception {

            const std::string SegmentationException::_name{"SegmentationException"};

            const std::string &SegmentationException::Name() const noexcept {
                return _name;
            }
        }
    }
}


