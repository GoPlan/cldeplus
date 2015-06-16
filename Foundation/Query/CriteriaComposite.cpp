//
// Created by LE, Duc Anh on 6/13/15.
//

#include "CriteriaComposite.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            const ComparativeType &CriteriaComposite::getComparativeType() const {
                const char *msg = "Composite comparative does not support getComparativeType()";
                throw Exception::cldeNonSupportedFunctionException(msg);
            }

            const SPtrColumn &CriteriaComposite::getColumn() const {
                const char *msg = "Composite comparative does not support getColumn()";
                throw Exception::cldeNonSupportedFunctionException(msg);
            }

            const Type::SPtrCldeValue &CriteriaComposite::getValue() const {
                const char *msg = "Composite comparative does not support getValue() method.";
                throw Exception::cldeNonSupportedFunctionException(msg);
            }
        }
    }
}