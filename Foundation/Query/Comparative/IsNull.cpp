//
// Created by LE, Duc Anh on 6/9/15.
//

#include "IsNull.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                Enumeration::ComparativeType IsNull::_type = Enumeration::ComparativeType::IsNull;

                const Enumeration::ComparativeType &IsNull::getType() const {
                    return _type;
                }
            }
        }
    }
}


