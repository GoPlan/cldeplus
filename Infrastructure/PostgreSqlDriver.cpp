//
// Created by LE, Duc Anh on 5/27/15.
//

#include "PostgreSqlDriver.h"


namespace Cloude {
    namespace Infrastructure {

        int PostgreSqlDriver::LoadEntity(std::shared_ptr<Entity> &entity,
                                         std::unordered_map<std::string, std::shared_ptr<Column>> &columnsMap) {
            return 0;
        }

        int PostgreSqlDriver::InsertEntity(std::shared_ptr<Entity> &entity,
                                           std::unordered_map<std::string, std::shared_ptr<Column>> &columnsMap) {
            return 0;
        }
    }
}

