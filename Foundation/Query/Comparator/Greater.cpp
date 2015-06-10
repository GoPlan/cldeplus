//
// Created by LE, Duc Anh on 6/9/15.
//

#include "Greater.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {

                std::string Greater::_type = " > ";

                const std::string Greater::CopyToString() const {
                    return _type;
                }

                Enumeration::ComparatorType Greater::getType() {
                    return Enumeration::ComparatorType::Greater;
                }
            }
        }
    }
}


