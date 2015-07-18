//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_DRIVERS_MYSQL_DATA_MYSQLDATE_H
#define CLOUD_E_PLUS_DRIVERS_MYSQL_DATA_MYSQLDATE_H

#include <Drivers/MySql/MySqlSourceException.h>
#include <Foundation/Data/TimeBasedValue.h>
#include <mysql.h>

namespace Cloude {
    namespace Drivers {
        namespace MySql {
            namespace Data {

                class MySqlDate : public Foundation::Data::TimeBasedValue {

                    MYSQL_TIME _date;

                public:
                    MySqlDate(unsigned year, unsigned month, unsigned day);

                    MySqlDate();
                    MySqlDate(const MySqlDate &) = default;
                    MySqlDate(MySqlDate &&) = default;
                    MySqlDate &operator=(const MySqlDate &) = default;
                    MySqlDate &operator=(MySqlDate &&) = default;
                    ~MySqlDate() = default;

                    // Value
                    void *PointerToBuffer() override;

                    // IPrintable
                    std::string ToString() const override;

                    // IComputable
                    Foundation::Data::Value &operator+(const Foundation::Data::Value &rhs) override;
                    Foundation::Data::Value &operator-(const Foundation::Data::Value &rhs) override;
                    Foundation::Data::Value &operator*(const Foundation::Data::Value &rhs) override;
                    Foundation::Data::Value &operator/(const Foundation::Data::Value &rhs) override;
                    Foundation::Data::Value &operator%(const Foundation::Data::Value &rhs) override;

                    // IComparable
                    virtual bool LessThan(const Foundation::Common::IComparable &target) const override;
                    virtual bool GreaterThan(const Foundation::Common::IComparable &target) const override;
                    virtual bool EquivalentTo(const Foundation::Common::IComparable &target) const override;
                };

                using SPtrMySqlDate = std::shared_ptr<MySqlDate>;
            }
        }
    }
}


#endif //CLOUD_E_PLUS_DRIVERS_MYSQL_DATA_MYSQLDATE_H
