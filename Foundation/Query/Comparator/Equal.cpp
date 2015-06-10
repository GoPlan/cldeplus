//
// Created by LE, Duc Anh on 6/9/15.
//

#include "Equal.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {

                std::string Equal::_type = " = ";

                const std::string Equal::CopyToString() const {
                    return _type;
                }

                Enumeration::ComparatorType Equal::getType() {
                    return Enumeration::ComparatorType::Equal;
                }
            }
        }
    }
}


