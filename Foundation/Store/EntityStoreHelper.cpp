//
// Created by LE, Duc Anh on 6/2/15.
//

#include <memory>
#include <stdexcept>
#include "EntityStoreHelper.h"

void Cloude::Foundation::Store::EntityStoreHelper::GenerateFieldsFromColumns(const SPtrColumnVector &columnVector,
                                                                             const SPtrEntity &entity,
                                                                             bool checkIfFieldExists) {

    if (!entity) {
        std::string msg{"Entity can not be nullptr or undefined"};
        throw std::invalid_argument{msg};
    }

    for (auto column : columnVector) {

        if (checkIfFieldExists && entity->HasField(column->getName())) {
            continue;
        }

        auto field = std::make_shared<Field>(const_cast<SPtrColumn &>(column));
        entity->setField(field);
    }
}

