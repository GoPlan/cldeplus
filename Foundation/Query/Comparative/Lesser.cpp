//
// Created by LE, Duc Anh on 6/9/15.
//

#include "Lesser.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                Enumeration::ComparativeType Lesser::_type = Enumeration::ComparativeType::Lesser;

                const Enumeration::ComparativeType &Lesser::getType() const {
                    return _type;
                }
            }
        }
    }
}