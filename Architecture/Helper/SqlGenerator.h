//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_SQLGENERATOR_H
#define CLOUD_E_CPLUS_SQLGENERATOR_H

#include <vector>
#include <iosfwd>
#include <Architecture/Entity.h>

#include "../Column.h"

namespace Cloude {
    namespace Architecture {
        namespace Helper {

            using Column = Cloude::Architecture::Column;
            using Entity = Cloude::Architecture::Entity;

            static std::string CreateGetPreparedQuery(const std::vector<Column> &columnsMap);
            static std::string CreateInsertPreparedQuery(const std::vector<Column> &columnsMap);
            static std::string CreateUpdatePreparedQuery(const std::vector<Column> &columnsMap);
            static std::string CreateDeletePreparedQuery(const std::vector<Column> &columnsMap);
            static std::string CreateSelectPreparedQuery(const std::vector<Column> &columnsMap);

            static std::string CreateGetQuery(const std::shared_ptr<Entity> &entity,const std::vector<Column> &columnsMap);
            static std::string CreateInsertQuery(const std::shared_ptr<Entity> &entity,const std::vector<Column> &columnsMap);
            static std::string CreateUpdateQuery(const std::shared_ptr<Entity> &entity,const std::vector<Column> &columnsMap);
            static std::string CreateDeleteQuery(const std::shared_ptr<Entity> &entity,const std::vector<Column> &columnsMap);
            static std::string CreateSelectQuery(const std::shared_ptr<Entity> &entity,const std::vector<Column> &columnsMap);
        }
    }
}


#endif //CLOUD_E_CPLUS_SQLGENERATOR_H
