//
// Created by LE, Duc Anh on 5/27/15.
//

#include "CLDEEntityException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            const string CLDEEntityException::_name{"CLDEEntityException"};

            const string &CLDEEntityException::Name() const noexcept {
                return _name;
            }
        }
    }
}


