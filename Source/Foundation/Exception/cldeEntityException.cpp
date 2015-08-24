//
// Created by LE, Duc Anh on 5/27/15.
//

#include "CLDEEntityException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            const std::string CLDEEntityException::_name{"CLDEEntityException"};

            const std::string &CLDEEntityException::Name() const noexcept {
                return _name;
            }
        }
    }
}


