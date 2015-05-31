//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_POSTGRESSOURCEDRIVER_H
#define CLOUD_E_CPLUS_POSTGRESSOURCEDRIVER_H

#include <Architecture/EntitySourceDriver.h>

namespace Cloude {
    namespace Infrastructure {

        using Entity = Architecture::Entity;
        using Column = Architecture::Column;

        class PostgresSourceDriver : public Architecture::EntitySourceDriver {
        public:
            PostgresSourceDriver() = default;
            virtual ~PostgresSourceDriver() = default;
            PostgresSourceDriver(const PostgresSourceDriver &srcPostgreSqlDriver) = default;
            PostgresSourceDriver &operator=(const PostgresSourceDriver &srcPostgreSqlDriver) = default;

        private:

        };
    }
}


#endif //CLOUD_E_CPLUS_POSTGRESSOURCEDRIVER_H
