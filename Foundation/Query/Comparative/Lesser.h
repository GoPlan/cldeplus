//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LESSER_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LESSER_H

#include "../PredicateLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {
                class Lesser : public PredicateLeaf {
                public:
                    Lesser(const Column &column, const Type::cldeValue &value) : PredicateLeaf(column, value) { };
                    virtual ~Lesser() = default;
                    Lesser(const Lesser &rhs) = default;
                    Lesser &operator=(const Lesser &rhs) = default;

                    // PredicateLeaf
                    const Enumeration::ComparativeType &getType() const override;

                private:
                    static Enumeration::ComparativeType _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LESSER_H
