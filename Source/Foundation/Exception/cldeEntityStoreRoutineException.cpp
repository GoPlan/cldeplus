//
// Created by LE, Duc Anh on 5/26/15.
//

#include "../EntityStore.h"
#include "cldeEntityStoreRoutineException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            std::string cldeEntityStoreRoutineException::_name{"cldeEntityStoreRoutineException"};

            const std::string &cldeEntityStoreRoutineException::Name() const noexcept {
                return _name;
            }
        }
    }
}