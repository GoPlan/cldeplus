//
// Created by LE, Duc Anh on 6/9/15.
//

#include "LesserOrEqual.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                Enumeration::ComparativeType LesserOrEqual::_type = Enumeration::ComparativeType::LesserOrEqual;

                const Enumeration::ComparativeType &LesserOrEqual::getType() const {
                    return _type;
                }
            }
        }
    }
}


