//
// Created by LE, Duc Anh on 6/9/15.
//

#include "And.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {

                std::string And::_type = "And";

                const std::string And::ToString() const {
                    return _type;
                }

                Enumeration::ComparatorType And::getType() {
                    return Enumeration::ComparatorType::And;
                }
            }
        }
    }
}
