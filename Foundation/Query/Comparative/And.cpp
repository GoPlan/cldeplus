//
// Created by LE, Duc Anh on 6/9/15.
//

#include "And.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                ComparativeType And::_type = ComparativeType::And;

                SPtrCriteria CreateCriteriaAnd(const SPtrCriteria &lhs, const SPtrCriteria &rhs) {
                    return std::make_shared<And>(lhs, rhs);
                }
            }
        }
    }
}
