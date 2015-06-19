//
// Created by LE, Duc Anh on 6/2/15.
//

#include <memory>
#include <stdexcept>
#include "EntityStoreHelper.h"

void Cloude::Foundation::Store::EntityStoreHelper::GenerateFieldsFromColumns(
        const Cloude::Foundation::SPtrColumnVector &columnVector,
        const Cloude::Foundation::Store::SPtrDataRecord &dataRecord,
        bool checkIfFieldExists) {

    if (!dataRecord) {
        std::string msg{"DataRecord can not be nullptr or undefined"};
        throw std::invalid_argument{msg};
    }

    for (auto column : columnVector) {

        if (checkIfFieldExists && dataRecord->HasField(column->getName())) {
            continue;
        }

        auto field = std::make_shared<Field>(const_cast<SPtrColumn &>(column));
        dataRecord->setField(field);
    }
}
