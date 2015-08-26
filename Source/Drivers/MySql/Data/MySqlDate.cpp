//
// Created by LE, Duc Anh on 7/16/15.
//

#include "MySqlDate.h"
#include "../MySqlHelper.h"

namespace Cloude {
    namespace Drivers {
        namespace MySql {
            namespace Data {

                MySqlDate::MySqlDate(unsigned year, unsigned month, unsigned day)
                        : TimeBasedValue{Foundation::Data::ValueType::Date, sizeof(MYSQL_TIME)} {

                    _date.year = year;
                    _date.month = month;
                    _date.day = day;
                    _date.hour = 0;
                    _date.minute = 0;
                    _date.second = 0;
                    _date.second_part = 0;
                    _date.neg = false;
                    _date.time_type = MYSQL_TIMESTAMP_DATE;
                }

                MySqlDate::MySqlDate()
                        : TimeBasedValue{Foundation::Data::ValueType::Date, sizeof(MYSQL_TIME)} {

                    _date.year = 0;
                    _date.month = 0;
                    _date.day = 0;
                    _date.hour = 0;
                    _date.minute = 0;
                    _date.second = 0;
                    _date.second_part = 0;
                    _date.neg = false;
                    _date.time_type = MYSQL_TIMESTAMP_DATE;
                }

                void *MySqlDate::PointerToBuffer() {
                    return &_date;
                }

                std::string MySqlDate::ToString() const {
                    return MySqlHelper::DateToISO8601String(_date);
                }

                Foundation::Data::Value &MySqlDate::operator+(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator+ yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDate::operator-(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator- yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDate::operator*(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator* yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDate::operator/(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator/ yet"};
                    throw MySqlSourceException{msg};
                }

                Foundation::Data::Value &MySqlDate::operator%(const Foundation::Data::Value &rhs) {
                    std::string msg{"Does not support operator% yet"};
                    throw MySqlSourceException{msg};
                }

                bool MySqlDate::LessThan(const Foundation::Common::IComparable &target) const {
                    auto &targetTs = dynamic_cast<const MySqlDate &>(target);
                    return MySqlHelper::Less(_date, targetTs._date);
                }

                bool MySqlDate::GreaterThan(const Foundation::Common::IComparable &target) const {
                    auto &targetTs = dynamic_cast<const MySqlDate &>(target);
                    return MySqlHelper::Greater(_date, targetTs._date);
                }

                bool MySqlDate::EquivalentTo(const Foundation::Common::IComparable &target) const {
                    return !LessThan(target) && !GreaterThan(target);
                }
            }
        }
    }
}



