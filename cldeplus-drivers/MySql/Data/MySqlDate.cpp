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

#include "MySqlDate.h"
#include "MySqlDateTimeImpl.h"
#include "../MySqlHelper.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {
            namespace Data {

                MySqlDate::MySqlDate(unsigned year, unsigned month, unsigned day)
                        : TimeBasedValue{Foundation::Data::ValueType::Date, sizeof(MYSQL_TIME)} {
                    //
                    _sptrDateImpl = cldeplus_make_shared<MySqlDateTimeImpl>();
                    _sptrDateImpl->SetDate(year, month, day);
                }

                MySqlDate::MySqlDate()
                        : TimeBasedValue{Foundation::Data::ValueType::Date, sizeof(MYSQL_TIME)} {
                    //
                    _sptrDateImpl = cldeplus_make_shared<MySqlDateTimeImpl>();
                    _sptrDateImpl->SetDate(0, 0, 0);
                }

                void *MySqlDate::PointerToBuffer() {
                    return &_sptrDateImpl->mysql_datetime;
                }

                string MySqlDate::ToString() const {
                    return MySqlHelper::DateToISO8601String(_sptrDateImpl->mysql_datetime);
                }

                Foundation::Data::Value &MySqlDate::operator+(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator+ yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDate::operator-(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator- yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDate::operator*(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator* yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDate::operator/(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator/ yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDate::operator%(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator% yet"};
                    throw MySqlSourceException{msg};
                }

                bool MySqlDate::LessThan(const Foundation::Common::IComparable &target) const {
                    auto &targetTs = dynamic_cast<const MySqlDate &>(target);
                    return MySqlHelper::Less(_sptrDateImpl->mysql_datetime, targetTs._sptrDateImpl->mysql_datetime);
                }

                bool MySqlDate::GreaterThan(const Foundation::Common::IComparable &target) const {
                    auto &targetTs = dynamic_cast<const MySqlDate &>(target);
                    return MySqlHelper::Greater(_sptrDateImpl->mysql_datetime, targetTs._sptrDateImpl->mysql_datetime);
                }

                bool MySqlDate::EquivalentTo(const Foundation::Common::IComparable &target) const {
                    return !LessThan(target) && !GreaterThan(target);
                }
            }
        }
    }
}



