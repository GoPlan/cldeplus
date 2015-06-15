//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNOTNULL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNOTNULL_H

#include "../Predicate.h"
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class IsNotNull : public Predicate {

                public:
                    IsNotNull(const SPtrColumn &column) : _column(column) { };
                    virtual ~IsNotNull() = default;
                    IsNotNull(const IsNotNull &rhs) = default;
                    IsNotNull &operator=(const IsNotNull &rhs) = default;

                    // PredicateLeaf
                    const SPtrColumn &getColumn() const override;
                    const bool isComposite() const override;
                    const Enumeration::ComparativeType &getComparativeType() const override;
                    const Type::SPtrCldeValue & getValue() const override;

                private:
                    const SPtrColumn &_column;
                    static Enumeration::ComparativeType _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNOTNULL_H
