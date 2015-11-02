//
// Created by LE, Duc Anh on 7/16/15.
//

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


