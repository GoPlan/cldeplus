//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_EQUAL_H
#define CLOUD_E_CPLUS_EQUAL_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class Equal {
                public:
                    Equal() = default;
                    virtual ~Equal() = default;
                    Equal(const Equal &rhs) = default;
                    Equal &operator=(const Equal &rhs) = default;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_EQUAL_H
