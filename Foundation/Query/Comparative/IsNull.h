//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNULL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNULL_H

#include "../CriteriaLeaf.h"
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class IsNull : public Criteria {

                    const SPtrColumn &_column;
                    static ComparativeType _type;

                public:
                    IsNull(const SPtrColumn &column) : _column(column) { };
                    IsNull(const IsNull &) = default;
                    IsNull(IsNull &&) = default;
                    IsNull &operator=(const IsNull &) = default;
                    IsNull &operator=(IsNull &&) = default;
                    ~IsNull() = default;

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

#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNULL_H
