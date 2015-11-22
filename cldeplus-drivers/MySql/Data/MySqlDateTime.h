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

#ifndef CLDEPLUS_DRIVERS_MYSQL_DATA_MYSQLDATETIME_H
#define CLDEPLUS_DRIVERS_MYSQL_DATA_MYSQLDATETIME_H

#include "../../../Foundation/Data/TimeBasedValue.h"
#include "../../MySql/MySqlSourceException.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {
            namespace Data {

                class MySqlDateTimeImpl;

                class MySqlDateTime : public Foundation::Data::TimeBasedValue {

                    shared_ptr<MySqlDateTimeImpl> _sptrDateTimeImpl;

                public:
                    MySqlDateTime(unsigned int year, unsigned int month, unsigned int day);
                    MySqlDateTime(unsigned int year, unsigned int month, unsigned int day,
                                  unsigned int hour, unsigned int minute, unsigned int second,
                                  unsigned long millisecond = 0);

                    MySqlDateTime();
                    MySqlDateTime(const MySqlDateTime &) = default;
                    MySqlDateTime(MySqlDateTime &&) = default;
                    MySqlDateTime &operator=(const MySqlDateTime &) = default;
                    MySqlDateTime &operator=(MySqlDateTime &&) = default;
                    virtual ~MySqlDateTime() = default;

                    // Value
                    virtual void *PointerToBuffer() override;

                    // IPrintable
                    virtual string ToString() const override;

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

                using SPtrMySqlDateTime = shared_ptr<MySqlDateTime>;
            }
        }
    }
}

#endif //CLDEPLUS_DRIVERS_MYSQL_DATA_MYSQLDATETIME_H
