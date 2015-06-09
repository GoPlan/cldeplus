//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_NOTLIKE_H
#define CLOUD_E_CPLUS_NOTLIKE_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class NotLike {
                public:
                    NotLike() = default;
                    virtual ~NotLike() = default;
                    NotLike(const NotLike &rhs) = default;
                    NotLike &operator=(const NotLike &rhs) = default;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_NOTLIKE_H
