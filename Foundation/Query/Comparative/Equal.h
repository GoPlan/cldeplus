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
                    Equal(const Column &column, const Type::cldeValue &value) : PredicateLeaf(column, value) { };
                    virtual ~Equal() = default;
                    Equal(const Equal &rhs) = default;
                    Equal &operator=(const Equal &rhs) = default;

                    // PredicateLeaf
                    const Enumeration::ComparativeType &getType() const override { return _type; };

                private:
                    static Enumeration::ComparativeType _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_EQUAL_H
