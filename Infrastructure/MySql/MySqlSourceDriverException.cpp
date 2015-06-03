//
// Created by LE, Duc Anh on 5/29/15.
//

#include "MySqlSourceDriverException.h"

namespace Cloude {
    namespace Infrastructure {
        namespace MySql {

            MySqlSourceDriverException::MySqlSourceDriverException(const std::string &sstrMessage) : _message(
                    sstrMessage) {
                //
            }

            MySqlSourceDriverException::MySqlSourceDriverException(const char *cstrMessage) : _message(cstrMessage) {
                //
            }

            const char *MySqlSourceDriverException::what() const noexcept {
                return _message.c_str();
            }
        }
    }
}


