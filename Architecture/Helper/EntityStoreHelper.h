//
// Created by LE, Duc Anh on 6/2/15.
//

#ifndef CLOUD_E_CPLUS_ENTITYSTOREHELPER_H
#define CLOUD_E_CPLUS_ENTITYSTOREHELPER_H

#include <memory>
#include <Architecture/Entity.h>
#include <vector>

namespace Cloude {
    namespace Architecture {
        namespace Helper {

            void GenerateFieldsFromColumns(std::shared_ptr<Entity> &entity,
                                           const std::vector<std::shared_ptr<Column>> &columnsList);

        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITYSTOREHELPER_H
