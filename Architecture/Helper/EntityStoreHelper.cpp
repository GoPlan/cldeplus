//
// Created by LE, Duc Anh on 6/2/15.
//

#include <memory>
#include "EntityStoreHelper.h"

namespace Cloude {
    namespace Architecture {
        namespace Helper {
            void GenerateFieldsFromColumns(std::shared_ptr<Entity> &entity,
                                           const std::vector<std::shared_ptr<Column>> &columnsList) {

                for (auto column : columnsList) {
                    auto field = std::make_shared<Field>(const_cast<std::shared_ptr<Column> &>(column));
                    entity->SetField(field);
                }
            }
        }
    }
}

