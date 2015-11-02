//
// Created by LE, Duc Anh on 7/1/15.
//

#include "TransformationException.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Exception {

            const string TransformationException::_name{"TransformationException"};

            const string &TransformationException::Name() const noexcept {
                return _name;
            }
        }
    }
}

