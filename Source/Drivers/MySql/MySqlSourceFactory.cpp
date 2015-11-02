//
// Created by LE, Duc Anh on 7/16/15.
//

#include "MySqlSourceFactory.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {

            Data::SPtrMySqlDate MySqlSourceFactory::CreateDate() {
                return cldeplus_make_shared<Data::MySqlDate>();
            }

            Data::SPtrMySqlDate MySqlSourceFactory::CreateDate(unsigned int year,
                                                               unsigned int month,
                                                               unsigned int day) {
                return cldeplus_make_shared<Data::MySqlDate>(year, month, day);
            }

            Data::SPtrMySqlTime MySqlSourceFactory::CreateTime() {
                return cldeplus_make_shared<Data::MySqlTime>();
            }

            Data::SPtrMySqlTime MySqlSourceFactory::CreateTime(unsigned int hour,
                                                               unsigned int minute,
                                                               unsigned int second,
                                                               unsigned long millisecond) {
                return cldeplus_make_shared<Data::MySqlTime>(hour, minute, second, millisecond);
            }

            Data::SPtrMySqlDateTime MySqlSourceFactory::CreateDateTime() {
                return cldeplus_make_shared<Data::MySqlDateTime>();
            }

            Data::SPtrMySqlDateTime MySqlSourceFactory::CreateDateTime(unsigned int year,
                                                                       unsigned int month,
                                                                       unsigned int day) {
                return cldeplus_make_shared<Data::MySqlDateTime>(year, month, day);
            }

            Data::SPtrMySqlDateTime MySqlSourceFactory::CreateDateTime(unsigned int year,
                                                                       unsigned int month,
                                                                       unsigned int day,
                                                                       unsigned int hour,
                                                                       unsigned int minute,
                                                                       unsigned int second,
                                                                       unsigned long millisecond) {
                return cldeplus_make_shared<Data::MySqlDateTime>(year, month, day, hour, minute, second, millisecond);
            }
        }
    }
}


