//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LESSER_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LESSER_H

#include "../CriteriaLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class Lesser : public CriteriaLeaf {
                    static ComparativeType _type;

                public:
                    Lesser(const SPtrColumn &column, const Type::SPtrCldeValue &value)
                            : CriteriaLeaf(column, value) { };
                    virtual ~Lesser() = default;
                    Lesser(const Lesser &rhs) = default;
                    Lesser &operator=(const Lesser &rhs) = default;

                    // CriteriaLeaf
                    const ComparativeType &getComparativeType() const override { return _type; };
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_LESSER_H
