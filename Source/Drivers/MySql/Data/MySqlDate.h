//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLDEPLUS_DRIVERS_MYSQL_DATA_MYSQLDATE_H
#define CLDEPLUS_DRIVERS_MYSQL_DATA_MYSQLDATE_H

#include "../../../Foundation/Data/TimeBasedValue.h"
#include "../MySqlSourceException.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {
            namespace Data {

                class MySqlDateTimeImpl;

                class MySqlDate : public Foundation::Data::TimeBasedValue {

                    shared_ptr<MySqlDateTimeImpl> _sptrDateImpl;

                public:
                    MySqlDate(unsigned year, unsigned month, unsigned day);

                    MySqlDate();
                    MySqlDate(const MySqlDate &) = default;
                    MySqlDate(MySqlDate &&) = default;
                    MySqlDate &operator=(const MySqlDate &) = default;
                    MySqlDate &operator=(MySqlDate &&) = default;
                    virtual ~MySqlDate() = default;

                    // Value
                    void *PointerToBuffer() override;

                    // IPrintable
                    string ToString() const override;

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

                using SPtrMySqlDate = shared_ptr<MySqlDate>;
            }
        }
    }
}


#endif //CLDEPLUS_DRIVERS_MYSQL_DATA_MYSQLDATE_H
