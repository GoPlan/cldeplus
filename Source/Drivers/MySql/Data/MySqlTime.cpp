//
// Created by LE, Duc Anh on 7/16/15.
//

#include "MySqlTime.h"
#include "../Helper/MySqlSourceHelper.h"

namespace Cloude {
    namespace Drivers {
        namespace MySql {
            namespace Data {

                MySqlTime::MySqlTime(unsigned int hour, unsigned int minute, unsigned int second,
                                     unsigned long millisecond)
                        : TimeBasedValue{Foundation::Data::ValueType::Time, sizeof(MYSQL_TIME)} {

                    _time.year = 0;
                    _time.month = 0;
                    _time.day = 0;
                    _time.hour = hour;
                    _time.minute = minute;
                    _time.second = second;
                    _time.second_part = millisecond;
                    _time.neg = false;
                    _time.time_type = MYSQL_TIMESTAMP_TIME;

                }

                MySqlTime::MySqlTime() :
                        TimeBasedValue{Foundation::Data::ValueType::Time, sizeof(MYSQL_TIME)} {

                    _time.year = 0;
                    _time.month = 0;
                    _time.day = 0;
                    _time.hour = 0;
                    _time.minute = 0;
                    _time.second = 0;
                    _time.second_part = 0;
                    _time.neg = false;
                    _time.time_type = MYSQL_TIMESTAMP_TIME;
                }

                void *MySqlTime::PointerToBuffer() {
                    return &_time;
                }

                std::string MySqlTime::ToString() const {
                    return Helper::MySqlSourceHelper::TimeToISO8601String(_time);
                }

                Foundation::Data::Value &MySqlTime::operator+(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator+ yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlTime::operator-(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator- yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlTime::operator*(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator* yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlTime::operator/(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator/ yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlTime::operator%(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator% yet"};
                    throw MySqlSourceException{msg};
                }

                bool MySqlTime::LessThan(const Foundation::Common::IComparable &target) const {
                    auto &targetTs = dynamic_cast<const MySqlTime &>(target);
                    return Helper::MySqlSourceHelper::Less(_time, targetTs._time);
                }

                bool MySqlTime::GreaterThan(const Foundation::Common::IComparable &target) const {
                    auto &targetTs = dynamic_cast<const MySqlTime &>(target);
                    return Helper::MySqlSourceHelper::Greater(_time, targetTs._time);
                }

                bool MySqlTime::EquivalentTo(const Foundation::Common::IComparable &target) const {
                    return !LessThan(target) && !GreaterThan(target);
                }
            }
        }
    }
}


