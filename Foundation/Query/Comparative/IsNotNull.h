//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_ISNOTNULL_H
#define CLOUD_E_CPLUS_ISNOTNULL_H

#include "../PredicateLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {
                class IsNotNull : public PredicateLeaf {
                public:
                    IsNotNull(const Column &column, const Type::cldeValue &value) : PredicateLeaf(column, value) { };
                    virtual ~IsNotNull() = default;
                    IsNotNull(const IsNotNull &rhs) = default;
                    IsNotNull &operator=(const IsNotNull &rhs) = default;

                    // PredicateLeaf
                    const Enumeration::ComparativeType &getType() const override;

                private:
                    static Enumeration::ComparativeType _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_ISNOTNULL_H
