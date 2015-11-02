//
// Created by LE, Duc Anh on 7/16/15.
//

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
                    _sptrDateImpl = std::make_shared<MySqlDateTimeImpl>();
                    _sptrDateImpl->SetDate(year, month, day);
                }

                MySqlDate::MySqlDate()
                        : TimeBasedValue{Foundation::Data::ValueType::Date, sizeof(MYSQL_TIME)} {
                    //
                    _sptrDateImpl = std::make_shared<MySqlDateTimeImpl>();
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



