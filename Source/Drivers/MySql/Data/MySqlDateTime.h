//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_DRIVERS_MYSQL_DATA_MYSQLDATETIME_H
#define CLOUD_E_PLUS_DRIVERS_MYSQL_DATA_MYSQLDATETIME_H

#include <mysql.h>
#include "../../../Foundation/Data/TimeBasedValue.h"
#include "../../MySql/MySqlSourceException.h"

namespace Cloude {
    namespace Drivers {
        namespace MySql {
            namespace Data {

                class MySqlDateTime : public Foundation::Data::TimeBasedValue {

                    MYSQL_TIME _dateTime;

                public:
                    MySqlDateTime(unsigned int year, unsigned int month, unsigned int day);
                    MySqlDateTime(unsigned int year, unsigned int month, unsigned int day,
                                  unsigned int hour, unsigned int minute, unsigned int second,
                                  unsigned long milliseconds = 0);

                    MySqlDateTime();
                    MySqlDateTime(const MySqlDateTime &) = default;
                    MySqlDateTime(MySqlDateTime &&) = default;
                    MySqlDateTime &operator=(const MySqlDateTime &) = default;
                    MySqlDateTime &operator=(MySqlDateTime &&) = default;
                    virtual ~MySqlDateTime() = default;

                    // Value
                    virtual void *PointerToBuffer() override;

                    // IPrintable
                    virtual std::string ToString() const override;

                    // IComputable
                    virtual Foundation::Data::Value &operator+(const Foundation::Data::Value &rhs) override;
                    virtual Foundation::Data::Value &operator-(const Foundation::Data::Value &rhs) override;
                    virtual Foundation::Data::Value &operator*(const Foundation::Data::Value &rhs) override;
                    virtual Foundation::Data::Value &operator/(const Foundation::Data::Value &rhs) override;
                    virtual Foundation::Data::Value &operator%(const Foundation::Data::Value &rhs) override;

                    // IComparable
                    virtual bool LessThan(const Foundation::Common::IComparable &target) const override;
                    virtual bool GreaterThan(const Foundation::Common::IComparable &target) const override;
                    virtual bool EquivalentTo(const Foundation::Common::IComparable &target) const override;
                };

                using SPtrMySqlDateTime = std::shared_ptr<MySqlDateTime>;
            }
        }
    }
}

#endif //CLOUD_E_PLUS_DRIVERS_MYSQL_DATA_MYSQLDATETIME_H
