//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LESSEROREQUAL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LESSEROREQUAL_H

#include "../PredicateLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {
                class LesserOrEqual : public PredicateLeaf {
                public:
                    LesserOrEqual(const Column &column, const Type::cldeValue &value)
                            : PredicateLeaf(column, value) { };
                    virtual ~LesserOrEqual() = default;
                    LesserOrEqual(const LesserOrEqual &rhs) = default;
                    LesserOrEqual &operator=(const LesserOrEqual &rhs) = default;

                    // Predicate
                    const Enumeration::ComparativeType &getType() const override;

                private:
                    static Enumeration::ComparativeType _type;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LESSEROREQUAL_H
