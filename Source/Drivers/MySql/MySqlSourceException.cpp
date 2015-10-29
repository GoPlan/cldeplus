//
// Created by LE, Duc Anh on 5/29/15.
//

#include "MySqlSourceException.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {

            std::string MySqlSourceException::_name{"MySqlSourceException"};

            MySqlSourceException::MySqlSourceException(const std::string &message)
                    : CLDEException{message} {
                //
            }

            const std::string &Drivers::MySql::MySqlSourceException::Name() const noexcept {
                return _name;
            }
        }
    }
}


