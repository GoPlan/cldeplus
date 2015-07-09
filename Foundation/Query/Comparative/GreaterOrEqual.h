//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARIVE_GREATEROREQUAL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARIVE_GREATEROREQUAL_H

#include "../CriteriaLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class GreaterOrEqual : public CriteriaLeaf {

                    static ComparativeType _type;

                public:
                    GreaterOrEqual(const SPtrColumn &column, const Data::SPtrValue &value)
                            : CriteriaLeaf(column, value) { };
                    GreaterOrEqual(const GreaterOrEqual &) = default;
                    GreaterOrEqual(GreaterOrEqual &&) = default;
                    GreaterOrEqual &operator=(const GreaterOrEqual &) = default;
                    GreaterOrEqual &operator=(GreaterOrEqual &&) = default;
                    ~GreaterOrEqual() = default;

                    // CriteriaLeaf
                    const ComparativeType &getComparativeType() const override { return _type; };
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARIVE_GREATEROREQUAL_H
