//
// Created by LE, Duc Anh on 6/13/15.
//

#include "CriteriaComposite.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            const ComparativeType &CriteriaComposite::getComparativeType() const {
                const char *msg = "Composite comparative does not support getComparativeType()";
                throw Exception::CLDENonSupportedFunctionException(msg);
            }

            const SPtrColumn &CriteriaComposite::getColumn() const {
                const char *msg = "Composite comparative does not support getColumn()";
                throw Exception::CLDENonSupportedFunctionException(msg);
            }

            const Data::SPtrValue &CriteriaComposite::getValue() const {
                const char *msg = "Composite comparative does not support getValue() method.";
                throw Exception::CLDENonSupportedFunctionException(msg);
            }
        }
    }
}