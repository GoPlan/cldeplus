//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_DRIVERS_MYSQL_DATA_MYSQLTIME_H
#define CLOUD_E_PLUS_DRIVERS_MYSQL_DATA_MYSQLTIME_H

#include <Drivers/MySql/MySqlSourceException.h>
#include <Foundation/Data/TimeBasedValue.h>
#include <mysql.h>

namespace Cloude {
    namespace Drivers {
        namespace MySql {
            namespace Data {

                class MySqlTime : public Foundation::Data::TimeBasedValue {

                    MYSQL_TIME _time;

                public:
                    MySqlTime(unsigned int hour, unsigned int minute, unsigned int second,
                              unsigned long millisecond = 0);

                    MySqlTime();
                    MySqlTime(const MySqlTime &) = default;
                    MySqlTime(MySqlTime &&) = default;
                    MySqlTime &operator=(const MySqlTime &) = default;
                    MySqlTime &operator=(MySqlTime &&) = default;
                    ~MySqlTime() = default;

                    // Value
                    virtual void *RawPointerToValueBuffer() override;

                    // IPrintable
                    virtual std::string ToString() const override;

                    // IComputable
                    virtual Foundation::Data::Value &operator+(const Foundation::Data::Value &rhs) override;
                    virtual Foundation::Data::Value &operator-(const Foundation::Data::Value &rhs) override;
                    virtual Foundation::Data::Value &operator*(const Foundation::Data::Value &rhs) override;
                    virtual Foundation::Data::Value &operator/(const Foundation::Data::Value &rhs) override;
                    virtual Foundation::Data::Value &operator%(const Foundation::Data::Value &rhs) override;
                };

                using SPtrMySqlTime = std::shared_ptr<MySqlTime>;
            }
        }
    }
}

#endif //CLOUD_E_PLUS_DRIVERS_MYSQL_DATA_MYSQLTIME_H
