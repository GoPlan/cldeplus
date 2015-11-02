//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIA_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIA_H

#include "../../Port/Definitions.h"
#include "../Column.h"
#include "../Data/Value.h"
#include "../Query/ComparativeType.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {

            class Criteria : public std::enable_shared_from_this<Criteria> {

            public:
                Criteria() = default;
                Criteria(const Criteria &) = default;
                Criteria(Criteria &&) = default;
                Criteria &operator=(const Criteria &) = default;
                Criteria &operator=(Criteria &&) = default;
                ~Criteria() = default;

                virtual const bool isComposite() const = 0;
                virtual const SPtrColumn &getColumn() const = 0;
                virtual const ComparativeType &getComparativeType() const = 0;
                virtual const Data::SPtrValue &getValue() const = 0;
            };

            using SPtrCriteria = shared_ptr<Criteria>;
            using WPtrCriteria = std::weak_ptr<Criteria>;
            using SPtrCriteriaVector = vector<SPtrCriteria>;
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIA_H
