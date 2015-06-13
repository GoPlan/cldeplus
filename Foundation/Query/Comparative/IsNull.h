//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNULL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNULL_H

#include "../PredicateLeaf.h"
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class IsNull : public Predicate {

                public:
                    IsNull(const Column &column) : _column(column) { };
                    virtual ~IsNull() = default;
                    IsNull(const IsNull &rhs) = default;
                    IsNull &operator=(const IsNull &rhs) = default;

                    // PredicateLeaf
                    const Column &getColumn() const override;
                    const bool isComposite() const override;
                    const Enumeration::ComparativeType &getComparativeType() const override;
                    const Type::SPtrCldeValue & getValue() const override;

                private:
                    const Column &_column;
                    static Enumeration::ComparativeType _type;
                };
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNULL_H
