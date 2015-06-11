//
// Created by LE, Duc Anh on 6/9/15.
//

#include "Like.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                Enumeration::ComparativeType Like::_type = Enumeration::ComparativeType::Like;

                const Enumeration::ComparativeType &Like::getType() const {
                    return _type;
                }
            }
        }
    }
}


