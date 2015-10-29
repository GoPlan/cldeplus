//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LIKE_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LIKE_H

#include "../CriteriaLeaf.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class Like : public CriteriaLeaf {

                    static ComparativeType _type;

                public:
                    Like(const SPtrColumn &column, const Data::SPtrValue &value) : CriteriaLeaf(column, value) { };
                    Like(const Like &) = default;
                    Like(Like &&) = default;
                    Like &operator=(const Like &) = default;
                    Like &operator=(Like &&) = default;
                    ~Like() = default;

                    // Criteria
                    const ComparativeType &getComparativeType() const override { return _type; };
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LIKE_H
