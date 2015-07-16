//
// Created by LE, Duc Anh on 7/16/15.
//


#include <Drivers/MySql/MySqlSourceHelper.h>
#include "MySqlDate.h"

namespace Cloude {
    namespace Drivers {
        namespace MySql {
            namespace Data {

                MySqlDate::MySqlDate(unsigned year, unsigned month, unsigned day)
                        : TimeBasedValue{Foundation::Data::ValueType::Date, sizeof(MYSQL_TIME)} {
                    _date.year = year;
                    _date.month = month;
                    _date.day = day;
                }

                MySqlDate::MySqlDate()
                        : TimeBasedValue{Foundation::Data::ValueType::Date, sizeof(MYSQL_TIME)} {
                    //
                }

                void *MySqlDate::RawPointerToValueBuffer() {
                    return &_date;
                }

                std::string MySqlDate::ToString() const {
                    return MySqlSourceHelper::DateToISO8601String(_date);
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
            }
        }
    }
}



