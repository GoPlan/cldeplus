//
// Created by LE, Duc Anh on 7/16/15.
//

#include "MySqlTime.h"
#include "MySqlDateTimeImpl.h"
#include "../MySqlHelper.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {
            namespace Data {

                MySqlTime::MySqlTime(unsigned int hour, unsigned int minute, unsigned int second,
                                     unsigned long millisecond)
                        : TimeBasedValue{Foundation::Data::ValueType::Time, sizeof(MYSQL_TIME)} {
                    //
                    _sptrTimeImpl = std::make_shared<MySqlDateTimeImpl>();
                    _sptrTimeImpl->SetTime(hour, minute, second, millisecond);
                }

                MySqlTime::MySqlTime() :
                        TimeBasedValue{Foundation::Data::ValueType::Time, sizeof(MYSQL_TIME)} {
                    //
                    _sptrTimeImpl = std::make_shared<MySqlDateTimeImpl>();
                    _sptrTimeImpl->SetTime(0, 0, 0, 0);
                }

                void *MySqlTime::PointerToBuffer() {
                    return &_sptrTimeImpl->mysql_datetime;
                }

                std::string MySqlTime::ToString() const {
                    return MySqlHelper::TimeToISO8601String(_sptrTimeImpl->mysql_datetime);
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


