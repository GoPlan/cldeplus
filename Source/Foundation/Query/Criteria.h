//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIA_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIA_H

#include <memory>
#include <iterator>
#include "../Column.h"
#include "../Data/Value.h"
#include "../Query/ComparativeType.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            class Criteria : public std::enable_shared_from_this<Criteria> {

            public:
                Criteria() = default;
                Criteria(const Criteria &) = default;
                Criteria(Criteria &&) = default;
                Criteria &operator=(const Criteria &srcExpression) = default;
                Criteria &operator=(Criteria &&srcExpression) = default;
                ~Criteria() = default;

                virtual const bool isComposite() const = 0;
                virtual const SPtrColumn &getColumn() const = 0;
                virtual const ComparativeType &getComparativeType() const = 0;
                virtual const Data::SPtrValue &getValue() const = 0;
            };

            using SPtrCriteria = std::shared_ptr<Criteria>;
            using WPtrCriteria = std::weak_ptr<Criteria>;
            using SPtrCriteriaVector = std::vector<SPtrCriteria>;
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIA_H
