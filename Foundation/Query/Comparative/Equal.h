//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_EQUAL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_EQUAL_H

#include "../PredicateLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class Equal : public Query::PredicateLeaf {

                public:
                    Equal(const SPtrColumn &column, const Type::SPtrCldeValue &value)
                            : PredicateLeaf(column, value) { };
                    ~Equal() = default;
                    Equal(const Equal &rhs) = default;
                    Equal &operator=(const Equal &rhs) = default;

                    // PredicateLeaf
                    const ComparativeType &getComparativeType() const override { return _type; };

                private:
                    static ComparativeType _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_EQUAL_H
