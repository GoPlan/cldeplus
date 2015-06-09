//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_LIKE_H
#define CLOUD_E_CPLUS_LIKE_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class Like {
                public:
                    Like() = default;
                    virtual ~Like() = default;
                    Like(const Like &rhs) = default;
                    Like &operator=(const Like &rhs) = default;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_LIKE_H
