//
// Created by LE, Duc Anh on 6/9/15.
//

#include "And.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                Enumeration::ComparativeType And::_type = Enumeration::ComparativeType::And;
                
                const Column &And::getColumn() const {
                    const char *msg = "AND compartive does not support getColumn()";
                    throw Exception::cldeNonSupportedFunctionException(msg);
                }
            }
        }
    }
}
