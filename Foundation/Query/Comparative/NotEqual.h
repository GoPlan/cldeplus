//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_NOTEQUAL_H
#define CLOUD_E_CPLUS_NOTEQUAL_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {
                class NotEqual {
                public:
                    NotEqual() = default;
                    virtual ~NotEqual() = default;
                    NotEqual(const NotEqual &rhs) = default;
                    NotEqual &operator=(const NotEqual &rhs) = default;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_NOTEQUAL_H
