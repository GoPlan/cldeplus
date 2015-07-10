//
// Created by LE, Duc Anh on 5/26/15.
//

#include "cldeDataSourceRoutineException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            std::string cldeDataSourceRoutineException::_name{"cldeDataSourceRoutineException"};

            const std::string &cldeDataSourceRoutineException::Name() const noexcept {
                return _name;
            }
        }
    }
}

