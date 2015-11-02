//
// Created by LE, Duc Anh on 5/29/15.
//

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
