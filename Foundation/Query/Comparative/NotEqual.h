//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_NOTEQUAL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_NOTEQUAL_H

#include "../CriteriaLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class NotEqual : public CriteriaLeaf {

                    static ComparativeType _type;

                public:
                    NotEqual(const SPtrColumn &column, const Data::SPtrValue &value) : CriteriaLeaf(column, value) { };
                    NotEqual(const NotEqual &) = default;
                    NotEqual(NotEqual &&) = default;
                    NotEqual &operator=(const NotEqual &) = default;
                    NotEqual &operator=(NotEqual &&) = default;
                    virtual ~NotEqual() = default;

                    // CriteriaLeaf
                    const ComparativeType &getComparativeType() const override { return _type; };
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_NOTEQUAL_H
