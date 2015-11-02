//
// Created by LE, Duc Anh on 5/26/15.
//

#include "../EntityStore.h"
#include "CLDEEntityStoreRoutineException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            string CLDEEntityStoreRoutineException::_name{"CLDEEntityStoreRoutineException"};

            const string &CLDEEntityStoreRoutineException::Name() const noexcept {
                return _name;
            }
        }
    }
}