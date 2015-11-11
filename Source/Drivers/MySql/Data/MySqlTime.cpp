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

#include "MySqlTime.h"
#include "MySqlDateTimeImpl.h"
#include "../MySqlHelper.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {
            namespace Data {

                MySqlTime::MySqlTime(unsigned int hour, unsigned int minute, unsigned int second, unsigned long millisecond)
                        : TimeBasedValue{Foundation::Data::ValueType::Time, sizeof(MYSQL_TIME)} {
                    //
                    _sptrTimeImpl = cldeplus_make_shared<MySqlDateTimeImpl>();
                    _sptrTimeImpl->SetTime(hour, minute, second, (unsigned int) millisecond);
                }

                MySqlTime::MySqlTime() :
                        TimeBasedValue{Foundation::Data::ValueType::Time, sizeof(MYSQL_TIME)} {
                    //
                    _sptrTimeImpl = cldeplus_make_shared<MySqlDateTimeImpl>();
                    _sptrTimeImpl->SetTime(0, 0, 0, 0);
                }

                void *MySqlTime::PointerToBuffer() {
                    return &_sptrTimeImpl->mysql_datetime;
                }

                string MySqlTime::ToString() const {
                    return MySqlHelper::TimeToISO8601String(_sptrTimeImpl->mysql_datetime);
                }

                Foundation::Data::Value &MySqlTime::operator+(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator+ yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlTime::operator-(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator- yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlTime::operator*(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator* yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlTime::operator/(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator/ yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlTime::operator%(const Foundation::Data::Value &rhs) {
                    string msg{"Does not support operator% yet"};
                    throw MySqlSourceException{msg};
                }

                bool MySqlTime::LessThan(const Foundation::Common::IComparable &target) const {
                    auto &targetTs = dynamic_cast<const MySqlTime &>(target);
                    return MySqlHelper::Less(_sptrTimeImpl->mysql_datetime, targetTs._sptrTimeImpl->mysql_datetime);
                }

                bool MySqlTime::GreaterThan(const Foundation::Common::IComparable &target) const {
                    auto &targetTs = dynamic_cast<const MySqlTime &>(target);
                    return MySqlHelper::Greater(_sptrTimeImpl->mysql_datetime, targetTs._sptrTimeImpl->mysql_datetime);
                }

                bool MySqlTime::EquivalentTo(const Foundation::Common::IComparable &target) const {
                    return !LessThan(target) && !GreaterThan(target);
                }
            }
        }
    }
}


