//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_GREATER_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_GREATER_H

#include "../CriteriaLeaf.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class Greater : public Query::CriteriaLeaf {

                    static ComparativeType _type;

                public:
                    Greater(const SPtrColumn &column, const Data::SPtrValue &value) : CriteriaLeaf(column, value) { };
                    Greater(const Greater &) = default;
                    Greater(Greater &&) = default;
                    Greater &operator=(const Greater &) = default;
                    Greater &operator=(Greater &&) = default;
                    ~Greater() = default;

                    // Criteria
                    const ComparativeType &getComparativeType() const override { return _type; }
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_GREATER_H
