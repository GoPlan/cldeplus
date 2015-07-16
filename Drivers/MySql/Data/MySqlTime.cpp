//
// Created by LE, Duc Anh on 7/16/15.
//

#include <Drivers/MySql/MySqlSourceHelper.h>
#include "MySqlTime.h"

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

                void *MySqlTime::RawPointerToValueBuffer() {
                    return &_time;
                }

                std::string MySqlTime::ToString() const {
                    return MySqlSourceHelper::TimeToISO8601String(_time);
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
            }
        }
    }
}


