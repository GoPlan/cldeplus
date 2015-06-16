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

                public:
                    GreaterOrEqual(const SPtrColumn &column, const Type::SPtrCldeValue &value)
                            : CriteriaLeaf(column, value) { };
                    virtual ~GreaterOrEqual() = default;
                    GreaterOrEqual(const GreaterOrEqual &rhs) = default;
                    GreaterOrEqual &operator=(const GreaterOrEqual &rhs) = default;

                    // CriteriaLeaf
                    const ComparativeType &getComparativeType() const override { return _type; };

                private:
                    static ComparativeType _type;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARIVE_GREATEROREQUAL_H
