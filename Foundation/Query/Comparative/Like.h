//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LIKE_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LIKE_H

#include "../CriteriaLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class Like : public CriteriaLeaf {
                    static ComparativeType _type;

                public:
                    Like(const SPtrColumn &column, const Type::SPtrCldeValue &value)
                            : CriteriaLeaf(column, value) { };
                    ~Like() = default;
                    Like(const Like &rhs) = default;
                    Like &operator=(const Like &rhs) = default;

                    // Criteria
                    const ComparativeType &getComparativeType() const override { return _type; };
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LIKE_H
