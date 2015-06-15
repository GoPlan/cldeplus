//
// Created by LE, Duc Anh on 6/2/15.
//

#include <memory>
#include "EntityStoreHelper.h"

void Cloude::Foundation::Store::EntityStoreHelper::GenerateFieldsFromColumns(const SPtrColumnVector &columnVector,
                                                                             const SPtrEntity &entity,
                                                                             bool checkIfFieldExists) {
    for (auto column : columnVector) {

        if (checkIfFieldExists && entity->HasField(column->getName())) {
            continue;
        }

        auto field = std::make_shared<Field>(const_cast<SPtrColumn &>(column));
        entity->setField(field);
    }
}

