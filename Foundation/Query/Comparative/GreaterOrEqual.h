//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARIVE_GREATEROREQUAL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARIVE_GREATEROREQUAL_H

#include "../PredicateLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {
                class GreaterOrEqual : public PredicateLeaf {
                public:
                    GreaterOrEqual(const Column &column, const Type::cldeValue &value)
                            : PredicateLeaf(column, value) { };
                    virtual ~GreaterOrEqual() = default;
                    GreaterOrEqual(const GreaterOrEqual &rhs) = default;
                    GreaterOrEqual &operator=(const GreaterOrEqual &rhs) = default;

                    // PredicateLeaf
                    const Enumeration::ComparativeType &getType() const override;

                private:
                    static Enumeration::ComparativeType _type;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARIVE_GREATEROREQUAL_H
