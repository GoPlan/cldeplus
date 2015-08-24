//
// Created by GoPlan on 18/05/2015.
//

#ifndef CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOUCRCEDRIVER_H
#define CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOUCRCEDRIVER_H

#include <memory>
#include <vector>
#include "../../Foundation/EntitySourceDriver.h"
#include "MySqlSourceException.h"

namespace Cloude {
    namespace Drivers {
        namespace MySql {

            enum class MySqlSourceExecutionStatus {

            };

            class MySqlSourceDriver : public Foundation::EntitySourceDriver {

            public:
                using Options = struct {
                    std::string Host;
                    std::string User;
                    std::string Pass;
                    std::string Base;
                    unsigned int Port = 3306;
                };

            public:
                explicit MySqlSourceDriver(const Foundation::EntityMap &entityMap);
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

            private:
                class MySqlApiImpl;

                Options _optionArgs;
                std::shared_ptr<MySqlApiImpl> _mySqlApiImpl;
                std::string _getStatement;
                std::string _insertStatement;
                std::string _updateStatement;
                std::string _deleteStatement;
                bool isConnected = false;

            private:
                void Init();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_DRIVERS_MYSQL_MYSQLSOUCRCEDRIVER_H
