//
// Created by LE, Duc Anh on 5/26/15.
//

#include "cldeNonSupportedDataTypeException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            const std::string cldeNonSupportedDataTypeException::_name{"cldeNonSupportedDataTypeException"};

            const std::string &cldeNonSupportedDataTypeException::Name() const noexcept {
                return _name;
            }

        }
    }
}


