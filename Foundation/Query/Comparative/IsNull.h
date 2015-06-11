//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_ISNULL_H
#define CLOUD_E_CPLUS_ISNULL_H

#include "../PredicateLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {
                class IsNull : public PredicateLeaf {
                public:
                    IsNull(const Column &column, const Type::cldeValue &value) : PredicateLeaf(column, value) { };
                    virtual ~IsNull() = default;
                    IsNull(const IsNull &rhs) = default;
                    IsNull &operator=(const IsNull &rhs) = default;

                    // PredicateLeaf


                    virtual const Enumeration::ComparativeType &getType() const override;
                private:
                    static Enumeration::ComparativeType _type;

                };
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_ISNULL_H
