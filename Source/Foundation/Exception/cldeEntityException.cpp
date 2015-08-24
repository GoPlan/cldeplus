//
// Created by LE, Duc Anh on 5/27/15.
//

#include "cldeEntityException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            const std::string cldeEntityException::_name{"cldeEntityException"};

            const std::string &cldeEntityException::Name() const noexcept {
                return _name;
            }
        }
    }
}


