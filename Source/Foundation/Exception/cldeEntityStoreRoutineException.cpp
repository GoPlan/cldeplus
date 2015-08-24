//
// Created by LE, Duc Anh on 5/26/15.
//

#include "../EntityStore.h"
#include "CLDEEntityStoreRoutineException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            std::string CLDEEntityStoreRoutineException::_name{"CLDEEntityStoreRoutineException"};

            const std::string &CLDEEntityStoreRoutineException::Name() const noexcept {
                return _name;
            }
        }
    }
}