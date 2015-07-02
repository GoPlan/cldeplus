//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LESSEROREQUAL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LESSEROREQUAL_H

#include "../CriteriaLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class LesserOrEqual : public CriteriaLeaf {
                    static ComparativeType _type;

                public:
                    LesserOrEqual(const SPtrColumn &column, const Data::SPtrValue &value)
                            : CriteriaLeaf(column, value) { };

                    LesserOrEqual(const LesserOrEqual &) = default;
                    LesserOrEqual(LesserOrEqual &&) = default;
                    LesserOrEqual &operator=(const LesserOrEqual &) = default;
                    LesserOrEqual &operator=(LesserOrEqual &&) = default;
                    virtual ~LesserOrEqual() = default;

                    // Criteria
                    const ComparativeType &getComparativeType() const override { return _type; };
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LESSEROREQUAL_H
