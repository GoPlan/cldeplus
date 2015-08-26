//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNOTNULL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNOTNULL_H

#include "../Criteria.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class IsNotNull : public Criteria {

                    SPtrColumn _column;
                    static ComparativeType _type;

                public:
                    IsNotNull(const SPtrColumn &column) : _column(column) { };
                    IsNotNull(const IsNotNull &) = default;
                    IsNotNull(IsNotNull &&) = default;
                    IsNotNull &operator=(const IsNotNull &) = default;
                    IsNotNull &operator=(IsNotNull &&) = default;
                    ~IsNotNull() = default;

                    // CriteriaLeaf
                    const SPtrColumn &getColumn() const override;
                    const bool isComposite() const override;
                    const ComparativeType &getComparativeType() const override;
                    const Data::SPtrValue &getValue() const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNOTNULL_H
