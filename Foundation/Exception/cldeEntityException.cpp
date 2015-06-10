//
// Created by LE, Duc Anh on 5/27/15.
//

#include "cldeEntityException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            cldeEntityException::cldeEntityException(const std::string &message) : _message(message) {
                //
            }

            const char *cldeEntityException::what() const noexcept {
                return _message.c_str();
            }
        }
    }
}


