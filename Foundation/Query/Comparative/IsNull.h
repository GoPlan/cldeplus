//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_ISNULL_H
#define CLOUD_E_CPLUS_ISNULL_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {
                class IsNull {
                public:
                    IsNull() = default;
                    virtual ~IsNull() = default;
                    IsNull(const IsNull &rhs) = default;
                    IsNull &operator=(const IsNull &rhs) = default;

                };
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_ISNULL_H
