//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_GREATEROREQUAL_H
#define CLOUD_E_CPLUS_GREATEROREQUAL_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class GreaterOrEqual {
                public:
                    GreaterOrEqual() = default;
                    virtual ~GreaterOrEqual() = default;
                    GreaterOrEqual(const GreaterOrEqual &rhs) = default;
                    GreaterOrEqual &operator=(const GreaterOrEqual &rhs) = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_GREATEROREQUAL_H
