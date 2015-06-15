//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATELEAF_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATELEAF_H

#include "Predicate.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            class PredicateLeaf : public Predicate {

            public:
                PredicateLeaf(const SPtrColumn &column, const Type::SPtrCldeValue &value)
                        : _column(column), _value(value) { };
                virtual ~PredicateLeaf() = default;
                PredicateLeaf(const PredicateLeaf &rhs) = default;
                PredicateLeaf &operator=(const PredicateLeaf &rhs) = default;

                // Predicate
                virtual const bool isComposite() const override;
                virtual const SPtrColumn &getColumn() const override;
                virtual const Type::SPtrCldeValue &getValue() const override;

            private:
                const SPtrColumn &_column;
                const Type::SPtrCldeValue &_value;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATELEAF_H
