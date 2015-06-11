//
// Created by LE, Duc Anh on 6/9/15.
//

#include "Or.h"


namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                Enumeration::ComparativeType Or::_type = Enumeration::ComparativeType::Or;

                const Column &Or::getColumn() const {
                    const char *msg = "OR compartive does not support getColumn()";
                    throw Exception::cldeNonSupportedFunctionException(msg);
                }
            }
        }
    }
}


