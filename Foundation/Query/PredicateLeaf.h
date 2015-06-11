//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_CPLUS_PREDICATELEAF_H
#define CLOUD_E_CPLUS_PREDICATELEAF_H

#include "Predicate.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            class PredicateLeaf : public Predicate {
            public:
                PredicateLeaf(const Column &column, const Type::cldeValue &value) : _column(column), _value(value) { };
                virtual ~PredicateLeaf() = default;
                PredicateLeaf(const PredicateLeaf &rhs) = default;
                PredicateLeaf &operator=(const PredicateLeaf &rhs) = default;

                virtual const Column &getColumn() const override;
                virtual const Type::cldeValue &getValue() const override;


            private:
                const Column &_column;
                const Type::cldeValue &_value;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_PREDICATELEAF_H
