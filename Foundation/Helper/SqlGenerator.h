//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_HELPER_SQLGENERATOR_H
#define CLOUD_E_CPLUS_FOUNDATION_HELPER_SQLGENERATOR_H

#include "Foundation/EntityMap.h"

namespace Cloude {
    namespace Foundation {
        namespace Helper {

            using EntityMap = Cloude::Foundation::EntityMap;
            using Column = Cloude::Foundation::Column;

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


#endif //CLOUD_E_CPLUS_FOUNDATION_HELPER_SQLGENERATOR_H
