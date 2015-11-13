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

#ifndef CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOUCRCEDRIVER_H
#define CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOUCRCEDRIVER_H

#include "../../Portable/CommonTypes.h"
#include "../../Foundation/EntitySourceDriver.h"
#include "MySqlSourceException.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace MySql {

            class MySqlSourceDriver : public Foundation::EntitySourceDriver {

            public:
                using Options = struct {
                    string Host;
                    string User;
                    string Pass;
                    string Base;
                    unsigned int Port = 3306;
                };

            public:
                explicit MySqlSourceDriver(Foundation::SPtrEntityMap const &entityMap);
                MySqlSourceDriver(MySqlSourceDriver const &) = default;
                MySqlSourceDriver(MySqlSourceDriver &&) = default;
                MySqlSourceDriver &operator=(MySqlSourceDriver const &) = default;
                MySqlSourceDriver &operator=(MySqlSourceDriver &&) = default;
                ~MySqlSourceDriver() = default;

                // Locals
                void Connect();
                void Disconnect();
                Options &OptionArgs() { return _optionArgs; }

                // EntitySourceDriver
                int Load(Foundation::SPtrEntity &entity) const override;
                int Insert(Foundation::SPtrEntity &entity) const override;
                int Save(Foundation::SPtrEntity &entity) const override;
                int Delete(Foundation::SPtrEntity &entity) const override;
                Foundation::SPtrEntityProxyVector Select(
                        Foundation::Query::SPtrCriteria const &sptrCriteria,
                        Foundation::SPtrColumnVector const &columnsForProjection) const override;

                // Factory methods
                static unique_ptr<MySqlSourceDriver> CreateUnique(Foundation::SPtrEntityMap const &sptrEntityMap) {
                    return cldeplus_make_unique<MySqlSourceDriver>(sptrEntityMap);
                }
                static shared_ptr<MySqlSourceDriver> CreateShared(Foundation::SPtrEntityMap const &sPtrEntityMap) {
                    return cldeplus_make_shared<MySqlSourceDriver>(sPtrEntityMap);
                }

            private:
                class MySqlApiImpl;
                shared_ptr<MySqlApiImpl> _mySqlApiImpl;

                Options _optionArgs;
                string _getStatement;
                string _insertStatement;
                string _updateStatement;
                string _deleteStatement;

            private:
                void Init();
            };

            using SPtrMySqlSourceDriver = shared_ptr<MySqlSourceDriver>;
        }
    }
}


#endif //CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOUCRCEDRIVER_H
