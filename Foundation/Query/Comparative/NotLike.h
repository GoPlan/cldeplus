//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_NOTLIKE_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_NOTLIKE_H

#include "../PredicateLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class NotLike : public PredicateLeaf {

                public:
                    NotLike(const Column &column, const Type::SPtrCldeValue &value) : PredicateLeaf(column, value) { };
                    ~NotLike() = default;
                    NotLike(const NotLike &rhs) = default;
                    NotLike &operator=(const NotLike &rhs) = default;

                    // Predicate
                    const Enumeration::ComparativeType &getComparativeType() const override { return _type; };

                private:
                    static Enumeration::ComparativeType _type;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_NOTLIKE_H
