//
// Created by LE, Duc Anh on 5/29/15.
//

#include "MySqlSourceException.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {

            string MySqlSourceException::_name{"MySqlSourceException"};

            MySqlSourceException::MySqlSourceException(const string &message)
                    : CLDEException{message} {
                //
            }

            const string &Drivers::MySql::MySqlSourceException::Name() const noexcept {
                return _name;
            }
        }
    }
}


