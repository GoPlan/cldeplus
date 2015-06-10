//
// Created by LE, Duc Anh on 6/9/15.
//

#include "Or.h"


namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {

                std::string Or::_type = " Or ";

                const std::string Or::CopyToString() const {
                    return _type;
                }

                Enumeration::ComparatorType Or::getType() {
                    return Enumeration::ComparatorType::Or;
                }
            }
        }
    }
}


