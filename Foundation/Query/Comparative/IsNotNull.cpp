//
// Created by LE, Duc Anh on 6/9/15.
//

#include "IsNotNull.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                Enumeration::ComparativeType IsNotNull::_type = Enumeration::ComparativeType::IsNotNull;

                const Enumeration::ComparativeType &IsNotNull::getType() const {
                    return _type;
                }
            }
        }
    }
}


