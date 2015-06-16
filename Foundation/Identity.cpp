//
// Created by GoPlan on 14/05/2015.
//

#include "Identity.h"

namespace Cloude {
    namespace Foundation {

        Identity::Identity(const std::vector<SPtrField> &fieldVector) {
            Store::IDataRecord::setMultiFields(fieldVector);
        }

        Identity::Identity(const std::vector<Field *> &fieldVector) {
            Store::IDataRecord::setMultiFields(fieldVector);
        }
    }
}
