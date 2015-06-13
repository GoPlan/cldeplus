//
// Created by LE, Duc Anh on 6/13/15.
//

#include "PredicateComposite.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            const Enumeration::ComparativeType &PredicateComposite::getComparativeType() const {
                const char *msg = "Composite compartive does not support getComparativeType()";
                throw Exception::cldeNonSupportedFunctionException(msg);
            }

            const Column &PredicateComposite::getColumn() const {
                const char *msg = "Composite compartive does not support getColumn()";
                throw Exception::cldeNonSupportedFunctionException(msg);
            }

            const Type::SPtrCldeValue &PredicateComposite::getValue() const {
                const char *msg = "Composite comparator does not support getValue() method.";
                throw Exception::cldeNonSupportedFunctionException(msg);
            }
        }
    }
}