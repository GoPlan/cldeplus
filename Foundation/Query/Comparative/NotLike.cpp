//
// Created by LE, Duc Anh on 6/9/15.
//

#include "NotLike.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                Enumeration::ComparativeType NotLike::_type = Enumeration::ComparativeType::NotLike;

                const Enumeration::ComparativeType &NotLike::getType() const {
                    return _type;
                }
            }
        }
    }
}


