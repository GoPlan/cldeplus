//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_ISNOTNULL_H
#define CLOUD_E_CPLUS_ISNOTNULL_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class IsNotNull {
                public:
                    IsNotNull() = default;
                    virtual ~IsNotNull() = default;
                    IsNotNull(const IsNotNull &rhs) = default;
                    IsNotNull &operator=(const IsNotNull &rhs) = default;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_ISNOTNULL_H
