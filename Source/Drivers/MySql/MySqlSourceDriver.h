//
// Created by GoPlan on 18/05/2015.
//

#ifndef CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOUCRCEDRIVER_H
#define CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOUCRCEDRIVER_H

#include "cldeplus_default"
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
                explicit MySqlSourceDriver(const Foundation::SPtrEntityMap &entityMap);
                MySqlSourceDriver(const MySqlSourceDriver &) = default;
                MySqlSourceDriver(MySqlSourceDriver &&) = default;
                MySqlSourceDriver &operator=(const MySqlSourceDriver &) = default;
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
                        const Foundation::Query::SPtrCriteria &sptrCriteria,
                        const Foundation::SPtrColumnVector &columnsForProjection) const override;

                // Factory methods
                static unique_ptr<MySqlSourceDriver> Create(Foundation::SPtrEntityMap const &sptrEntityMap) {
                    return unique_ptr<MySqlSourceDriver>(new MySqlSourceDriver(sptrEntityMap));
                }

            private:
                class MySqlApiImpl;

                Options _optionArgs;
                shared_ptr<MySqlApiImpl> _mySqlApiImpl;
                string _getStatement;
                string _insertStatement;
                string _updateStatement;
                string _deleteStatement;
                bool isConnected = false;

            private:
                void Init();
            };

            using SPtrMySqlSourceDriver = shared_ptr<MySqlSourceDriver>;
        }
    }
}


#endif //CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOUCRCEDRIVER_H
