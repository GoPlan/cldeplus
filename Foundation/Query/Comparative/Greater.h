//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_GREATER_H
#define CLOUD_E_CPLUS_GREATER_H


#include "../PredicateLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {
                class Greater : public Query::PredicateLeaf {
                public:
                    Greater(const Column &column, const Type::cldeValue &value) : PredicateLeaf(column, value) { };
                    ~Greater() = default;
                    Greater(const Greater &rhs) = default;
                    Greater &operator=(const Greater &rhs) = default;

                    // Predicate
                    const Enumeration::ComparativeType &getType() const override { return _type; }

                private:
                    static Enumeration::ComparativeType _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_GREATER_H
