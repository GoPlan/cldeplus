//
// Created by LE, Duc Anh on 5/29/15.
//

#include "MySqlSourceException.h"

namespace Cloude {
    namespace Infrastructure {
        namespace MySql {

            MySqlSourceException::MySqlSourceException(const std::string &sstrMessage) : _message(
                    sstrMessage) {
                //
            }

            MySqlSourceException::MySqlSourceException(const char *cstrMessage) : _message(cstrMessage) {
                //
            }

            const char *MySqlSourceException::what() const noexcept {
                return _message.c_str();
            }
        }
    }
}


