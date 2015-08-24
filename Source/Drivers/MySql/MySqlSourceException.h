//
// Created by LE, Duc Anh on 5/29/15.
//

#ifndef CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOURCEDEXCEPTION_H
#define CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOURCEDEXCEPTION_H

#include "../../Foundation/Exception/cldeException.h"

namespace Cloude {
    namespace Drivers {
        namespace MySql {

            class MySqlSourceException : public Foundation::Exception::cldeException {

                static std::string _name;

            public:
                MySqlSourceException(const std::string &message);
                MySqlSourceException(const MySqlSourceException &) = default;
                MySqlSourceException(MySqlSourceException &&) = default;
                MySqlSourceException &operator=(const MySqlSourceException &) = default;
                MySqlSourceException &operator=(MySqlSourceException &&) = default;
                ~MySqlSourceException() = default;

                virtual const std::string &Name() const noexcept override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOURCEDEXCEPTION_H
