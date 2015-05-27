//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_POSTGRESQLDRIVER_H
#define CLOUD_E_CPLUS_POSTGRESQLDRIVER_H

#include "Architecture/Entity.h"
#include "Architecture/Column.h"
#include "Architecture/EntitySourceDriver.h"

namespace Cloude {
    namespace Infrastructure {

        using Entity = Architecture::Entity;
        using Column = Architecture::Column;

        class PostgreSqlDriver : public Architecture::EntitySourceDriver {
        public:
            PostgreSqlDriver() = default;
            virtual ~PostgreSqlDriver() = default;
            PostgreSqlDriver(const PostgreSqlDriver &srcPostgreSqlDriver) = default;
            PostgreSqlDriver &operator=(const PostgreSqlDriver &srcPostgreSqlDriver) = default;

            virtual int LoadEntity(std::shared_ptr<Entity> &entity,
                                   std::unordered_map<std::string, std::shared_ptr<Column>> &columnsMap);
            virtual int InsertEntity(std::shared_ptr<Entity> &entity,
                                     std::unordered_map<std::string, std::shared_ptr<Column>> &columnsMap);

        private:

        };
    }
}


#endif //CLOUD_E_CPLUS_POSTGRESQLDRIVER_H
