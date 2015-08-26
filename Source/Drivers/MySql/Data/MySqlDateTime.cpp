//
// Created by LE, Duc Anh on 7/16/15.
//

#include "MySqlDateTime.h"
#include "../MySqlHelper.h"

namespace Cloude {
    namespace Drivers {
        namespace MySql {
            namespace Data {


                MySqlDateTime::MySqlDateTime(unsigned int year, unsigned int month, unsigned int day)
                        : TimeBasedValue{Foundation::Data::ValueType::DateTime, sizeof(MYSQL_TIME)} {

                    _dateTime.year = year;
                    _dateTime.month = month;
                    _dateTime.day = day;
                    _dateTime.hour = 0;
                    _dateTime.minute = 0;
                    _dateTime.second = 0;
                    _dateTime.second_part = 0;
                    _dateTime.neg = false;
                    _dateTime.time_type = MYSQL_TIMESTAMP_DATETIME;
                }

                MySqlDateTime::MySqlDateTime(unsigned int year,
                                             unsigned int month,
                                             unsigned int day,
                                             unsigned int hour,
                                             unsigned int minute,
                                             unsigned int second,
                                             unsigned long milliseconds)
                        : TimeBasedValue{Foundation::Data::ValueType::DateTime, sizeof(MYSQL_TIME)} {

                    _dateTime.year = year;
                    _dateTime.month = month;
                    _dateTime.day = day;
                    _dateTime.hour = hour;
                    _dateTime.minute = minute;
                    _dateTime.second = second;
                    _dateTime.second_part = milliseconds;
                    _dateTime.neg = false;
                    _dateTime.time_type = MYSQL_TIMESTAMP_DATETIME;
                }

                MySqlDateTime::MySqlDateTime()
                        : TimeBasedValue{Foundation::Data::ValueType::DateTime, sizeof(MYSQL_TIME)} {

                    _dateTime.year = 0;
                    _dateTime.month = 0;
                    _dateTime.day = 0;
                    _dateTime.hour = 0;
                    _dateTime.minute = 0;
                    _dateTime.second = 0;
                    _dateTime.second_part = 0;
                    _dateTime.neg = false;
                    _dateTime.time_type = MYSQL_TIMESTAMP_DATETIME;
                }

                void *MySqlDateTime::PointerToBuffer() {
                    return &_dateTime;
                }

                std::string MySqlDateTime::ToString() const {
                    return MySqlHelper::DateTimeToISO8601String(_dateTime);
                }

                Foundation::Data::Value &MySqlDateTime::operator+(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator+ yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDateTime::operator-(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator- yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDateTime::operator*(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator* yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDateTime::operator/(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator/ yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDateTime::operator%(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator% yet"};
                    throw MySqlSourceException{msg};
                }

                bool MySqlDateTime::LessThan(const Foundation::Common::IComparable &target) const {
                    auto &targetTs = dynamic_cast<const MySqlDateTime &>(target);
                    return MySqlHelper::Less(_dateTime, targetTs._dateTime);
                }

                bool MySqlDateTime::GreaterThan(const Foundation::Common::IComparable &target) const {
                    auto &targetTs = dynamic_cast<const MySqlDateTime &>(target);
                    return MySqlHelper::Greater(_dateTime, targetTs._dateTime);
                }

                bool MySqlDateTime::EquivalentTo(const Foundation::Common::IComparable &target) const {
                    return !LessThan(target) && !GreaterThan(target);
                }
            }
        }
    }
}


