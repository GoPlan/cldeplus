//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_AND_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_AND_H

#include "../CriteriaComposite.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class And : public Query::CriteriaComposite {

                    static ComparativeType _type;

                public:
                    And(const SPtrCriteria &lhs, const SPtrCriteria &rhs)
                            : CriteriaComposite(lhs, rhs) { }
                    And(const And &) = default;
                    And(And &&) = default;
                    And &operator=(const And &) = default;
                    And &operator=(And &&) = default;
                    ~And() = default;

                    // Criteria
                    const ComparativeType &getComparativeType() const override { return _type; };
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_AND_H
