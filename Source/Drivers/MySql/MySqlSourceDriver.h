//
// Created by GoPlan on 18/05/2015.
//

#ifndef CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOUCRCEDRIVER_H
#define CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOUCRCEDRIVER_H

#include "../../Port/Definitions.h"
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
                static unique_ptr<MySqlSourceDriver> Create(Foundation::SPtrEntityMap const &sptrEntityMap) {
                    return cldeplus_make_unique<MySqlSourceDriver>(sptrEntityMap);
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
