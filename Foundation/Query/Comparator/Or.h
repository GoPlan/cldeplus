//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_OR_H
#define CLOUD_E_CPLUS_OR_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class Or {
                public:
                    Or() = default;
                    virtual ~Or() = default;
                    Or(const Or &rhs) = default;
                    Or &operator=(const Or &rhs) = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_OR_H
