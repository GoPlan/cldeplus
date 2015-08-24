//
// Created by LE, Duc Anh on 7/1/15.
//

#include "TransformationException.h"

namespace Cloude {
    namespace Segmentation {
        namespace Exception {

            const std::string TransformationException::_name{"TransformationException"};

            const std::string &TransformationException::Name() const noexcept {
                return _name;
            }
        }
    }
}

