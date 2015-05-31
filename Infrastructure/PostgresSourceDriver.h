//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_POSTGRESCONNECTOR_H
#define CLOUD_E_CPLUS_POSTGRESCONNECTOR_H

#include <Architecture/DataSource/Connector.h>

namespace Cloude {
    namespace Infrastructure {

        using Entity = Architecture::Entity;
        using Column = Architecture::Column;

        class PostgresSourceDriver : public Architecture::DataSource::Connector {
        public:
            PostgresSourceDriver() = default;
            virtual ~PostgresSourceDriver() = default;
            PostgresSourceDriver(const PostgresSourceDriver &srcPostgreSqlDriver) = default;
            PostgresSourceDriver &operator=(const PostgresSourceDriver &srcPostgreSqlDriver) = default;

            virtual int LoadEntity(std::shared_ptr<Entity> &entity,
                                   std::unordered_map<std::string, std::shared_ptr<Column>> &columnsMap);
            virtual int InsertEntity(std::shared_ptr<Entity> &entity,
                                     std::unordered_map<std::string, std::shared_ptr<Column>> &columnsMap);

        private:

        };
    }
}


#endif //CLOUD_E_CPLUS_POSTGRESCONNECTOR_H
