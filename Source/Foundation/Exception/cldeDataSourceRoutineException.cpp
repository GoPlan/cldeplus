//
// Created by LE, Duc Anh on 5/26/15.
//

#include "CLDEDataSourceRoutineException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            std::string CLDEDataSourceRoutineException::_name{"CLDEDataSourceRoutineException"};

            const std::string &CLDEDataSourceRoutineException::Name() const noexcept {
                return _name;
            }
        }
    }
}

