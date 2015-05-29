//
// Created by LE, Duc Anh on 5/29/15.
//

#include "MySqlDriverException.h"

namespace Cloude {
    namespace Infrastructure {
        namespace Exception {

            MySqlDriverException::MySqlDriverException(const std::string &sstrMessage) : _message(sstrMessage) {
                //
            }

            MySqlDriverException::MySqlDriverException(const char *cstrMessage) : _message(cstrMessage) {
                //
            }

            const char *MySqlDriverException::what() const noexcept {
                return _message.c_str();
            }
        }
    }
}


