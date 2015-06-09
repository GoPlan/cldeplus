//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_AND_H
#define CLOUD_E_CPLUS_AND_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator{
                class And {
                public:
                    And() = default;
                    virtual ~And() = default;
                    And(const And &rhs) = default;
                    And &operator=(const And &rhs) = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_AND_H
