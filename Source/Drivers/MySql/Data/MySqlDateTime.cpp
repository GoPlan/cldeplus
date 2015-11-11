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

#include "MySqlDateTime.h"
#include "MySqlDateTimeImpl.h"
#include "../MySqlHelper.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {
            namespace Data {


                MySqlDateTime::MySqlDateTime(unsigned int year, unsigned int month, unsigned int day)
                        : TimeBasedValue{Foundation::Data::ValueType::DateTime, sizeof(MYSQL_TIME)} {
                    //
                    _sptrDateTimeImpl = cldeplus_make_shared<MySqlDateTimeImpl>();
                    _sptrDateTimeImpl->SetDateTime(year, month, day);
                }

                MySqlDateTime::MySqlDateTime(unsigned int year,
                                             unsigned int month,
                                             unsigned int day,
                                             unsigned int hour,
                                             unsigned int minute,
                                             unsigned int second,
                                             unsigned long millisecond)
                        : TimeBasedValue{Foundation::Data::ValueType::DateTime, sizeof(MYSQL_TIME)} {
                    //
                    _sptrDateTimeImpl = cldeplus_make_shared<MySqlDateTimeImpl>();
                    _sptrDateTimeImpl->SetDateTime(year, month, day, hour, minute, second, millisecond);
                }

                MySqlDateTime::MySqlDateTime()
                        : TimeBasedValue{Foundation::Data::ValueType::DateTime, sizeof(MYSQL_TIME)} {
                    //
                    _sptrDateTimeImpl = cldeplus_make_shared<MySqlDateTimeImpl>();
                    _sptrDateTimeImpl->SetDateTime(0, 0, 0);
                }

                void *MySqlDateTime::PointerToBuffer() {
                    return &_sptrDateTimeImpl->mysql_datetime;
                }

                string MySqlDateTime::ToString() const {
                    return MySqlHelper::DateTimeToISO8601String(_sptrDateTimeImpl->mysql_datetime);
                }

                Foundation::Data::Value &MySqlDateTime::operator+(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator+ yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDateTime::operator-(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator- yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDateTime::operator*(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator* yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDateTime::operator/(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator/ yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDateTime::operator%(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator% yet"};
                    throw MySqlSourceException{msg};
                }

                bool MySqlDateTime::LessThan(const Foundation::Common::IComparable &target) const {
                    auto &targetTs = dynamic_cast<const MySqlDateTime &>(target);
                    return MySqlHelper::Less(_sptrDateTimeImpl->mysql_datetime,
                                             targetTs._sptrDateTimeImpl->mysql_datetime);
                }

                bool MySqlDateTime::GreaterThan(const Foundation::Common::IComparable &target) const {
                    auto &targetTs = dynamic_cast<const MySqlDateTime &>(target);
                    return MySqlHelper::Greater(_sptrDateTimeImpl->mysql_datetime,
                                                targetTs._sptrDateTimeImpl->mysql_datetime);
                }

                bool MySqlDateTime::EquivalentTo(const Foundation::Common::IComparable &target) const {
                    return !LessThan(target) && !GreaterThan(target);
                }
            }
        }
    }
}


