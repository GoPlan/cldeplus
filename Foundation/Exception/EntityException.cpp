//
// Created by LE, Duc Anh on 5/27/15.
//

#include "EntityException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            EntityException::EntityException(const std::string &message) : _message(message) {
                //
            }

            const char *EntityException::what() const noexcept {
                return _message.c_str();
            }
        }
    }
}


