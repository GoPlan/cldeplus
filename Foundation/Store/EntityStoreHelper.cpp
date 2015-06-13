//
// Created by LE, Duc Anh on 6/2/15.
//

#include <memory>
#include "EntityStoreHelper.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            void GenerateFieldsFromColumns(const SPtrColumnVector &columnVector,
                                           SPtrEntity &entity,
                                           bool checkIfFieldExists) {

                for (auto column : columnVector) {

                    if (checkIfFieldExists && entity->HasField(column->getName())) {
                        continue;
                    }

                    auto field = std::make_shared<Field>(const_cast<std::shared_ptr<Column> &>(column));
                    entity->setField(field);
                }
            }
        }
    }
}

