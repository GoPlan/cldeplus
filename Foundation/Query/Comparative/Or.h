//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_OR_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_OR_H

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include <Foundation/Query/PredicateComposite.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class Or : public Query::PredicateComposite {

                public:
                    Or(const SPtrPredicate &lhs, const SPtrPredicate &rhs) : PredicateComposite(lhs, rhs) { }
                    ~Or() = default;
                    Or(const Or &rhs) = default;
                    Or &operator=(const Or &rhs) = default;

                    // Locals
                    const Enumeration::ComparativeType &getComparativeType() const override { return _type; };

                private:
                    static Enumeration::ComparativeType _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_OR_H
