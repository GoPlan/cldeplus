//
// Created by GoPlan on 18/05/2015.
//

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_MYSQL_MYSQLSOUCRCEDRIVER_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_MYSQL_MYSQLSOUCRCEDRIVER_H

#include <memory>
#include <vector>
#include <Foundation/EntitySourceDriver.h>
#include "MySqlSourceException.h"

namespace Cloude {
    namespace SourceDriver {
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
                ~MySqlSourceDriver();
                MySqlSourceDriver(const MySqlSourceDriver &entityMap) = default;
                MySqlSourceDriver &operator=(const MySqlSourceDriver &entityMap) = default;

                // Locals
                void Connect();
                void Disconnect();
                Options &getOptionArgs() { return _optionArgs; }

                // EntitySourceDriver
                int Load(std::shared_ptr<Foundation::Entity> &entity) const override;
                int Insert(std::shared_ptr<Foundation::Entity> &entity) const override;
                int Save(std::shared_ptr<Foundation::Entity> &entity) const override;
                int Delete(std::shared_ptr<Foundation::Entity> &entity) const override;
                upProxyVector Select(const upPredicate &expr) const override;

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
                void init();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_SOURCEDRIVER_MYSQL_MYSQLSOUCRCEDRIVER_H
