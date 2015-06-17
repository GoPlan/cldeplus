//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_EQUAL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_EQUAL_H

#include "../CriteriaLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class Equal : public Query::CriteriaLeaf {
                    static ComparativeType _type;

                public:
                    Equal(const SPtrColumn &column, const Type::SPtrCldeValue &value)
                            : CriteriaLeaf(column, value) { };
                    ~Equal() = default;
                    Equal(const Equal &rhs) = default;
                    Equal &operator=(const Equal &rhs) = default;

                    // CriteriaLeaf
                    const ComparativeType &getComparativeType() const override { return _type; };
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_EQUAL_H
