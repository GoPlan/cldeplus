//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_OR_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_OR_H

#include "../../Exception/CLDENonSupportedFunctionException.h"
#include "../CriteriaComposite.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class Or : public Query::CriteriaComposite {
                    static ComparativeType _type;

                public:
                    Or(const SPtrCriteria &lhs, const SPtrCriteria &rhs)
                            : CriteriaComposite(lhs, rhs) { }
                    Or(const Or &rhs) = default;
                    Or(Or &&) = default;
                    Or &operator=(const Or &) = default;
                    Or &operator=(Or &&) = default;
                    ~Or() = default;

                    // Locals
                    const ComparativeType &getComparativeType() const override { return _type; };
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_OR_H
