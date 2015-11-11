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
