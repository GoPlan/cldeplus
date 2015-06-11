//
// Created by LE, Duc Anh on 6/11/15.
//

#include "PredicateLeaf.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            const Column &PredicateLeaf::getColumn() const {
                return _column;
            }
            const Type::cldeValue &PredicateLeaf::getValue() const {
                return _value;
            }
        }
    }
}


