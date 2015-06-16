//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_AND_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_AND_H

#include <Foundation/Query/PredicateComposite.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class And : public Query::PredicateComposite {

                public:
                    And(const SPtrPredicate &lhs, const SPtrPredicate &rhs)
                            : PredicateComposite(lhs, rhs) { }
                    ~And() = default;
                    And(const And &rhs) = default;
                    And &operator=(const And &rhs) = default;

                    // Predicate
                    const ComparativeType &getComparativeType() const override { return _type; };

                private:
                    static ComparativeType _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_AND_H
