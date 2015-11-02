//
// Created by LE, Duc Anh on 5/26/15.
//

#include "CLDEDataSourceRoutineException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            string CLDEDataSourceRoutineException::_name{"CLDEDataSourceRoutineException"};

            const string &CLDEDataSourceRoutineException::Name() const noexcept {
                return _name;
            }
        }
    }
}

