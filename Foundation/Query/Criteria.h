//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIA_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIA_H

#include <memory>
#include <iterator>
#include <Foundation/Column.h>
#include <Foundation/Type/cldeValue.h>
#include <Foundation/Query/ComparativeType.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {

            class Criteria : public std::enable_shared_from_this<Criteria> {

            public:
                Criteria() = default;
                virtual ~Criteria() = default;
                Criteria(const Criteria &srcExpression) = default;
                Criteria &operator=(const Criteria &srcExpression) = default;

                virtual const bool isComposite() const = 0;
                virtual const SPtrColumn &getColumn() const = 0;
                virtual const ComparativeType &getComparativeType() const = 0;
                virtual const Type::SPtrCldeValue &getValue() const = 0;
            };

            using SPtrCriteria = std::shared_ptr<Criteria>;
            using WPtrCriteria = std::weak_ptr<Criteria>;
            using SPtrCriteriaVector = std::vector<SPtrCriteria>;
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIA_H
