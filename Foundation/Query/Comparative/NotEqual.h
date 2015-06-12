//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_NOTEQUAL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_NOTEQUAL_H

#include "../PredicateLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {
                class NotEqual : public PredicateLeaf {
                public:
                    NotEqual(const Column &column, const Type::cldeValue &value) : PredicateLeaf(column, value) { };
                    virtual ~NotEqual() = default;
                    NotEqual(const NotEqual &rhs) = default;
                    NotEqual &operator=(const NotEqual &rhs) = default;

                    // PredicateLeaf
                    const Enumeration::ComparativeType &getType() const override { return _type; };

                private:
                    static Enumeration::ComparativeType _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_NOTEQUAL_H
