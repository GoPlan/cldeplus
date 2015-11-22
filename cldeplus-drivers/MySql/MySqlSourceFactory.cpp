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


