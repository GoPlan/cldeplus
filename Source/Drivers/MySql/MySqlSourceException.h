/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#ifndef CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOURCEDEXCEPTION_H
#define CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOURCEDEXCEPTION_H

#include "../../Foundation/Exception/CLDEException.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {

            class MySqlSourceException : public Foundation::Exception::CLDEException {

                static string _name;

            public:
                MySqlSourceException(const string &message);
                MySqlSourceException(const MySqlSourceException &) = default;
                MySqlSourceException(MySqlSourceException &&) = default;
                MySqlSourceException &operator=(const MySqlSourceException &) = default;
                MySqlSourceException &operator=(MySqlSourceException &&) = default;
                ~MySqlSourceException() = default;

                virtual const string &Name() const noexcept override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOURCEDEXCEPTION_H
