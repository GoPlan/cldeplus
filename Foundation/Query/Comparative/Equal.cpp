//
// Created by LE, Duc Anh on 6/9/15.
//

#include "Equal.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                ComparativeType Equal::_type = ComparativeType::Equal;

                SPtrCriteria CreateCriteriaEqual(const SPtrColumn &column, const Data::SPtrValue &value) {
                    return std::make_shared<Equal>(column, value);
                }
            }
        }
    }
}


