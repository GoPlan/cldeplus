//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_GREATER_H
#define CLOUD_E_CPLUS_GREATER_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class Greater {
                public:
                    Greater() = default;
                    virtual ~Greater() = default;
                    Greater(const Greater &rhs) = default;
                    Greater &operator=(const Greater &rhs) = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_GREATER_H
