//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_SQLGENERATOR_H
#define CLOUD_E_CPLUS_SQLGENERATOR_H

#include "Framework/EntityMap.h"

namespace Cloude {
    namespace Framework {
        namespace Helper {

            using EntityMap = Cloude::Framework::EntityMap;
            using Column = Cloude::Framework::Column;

            std::string CreateGetPreparedQuery(const EntityMap &entityMap,
                                               std::function<std::string(const std::shared_ptr<Column> &column,
                                                                         int index)> F);

            std::string CreateInsertPreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::shared_ptr<Column> &column,
                                                                            int index)> F);

            std::string CreateUpdatePreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::shared_ptr<Column> &column,
                                                                            int index)> F);

            std::string CreateDeletePreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::shared_ptr<Column> &column,
                                                                            int index)> F);

        }
    }
}


#endif //CLOUD_E_CPLUS_SQLGENERATOR_H
