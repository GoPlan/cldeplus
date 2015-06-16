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

                public:
                    And(const SPtrCriteria &lhs, const SPtrCriteria &rhs)
                            : CriteriaComposite(lhs, rhs) { }
                    ~And() = default;
                    And(const And &rhs) = default;
                    And &operator=(const And &rhs) = default;

                    // Criteria
                    const ComparativeType &getComparativeType() const override { return _type; };

                private:
                    static ComparativeType _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_AND_H
