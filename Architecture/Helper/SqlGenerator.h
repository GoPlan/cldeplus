//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_SQLGENERATOR_H
#define CLOUD_E_CPLUS_SQLGENERATOR_H

#include "vector"
#include "iosfwd"

#include "Architecture/EntityMap.h"

namespace Cloude {
    namespace Architecture {
        namespace Helper {

            using EntityMap = Cloude::Architecture::EntityMap;
            using Column = Cloude::Architecture::Column;

            std::string CreateGetPreparedQuery(const EntityMap &entityMap,
                                               std::function<std::string(const std::shared_ptr<Column> &column,
                                                                         const int index)> F);

            std::string CreateInsertPreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::shared_ptr<Column> &column,
                                                                            const int index)> F);

            std::string CreateUpdatePreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::shared_ptr<Column> &column,
                                                                            const int index)> F);

            std::string CreateDeletePreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::shared_ptr<Column> &column,
                                                                            const int index)> F);

        }
    }
}


#endif //CLOUD_E_CPLUS_SQLGENERATOR_H
